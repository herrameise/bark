#include "EditorPanel.h"
using namespace bark::app;

#include <wx/combobox.h>
#include <wx/dcclient.h>
#include <wx/menu.h>
#include <wx/scrolbar.h>

#include "../ColorTemplate.h"
#include "../Logger.h"
#include "../Manager.h"
#include "../Specimen.h"
#include "EditorSettingsDialog.h"
#include "EditorTextCtrl.h"
#include "FillValueDialog.h"
#include "MaskValueDialog.h"



EditorPanel::EditorPanel(
    wxWindow*   parent,
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen) :
    EditorPanelForm(parent),
    m_logger(logger),
    m_manager(manager),
    m_specimen(specimen)
{
    m_settings.font.SetFaceName(m_settings.facenames[0]);
    m_settings.font.SetPointSize(10);
    m_settings.capital_hex = true;

    m_active = false;
    m_display_mode = EDITOR_DISPLAY_MODE_BYTES;
    m_first_byte = 0;
    m_selecting = false;
    m_mouse_byte_exists = false;
    m_show_color_template = false;
    m_color_template = nullptr;

    BuildContextMenus();
    BindEvents();
    
    SyncWithSpecimen();
    ApplySettings();
    AdjustSizes();
    GenerateHeaders();
    GenerateText();
    FormatText();
    Layout();
}


EditorPanel::~EditorPanel()
{
    if (m_copy_buffer_size > 0) delete[] m_copy_buffer;
}


void EditorPanel::BuildContextMenus()
{
    m_raw_menu = new wxMenu();
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_COPY, "Copy"));
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_PASTE_OVERWRITE, "Paste (overwrite)"));
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_PASTE_INSERT, "Paste (insert)"));
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_DELETE, "Delete"));
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_FILL, "Fill"));
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_FILL_ZERO, "Fill (zero)"));
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_XOR_MASK, "XOR Mask"));
    m_raw_menu->Append(new wxMenuItem(m_raw_menu, EDITOR_MENU_ID_REVERSE, "Reverse"));
    m_RawData->SetContextMenu(m_raw_menu);

    m_ascii_menu = new wxMenu();
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_COPY, "Copy"));
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_PASTE_OVERWRITE, "Paste (overwrite)"));
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_PASTE_INSERT, "Paste (insert)"));
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_DELETE, "Delete"));
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_FILL, "Fill"));
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_FILL_ZERO, "Fill (zero)"));
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_XOR_MASK, "XOR Mask"));
    m_ascii_menu->Append(new wxMenuItem(m_ascii_menu, EDITOR_MENU_ID_REVERSE, "Reverse"));
    m_AsciiData->SetContextMenu(m_ascii_menu);

    m_copy_buffer = nullptr;
    m_copy_buffer_size = 0;
    m_raw_menu->Enable(EDITOR_MENU_ID_PASTE_OVERWRITE, false);
    m_ascii_menu->Enable(EDITOR_MENU_ID_PASTE_OVERWRITE, false);
    m_raw_menu->Enable(EDITOR_MENU_ID_PASTE_INSERT, false);
    m_ascii_menu->Enable(EDITOR_MENU_ID_PASTE_INSERT, false);
}


void EditorPanel::BindEvents()
{
    Bind(wxEVT_SIZE, &EditorPanel::OnResize, this);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorPanel::OnContextMenuEvent, this);

    m_SettingsButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &EditorPanel::OnButtonSettings, this);
    m_DisplayModeComboBox->Bind(wxEVT_COMMAND_COMBOBOX_SELECTED, &EditorPanel::OnComboBoxDisplayMode, this);
    m_ColorTemplateCheckBox->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED, &EditorPanel::OnCheckBoxColorTemplate, this);

    m_Offsets->Bind(wxEVT_LEFT_DOWN, &EditorPanel::OnLeftMouseButtonDown, this);

    m_RawData->Bind(wxEVT_LEAVE_WINDOW, &EditorPanel::OnLeaveWindow, this);
    m_RawData->Bind(wxEVT_LEFT_DOWN, &EditorPanel::OnLeftMouseButtonDown, this);
    m_RawData->Bind(wxEVT_LEFT_UP, &EditorPanel::OnLeftMouseButtonUp, this);
    m_RawData->Bind(wxEVT_KEY_UP, &EditorPanel::OnKeyUp, this);

    m_AsciiData->Bind(wxEVT_LEAVE_WINDOW, &EditorPanel::OnLeaveWindow, this);
    m_AsciiData->Bind(wxEVT_LEFT_DOWN, &EditorPanel::OnLeftMouseButtonDown, this);
    m_AsciiData->Bind(wxEVT_LEFT_UP, &EditorPanel::OnLeftMouseButtonUp, this);

    m_Scrollbar->Bind(wxEVT_SCROLL_CHANGED, &EditorPanel::OnScroll, this);
}


void EditorPanel::OnButtonSettings(
    wxCommandEvent& event)
{
    EditorSettingsDialog* dlg = new EditorSettingsDialog(this, this);
    dlg->ShowModal();

    ApplySettings();
    AdjustSizes();
    GenerateHeaders();
    GenerateText();
    LocalizeSelectionRange();
    FormatText();
    Layout();
}


void EditorPanel::OnComboBoxDisplayMode(
    wxCommandEvent& event)
{
    m_display_mode = static_cast<EDITOR_DISPLAY_MODE>(m_DisplayModeComboBox->GetSelection());

    AdjustSizes();
    GenerateHeaders();
    GenerateText();
    FormatText();
    Layout();
}


void EditorPanel::OnCheckBoxColorTemplate(
    wxCommandEvent& event)
{
    m_show_color_template = m_ColorTemplateCheckBox->IsChecked();

    LocalizeColorTemplate();
    FormatText();
}


void EditorPanel::OnResize(
    wxSizeEvent& event)
{
    AdjustSizes();
    GenerateHeaders();
    GenerateText();
    LocalizeSelectionRange();
    LocalizeColorTemplate();
    FormatText();

    if (m_active == false)
    {
        event.Skip(false);
        event.StopPropagation();
        return;
    }

    event.Skip(true);
}


void EditorPanel::OnScroll(
    wxScrollEvent& event)
{
    Scroll(m_Scrollbar->GetThumbPosition());
}


void EditorPanel::OnLeaveWindow(
    wxMouseEvent& event)
{
    m_selecting = false;
}


void EditorPanel::OnLeftMouseButtonDown(
    wxMouseEvent& event)
{
    // prevent user from being able to click inside m_Offsets
    if (event.GetEventObject() == m_Offsets) return;

    if (m_mouse_byte_exists) m_selecting = true;

    m_selection_start_byte = m_mouse_byte;
    m_selection_stop_byte = m_mouse_byte;

    if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
    {
        m_selection_start_bit = 0;
        m_selection_stop_bit = 7;
        m_RawData->SetCaretPosition((m_mouse_byte_local * 3) - 1);
    }
    else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
    {
        if (m_text_ctrl == EDITOR_TEXT_CTRL_RAW)
        {
            m_selection_start_bit = m_mouse_bit;
            m_selection_stop_bit = m_mouse_bit;
            m_RawData->SetCaretPosition((m_mouse_byte_local * 9) + m_mouse_bit - 1);
        }
        else if (m_text_ctrl == EDITOR_TEXT_CTRL_ASCII)
        {
            m_selection_start_bit = 0;
            m_selection_stop_bit = 7;
            m_RawData->SetCaretPosition((m_mouse_byte_local * 9) - 1);
        }
        else return; // unimplemented text ctrl
    }
    else return; // unimplemented display mode

    m_specimen->SetSelection(
        m_selection_start_byte, m_selection_start_bit,
        m_selection_stop_byte, m_selection_stop_bit);

    m_RawData->SetFocus();
}


void EditorPanel::OnLeftMouseButtonUp(
    wxMouseEvent& event)
{
    m_selecting = false;
}


void EditorPanel::OnContextMenuEvent(
    wxCommandEvent& event)
{
    int id = event.GetId();

    switch (id)
    {
    case EDITOR_MENU_ID_COPY:
        ContextMenuCopy();
        break;
    case EDITOR_MENU_ID_PASTE_OVERWRITE:
        ContextMenuPasteOverwrite();
        break;
    case EDITOR_MENU_ID_PASTE_INSERT:
        ContextMenuPasteInsert();
        break;
    case EDITOR_MENU_ID_DELETE:
        ContextMenuDelete();
        break;
    case EDITOR_MENU_ID_FILL:
        ContextMenuFill();
        break;
    case EDITOR_MENU_ID_FILL_ZERO:
        ContextMenuFillZero();
        break;
    case EDITOR_MENU_ID_XOR_MASK:
        ContextMenuXorMask();
        break;
    case EDITOR_MENU_ID_REVERSE:
        ContextMenuReverse();
        break;
    default:
        m_logger->LogWarning(this, "unimplemented popup menu item");
        break;
    }
}


void EditorPanel::OnKeyUp(
    wxKeyEvent& event)
{
    int code = event.GetKeyCode();

    if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
    {
        uint8_t value;

        switch (code)
        {
            case '0': value = 0x0; break;
            case '1': value = 0x1; break;
            case '2': value = 0x2; break;
            case '3': value = 0x3; break;
            case '4': value = 0x4; break;
            case '5': value = 0x5; break;
            case '6': value = 0x6; break;
            case '7': value = 0x7; break;
            case '8': value = 0x8; break;
            case '9': value = 0x9; break;
            case 'A': value = 0xA; break;
            case 'B': value = 0xB; break;
            case 'C': value = 0xC; break;
            case 'D': value = 0xD; break;
            case 'E': value = 0xE; break;
            case 'F': value = 0xF; break;
            default: return; break;
        }

        long caret_position = m_RawData->GetCaretPosition();
        uint64_t index = m_first_byte + ((caret_position + 1) / 3);

        uint8_t byte;
        if (index < m_size) { byte = m_bytes[index]; }
        else { byte = 0x00; }

        if ((caret_position + 1) % 3 == 0) // HI nibble
        {
            value <<= 4;
            byte &= 0xF;
            byte |= value;
            caret_position += 1;
        }
        else // LO nibble
        {
            byte &= 0xF0;
            byte |= value;
            caret_position += 2;
        }

        if (index < m_size)
        {
            m_specimen->FillBytes(index, 1, byte);
        }
        else
        {
            m_specimen->InsertBytes(index, 1, &byte);
        }

        m_RawData->SetCaretPosition(caret_position);
    }
    else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
    {
        uint8_t value;

        switch (code)
        {
            case '0': value = 0; break;
            case '1': value = 1; break;
            default: return; break;
        }

        long caret_position = m_RawData->GetCaretPosition();
        uint64_t index = m_first_byte + ((caret_position + 1) / 9);
        if (index >= m_size)
        {
            uint8_t new_byte[1] = { 0x00 };
            m_specimen->InsertBytes(m_size, 1, new_byte);
        }
        int bitpos = 7 - ((caret_position + 1) % 9);

        uint8_t byte = m_bytes[index];
        byte &= ~(0x1 << bitpos);
        byte |= (value << bitpos);

        if (bitpos > 0) { caret_position += 1; }
        else { caret_position += 2; }

        m_specimen->FillBytes(index, 1, byte);
        m_RawData->SetCaretPosition(caret_position);
    }
    else return; // unimplemented display mode
}


EditorSettings* EditorPanel::GetSettings()
{
    return &m_settings;
}


void EditorPanel::SyncWithSpecimen()
{
    m_bytes = m_specimen->GetRawData();
    m_size = m_specimen->GetSize();
}


void EditorPanel::ApplySettings()
{
    // set fonts
    m_OffsetsHeader->SetFont(m_settings.font);
    m_Offsets->SetFont(m_settings.font);
    m_RawDataHeader->SetFont(m_settings.font);
    m_RawData->SetFont(m_settings.font);
    m_AsciiDataHeader->SetFont(m_settings.font);
    m_AsciiData->SetFont(m_settings.font);

    // initialize "offsets" wxRichTextCtrl
    m_Offsets->EnableVerticalScrollbar(false);
    m_Offsets->SetTextCursor(*wxSTANDARD_CURSOR);

    // initialize "raw data" wxRichTextCtrl
    m_RawData->SetEditorPanel(this);
    m_RawData->EnableVerticalScrollbar(false);
    m_RawData->SetTextCursor(*wxSTANDARD_CURSOR);

    // initialize "ASCII data" wxRichTextCtrl
    m_AsciiData->SetEditorPanel(this);
    m_AsciiData->EnableVerticalScrollbar(false);
    m_AsciiData->SetTextCursor(*wxSTANDARD_CURSOR);

    // get width/height for current font
    wxClientDC dc(m_Offsets);
    dc.SetFont(m_settings.font);
    m_char_width = dc.GetCharWidth();
    m_char_height = dc.GetCharHeight();

    // calculate number of data digits required for largest possible file offset
    int m_offset_digits = 2;
    if (m_size > 0xFF) m_offset_digits++;
    if (m_size > 0xFFF) m_offset_digits++;
    if (m_size > 0xFFFF) m_offset_digits++;
    if (m_size > 0xFFFFF) m_offset_digits++;
    if (m_size > 0xFFFFFF) m_offset_digits++;
    if (m_size > 0xFFFFFFF) m_offset_digits++;
    if (m_size > 0xFFFFFFFF) m_offset_digits++;
    if (m_size > 0xFFFFFFFFF) m_offset_digits++;

    // create format string for printing offsets
    int m_offset_chars = m_offset_digits + 2; // account for "0x" prepending offset
    m_offset_format = wxString("0x%0") + wxString::Format("%d", m_offset_digits) + wxString("llX");

    // set offset text control width
    int m_offset_pixels =
        TEXT_CTRL_BORDER + TEXT_CTRL_PADDING +
        m_offset_chars * m_char_width +
        TEXT_CTRL_PADDING + TEXT_CTRL_BORDER;
    m_Offsets->SetSizeHints(m_offset_pixels, -1);
}


void EditorPanel::AdjustSizes()
{
    int vertical_pixels = GetClientSize().GetHeight() - (m_ToolbarPanel->GetSize().GetHeight() + m_OffsetsHeader->GetSize().GetHeight());
    int usable_vertical_pixels = vertical_pixels - ((2 * TEXT_CTRL_BORDER) + TEXT_CTRL_PADDING);
    int horizontal_pixels = GetSize().GetWidth() - m_Offsets->GetSize().GetWidth();
    int scrollbar_width = m_Scrollbar->GetSize().GetWidth();
    int usable_horizontal_pixels = horizontal_pixels - ((4 * TEXT_CTRL_BORDER) + (4 * TEXT_CTRL_PADDING) + scrollbar_width + 4);
    m_lines = (usable_vertical_pixels / (m_char_height + TEXT_CTRL_PADDING));
    int chars_per_line = usable_horizontal_pixels / m_char_width;

    int data_chars_per_line = 0;
    if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
    {
        m_bytes_per_line = (chars_per_line + 1) / 4;
        // the "+1" is for the last data byte not having a trailing space
        // 4 = 2 data digits + 1 trailing space + 1 ASCII character

        data_chars_per_line = (m_bytes_per_line * 3) - 1;
        // 3 = 2 data digits + 1 trailing space
        // the "-1" is for the last data byte not having a trailing space
    }
    else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
    {
        m_bytes_per_line = (chars_per_line + 1) / 10;
        // the "+1" is for the last binary byte not having a trailing space
        // 10 = 8 binary digits + 1 trailing space + 1 ASCII character

        data_chars_per_line = (m_bytes_per_line * 9) - 1;
        // 9 = 8 binary digits + 1 trailing space
        // the "-1" is for the last data byte not having a trailing space
    }
    else
    {
        // unsupported display mode!
    }

    // must be able to display at least one byte
    if (m_lines < 1 || m_bytes_per_line < 1)
    {
        m_active = false;
        return;
    }

    m_active = true;

    // calculate local range
    m_first_byte = m_first_byte - (m_first_byte % m_bytes_per_line);
    m_last_byte = m_first_byte + (m_lines * m_bytes_per_line) - 1; // NOTE: m_last_byte can be greater than m_size!

    // adjust data byte text control width
    int data_bytes_width_pixels =
        (2 * TEXT_CTRL_BORDER) +
        (2 * TEXT_CTRL_PADDING) +
        (data_chars_per_line * m_char_width);
    m_RawData->SetSizeHints(data_bytes_width_pixels, -1);

    // adjust ASCII byte text control width
    int ascii_bytes_width_pixels =
        (2 * TEXT_CTRL_BORDER) +
        (2 * TEXT_CTRL_PADDING) +
        (m_bytes_per_line * m_char_width);
    m_AsciiData->SetSizeHints(ascii_bytes_width_pixels, -1);

    // adjust scrollbar
    int position = m_first_byte / m_bytes_per_line;
    int thumb_size = m_lines;
    int range = (m_size / m_bytes_per_line) + 1;
    int page_size = 3;
    m_Scrollbar->SetScrollbar(position, thumb_size, range, page_size, true);
}


void EditorPanel::MouseMovement(
    void*   source,
    int     position)
{
    // if Editor is not active, return immediately
    if (m_active == false) return;

    // set wxRichTextCtrl source
    if (source == (void*)m_RawData) m_text_ctrl = EDITOR_TEXT_CTRL_RAW;
    else if (source == (void*)m_AsciiData) m_text_ctrl = EDITOR_TEXT_CTRL_ASCII;
    else m_text_ctrl = EDITOR_TEXT_CTRL_UNKNOWN; // should never happen

    // calculate localized byte and bit indices underneath mouse cursor
    if (m_text_ctrl == EDITOR_TEXT_CTRL_RAW)
    {
        if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
        {
            m_mouse_byte_local = position / 3;
            m_mouse_bit = 0;
        }
        else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
        {
            m_mouse_byte_local = position / 9;
            m_mouse_bit = position % 9;
            if (m_mouse_bit > 7) m_mouse_bit = 7;
        }
        else return; // unimplemented display mode
    }
    else if (m_text_ctrl == EDITOR_TEXT_CTRL_ASCII)
    {
        m_mouse_byte_local = position - (position / (m_bytes_per_line + 1));
        m_mouse_bit = 0;
    }
    else return; // unimplemented text control

    // calculate actual Specimen byte index from localized index
    m_mouse_byte = m_first_byte + m_mouse_byte_local;

    // past end of bytes
    if (m_mouse_byte >= m_size)
    {
        m_mouse_byte_exists = false;
    }
    else
    {
        m_mouse_byte_exists = true;

        if (m_selecting)
        {
            m_selection_stop_byte_local = m_mouse_byte_local;
            m_selection_stop_byte = m_mouse_byte;

            if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
            {
                m_selection_stop_bit = 7;
            }
            else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
            {
                if (source == m_AsciiData) m_selection_stop_bit = 7;
                else m_selection_stop_bit = m_mouse_bit;
            }
            else return; // unimplemented display mode

            m_specimen->SetSelection(
                m_selection_start_byte, m_selection_start_bit,
                m_selection_stop_byte, m_selection_stop_bit);
        }
    }
}


void EditorPanel::Scroll(
    int position)
{
    m_first_byte = (position * m_bytes_per_line);
    GenerateText();
    LocalizeSelectionRange();
    LocalizeColorTemplate();
    FormatText();
}


void EditorPanel::SetSelection(
    uint64_t    selection_start_byte,
    uint8_t     selection_start_bit,
    uint64_t    selection_stop_byte,
    uint8_t     selection_stop_bit)
{
    m_selection_exists = true;
    m_raw_menu->Enable(EDITOR_MENU_ID_COPY, true);
    m_ascii_menu->Enable(EDITOR_MENU_ID_COPY, true);
    
    m_selection_start_byte = selection_start_byte;
    m_selection_start_bit = selection_start_bit;
    m_selection_stop_byte = selection_stop_byte;
    m_selection_stop_bit = selection_stop_bit;

    m_selection_start_byte_local = m_selection_start_byte - m_first_byte;
    m_selection_stop_byte_local = m_selection_stop_byte - m_first_byte;
}


void EditorPanel::ClearSelection()
{
    m_selection_exists = false;
    m_raw_menu->Enable(EDITOR_MENU_ID_COPY, false);
    m_ascii_menu->Enable(EDITOR_MENU_ID_COPY, true);
    FormatText();
}


void EditorPanel::LocalizeSelectionRange()
{
    m_selection_start_byte_local = m_selection_start_byte - m_first_byte;
    m_selection_stop_byte_local = m_selection_stop_byte - m_first_byte;
}


void EditorPanel::GenerateHeaders()
{
    if (m_active == false)
    {
        m_RawDataHeader->SetLabel(wxString(""));
        m_AsciiDataHeader->SetLabel(wxString(""));
        return;
    }

    wxString data_bytes_header;
    wxString ascii_bytes_header;

    for (unsigned int byte = 0; byte < m_bytes_per_line; byte++)
    {
        if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
        {
            data_bytes_header += wxString::Format("%02X", (uint8_t)byte);
        }
        else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
        {
            data_bytes_header += wxString::Format("   %02X   ", (uint8_t)byte);
        }
        else
        {
            // unsupported display mode
        }

        if (byte < (m_bytes_per_line - 1)) data_bytes_header += " ";
        ascii_bytes_header += wxString::Format("%X", (uint8_t)(byte % 16));
    }

    m_RawDataHeader->SetLabel(data_bytes_header);
    m_AsciiDataHeader->SetLabel(ascii_bytes_header);
}


void EditorPanel::GenerateText()
{
    m_Offsets->Clear();
    m_RawData->Clear();
    m_AsciiData->Clear();

    if (m_active == false) return;

    wxString offsets_text;
    wxString data_bytes_text;
    wxString ascii_bytes_text;

    uint8_t value;
    int64_t index = m_first_byte;

    for (unsigned int line = 0; line < m_lines; line++)
    {
        // generate offsets
        if ((line * m_bytes_per_line) < m_size) offsets_text += wxString::Format(m_offset_format, index) + wxString("\n");

        if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
        {
            // generate data bytes and ascii bytes
            for (unsigned int byte = 0; byte < m_bytes_per_line; byte++)
            {
                if (index < (int64_t)m_size)
                {
                    value = m_bytes[index];
                    data_bytes_text += wxString::Format("%02X ", value);
                    if (value >= 0x20 && value <= 0x7E) ascii_bytes_text += wxString::Format("%c", value);
                    else ascii_bytes_text += ".";
                }
                else
                {
                    data_bytes_text += "   ";
                    ascii_bytes_text += " ";
                }

                index++;
            }
        }
        else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
        {
            // generate binary bytes and ascii bytes
            for (unsigned int byte = 0; byte < m_bytes_per_line; byte++)
            {
                if (index < (int64_t)m_size)
                {
                    value = m_bytes[index];
                    for (int i = 7; i >= 0; i--)
                    {
                        if (((value >> i) & 0x01) == 0) data_bytes_text += "0";
                        else data_bytes_text += "1";
                    }
                    data_bytes_text += " ";
                    if (value >= 0x20 && value <= 0x7E) ascii_bytes_text += wxString::Format("%c", value);
                    else ascii_bytes_text += ".";
                }
                else
                {
                    data_bytes_text += "         ";
                    ascii_bytes_text += " ";
                }

                index++;
            }
        }
        else {} // unsupported display mode

        data_bytes_text.RemoveLast();
        data_bytes_text += "\n";
        ascii_bytes_text += "\n";
    }

    // refresh text controls
    m_Offsets->WriteText(offsets_text);
    m_RawData->WriteText(data_bytes_text);
    m_AsciiData->WriteText(ascii_bytes_text);
}


void EditorPanel::FormatText()
{
    // if window is too small, don't apply any formatting
    if (m_active == false) return;

    // apply ColorTemplate
    if (m_color_template && (m_show_color_template == true))
    {
        for (unsigned int i = 0; i < m_data_ranges.size(); i++)
        {
            m_RawData->SetStyleEx(m_data_ranges[i].range, m_data_ranges[i].attr);
            m_AsciiData->SetStyleEx(m_ascii_ranges[i].range, m_ascii_ranges[i].attr);
        }
    }

    if (m_selection_exists == false) return;

    int selection_start_byte_local;
    int selection_start_bit_local;
    int selection_stop_byte_local;
    int selection_stop_bit_local;

    if ((m_selection_start_byte < m_selection_stop_byte) ||
        ((m_selection_start_byte == m_selection_stop_byte) && (m_selection_start_bit <= m_selection_stop_bit)))
    {
            selection_start_byte_local = m_selection_start_byte_local;
            selection_start_bit_local = m_selection_start_bit;
            selection_stop_byte_local = m_selection_stop_byte_local;
            selection_stop_bit_local = m_selection_stop_bit;
    }
    else // start > stop
    {
        selection_start_byte_local = m_selection_stop_byte_local;
        selection_start_bit_local = m_selection_stop_bit;
        selection_stop_byte_local = m_selection_start_byte_local;
        selection_stop_bit_local = m_selection_start_bit;
    }

    // selection range for raw data wxRichTextCtrl 
    long selection_start_data_char;
    long selection_stop_data_char;

    if (m_display_mode == EDITOR_DISPLAY_MODE_BYTES)
    {
        selection_start_data_char = selection_start_byte_local * 3;
        selection_stop_data_char = selection_stop_byte_local * 3 + 2;
    }
    else if (m_display_mode == EDITOR_DISPLAY_MODE_BITS)
    {
        selection_start_data_char = selection_start_byte_local * 9;
        selection_start_data_char += selection_start_bit_local;
        selection_stop_data_char = selection_stop_byte_local * 9;
        selection_stop_data_char += selection_stop_bit_local + 1;
    }
    else return; // unimplemented display mode

    // selection range for ASCII wxRichTextCtrl
    long selection_start_ascii_char = selection_start_byte_local + (selection_start_byte_local / m_bytes_per_line);
    long selection_stop_ascii_char = selection_stop_byte_local + (selection_stop_byte_local / m_bytes_per_line) + 1;

    // set selections
    long caret = m_RawData->GetCaretPosition();
    m_RawData->SetSelection(selection_start_data_char, selection_stop_data_char);
    m_AsciiData->SetSelection(selection_start_ascii_char, selection_stop_ascii_char);
    m_RawData->SetCaretPosition(caret);
}


void EditorPanel::AddColorTemplate(
    ColorTemplate* color_template)
{
    m_color_template = color_template;

    if (m_show_color_template == true)
    {
        LocalizeColorTemplate();
        FormatText();
    }
}


void EditorPanel::RemoveColorTemplate(
    ColorTemplate* color_template)
{
    m_color_template = nullptr;

    if (m_show_color_template == true)
    {
        LocalizeColorTemplate();
        FormatText();
    }
}


void EditorPanel::LocalizeColorTemplate()
{
    if (m_color_template == nullptr) return;

    m_data_ranges.clear();
    m_ascii_ranges.clear();

    uint64_t start;
    uint64_t stop;

    LocalColorRange local_range;

    for (unsigned int i = 0; i < m_color_template->GetRangeCount(); i++)
    {
        ColorRange* range = m_color_template->GetRange(i);
        start = range->start;
        stop = range->stop;

        // check if range is in view
        if (start < m_first_byte) continue;
        if (stop > m_last_byte) continue;

        // localize offsets
        start = start - m_first_byte;
        stop = stop - m_first_byte;

        // set color
        local_range.attr.SetTextColour(range->text_color);
        local_range.attr.SetBackgroundColour(range->background_color);

        // add localized range for data bytes control
        local_range.range.SetStart(start * 3);
        local_range.range.SetEnd((stop * 3) + 2);
        m_data_ranges.push_back(local_range);

        // add localized range for ASCII bytes control
        local_range.range.SetStart(start + (start / m_bytes_per_line));
        local_range.range.SetEnd(stop + (stop / m_bytes_per_line) + 1);
        m_ascii_ranges.push_back(local_range);
    }
}


void EditorPanel::ContextMenuCopy()
{
    if (m_copy_buffer_size > 0) delete[] m_copy_buffer;

    if (m_selection_start_byte <= m_selection_stop_byte)
    {
        m_copy_buffer_size = (m_selection_stop_byte - m_selection_start_byte) + 1;
    }
    else
    {
        m_copy_buffer_size = (m_selection_start_byte - m_selection_stop_byte) + 1;
    }

    m_copy_buffer = new uint8_t[m_copy_buffer_size];

    m_specimen->GetBytes(m_selection_start_byte, m_copy_buffer_size, m_copy_buffer);

    m_raw_menu->Enable(EDITOR_MENU_ID_PASTE_OVERWRITE, true);
    m_ascii_menu->Enable(EDITOR_MENU_ID_PASTE_OVERWRITE, true);
    m_raw_menu->Enable(EDITOR_MENU_ID_PASTE_INSERT, true);
    m_ascii_menu->Enable(EDITOR_MENU_ID_PASTE_INSERT, true);
}


void EditorPanel::ContextMenuPasteOverwrite()
{
    if (m_selection_exists)
    {
        if (m_specimen->ReplaceBytes(m_selection_start_byte, m_copy_buffer_size, m_copy_buffer) == true)
        {
            m_specimen->SetSelection(m_selection_start_byte, 0, (m_selection_start_byte + m_copy_buffer_size - 1), 0);
        }
    }
}


void EditorPanel::ContextMenuPasteInsert()
{
    if (m_selection_exists)
    {
        if (m_specimen->InsertBytes(m_selection_start_byte, m_copy_buffer_size, m_copy_buffer) == true)
        {
            m_specimen->SetSelection(m_selection_start_byte, 0, (m_selection_start_byte + m_copy_buffer_size - 1), 0);
        }
    }
}


void EditorPanel::ContextMenuDelete()
{
    if (m_selection_exists)
    {
        if (m_specimen->DeleteBytes(m_selection_start_byte, (m_selection_stop_byte - m_selection_start_byte + 1)) == true)
        {
            m_specimen->ClearSelection();
        }
    }
}


void EditorPanel::ContextMenuFill()
{
    if (m_selection_exists)
    {
        uint8_t byte;
        FillValueDialog* dlg = new FillValueDialog(nullptr, &byte);
        int rv = dlg->ShowModal();
        dlg->Destroy();

        if (rv == 1)
        {
            uint64_t selection_size = m_selection_stop_byte - m_selection_start_byte + 1;

            m_specimen->FillBytes(m_selection_start_byte, selection_size, byte);
        }
    }
}


void EditorPanel::ContextMenuFillZero()
{
    if (m_selection_exists)
    {
        uint64_t selection_size = m_selection_stop_byte - m_selection_start_byte + 1;

        m_specimen->FillBytes(m_selection_start_byte, selection_size, 0x00);
    }
}


void EditorPanel::ContextMenuXorMask()
{
    if (m_selection_exists)
    {
        uint8_t byte;
        MaskValueDialog* dlg = new MaskValueDialog(nullptr, &byte);
        int rv = dlg->ShowModal();
        dlg->Destroy();

        if (rv == 1)
        {
            uint64_t selection_size = m_selection_stop_byte - m_selection_start_byte + 1;

            uint8_t* masked = new uint8_t[selection_size];
            for (unsigned int i = 0; i < selection_size; i++)
            {
                masked[i] = m_bytes[m_selection_start_byte + i] ^ byte;
            }

            m_specimen->ReplaceBytes(m_selection_start_byte, selection_size, masked);

            delete[] masked;
        }
    }
}


void EditorPanel::ContextMenuReverse()
{
    if (m_selection_exists)
    {
        uint64_t selection_size = m_selection_stop_byte - m_selection_start_byte + 1;

        uint8_t* reversed = new uint8_t[selection_size];
        for (unsigned int i = 0; i < selection_size; i++)
        {
            reversed[i] = m_bytes[m_selection_start_byte + selection_size - 1 - i];
        }

        m_specimen->ReplaceBytes(m_selection_start_byte, selection_size, reversed);

        delete[] reversed;
    }
}