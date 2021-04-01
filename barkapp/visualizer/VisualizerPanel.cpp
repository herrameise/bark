#include "VisualizerPanel.h"
using namespace bark::app;

#include <wx/dcclient.h>
#include <wx/graphics.h>
#include <wx/scrolbar.h>

#include "../Logger.h"
#include "../Manager.h"
#include "../Specimen.h"
#include "VisualizerSettingsDialog.h"



VisualizerPanel::VisualizerPanel(
    wxWindow*   parent,
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen) :
    VisualizerPanelForm(parent),
    m_logger(logger),
    m_manager(manager),
    m_specimen(specimen)
{
    m_settings.normal_zero = *wxWHITE;
    m_settings.normal_one = *wxBLACK;
    m_settings.selection_zero = *wxCYAN;
    m_settings.selection_zero = *wxBLUE;
    m_settings.snap = 8;
    m_settings.show_separators = true;

    m_SpinButtonZoom->SetRange(0, 5);
    m_SpinButtonZoom->SetValue(2);
    m_zoom = 4;

    m_start_bit = 0;
    m_bits = nullptr;

    m_brush_normal_zero.SetColour(*wxWHITE);
    m_brush_normal_zero.SetStyle(wxBRUSHSTYLE_SOLID);
    m_brush_normal_one.SetColour(*wxBLACK);
    m_brush_normal_one.SetStyle(wxBRUSHSTYLE_SOLID);
    m_brush_selection_zero.SetColour(*wxCYAN);
    m_brush_selection_zero.SetStyle(wxBRUSHSTYLE_SOLID);
    m_brush_selection_one.SetColour(*wxBLUE);
    m_brush_selection_one.SetStyle(wxBRUSHSTYLE_SOLID);

    BindEvents();
    SyncWithSpecimen();
}


VisualizerPanel::~VisualizerPanel()
{
    if (m_bits) { delete[] m_bits; }
}


void VisualizerPanel::BuildContextMenu() {}


void VisualizerPanel::BindEvents()
{
    m_ButtonSettings->Bind(wxEVT_BUTTON, &VisualizerPanel::OnButtonSettings, this);
    m_SpinButtonZoom->Bind(wxEVT_SPIN, &VisualizerPanel::OnSpinButtonZoom, this);

    m_Canvas->Bind(wxEVT_SIZE, &VisualizerPanel::OnResize, this);

    m_ScrollBar->Bind(wxEVT_SCROLL_CHANGED, &VisualizerPanel::OnScroll, this);
}


void VisualizerPanel::OnButtonSettings(
    wxCommandEvent& event)
{
    VisualizerSettingsDialog* dlg = new VisualizerSettingsDialog(nullptr, this);
    dlg->ShowModal();

    ApplySettings();

    if (m_active == false) { return; }

    Resize();
    GetBits();
    Draw();
}


void VisualizerPanel::OnResize(
    wxSizeEvent &event)
{
    event.Skip();

    if (m_active == false) { return; }

    Resize();
    GetBits();
    Draw();
}


void VisualizerPanel::OnScroll(
    wxScrollEvent& event)
{
    if (m_active == false) { return; }

    Scroll(m_ScrollBar->GetThumbPosition());
    GetBits();
    Draw();
}


void VisualizerPanel::OnSpinButtonZoom(
    wxSpinEvent& event)
{
    if (m_active == false) { return; }

    int value = m_SpinButtonZoom->GetValue();

    switch (value)
    {
        case 0: m_zoom = 1; break;
        case 1: m_zoom = 2; break;
        case 2: m_zoom = 4; break;
        case 3: m_zoom = 8; break;
        case 4: m_zoom = 16; break;
        case 5: m_zoom = 32; break;
        default: m_zoom = 4; break;
    }

    Resize();
    GetBits();
    Draw();
}


void VisualizerPanel::SyncWithSpecimen()
{
    if (m_specimen->Exists())
    {
        m_active = true;

        m_bytes = m_specimen->GetRawData();
        m_size = m_specimen->GetSize();

        if (m_specimen->SelectionExists())
        {
            m_selection_exists = true;

            m_start_bit = m_specimen->GetSelectionStartByte() * 8 + m_specimen->GetSelectionStartBit();
            m_stop_bit = m_specimen->GetSelectionStopByte() * 8 + m_specimen->GetSelectionStopBit();
        }
        else
        {
            m_selection_exists = false;
        }
    }
    else
    {
        m_active = false;
    }
}


void VisualizerPanel::SetSelection(
    uint64_t    start,
    uint64_t    stop)
{
    m_selection_start_bit = start;
    m_selection_stop_bit = stop;
}


void VisualizerPanel::ApplySettings()
{
    m_brush_normal_zero.SetColour(m_settings.normal_zero);
    m_brush_normal_one.SetColour(m_settings.normal_one);
    m_brush_selection_zero.SetColour(m_settings.selection_zero);
    m_brush_selection_one.SetColour(m_settings.selection_one);
}


void VisualizerPanel::Scroll(
    int position)
{
    m_start_bit = position * m_cols;
}


void VisualizerPanel::Resize()
{
    if (m_active == false) return;

    wxSize size = m_Canvas->GetClientSize();
    m_canvas_width = (unsigned int)size.GetWidth();
    m_canvas_height = (unsigned int)size.GetHeight();

    m_available_rows = (m_canvas_height / m_zoom) - 2;
    m_available_cols = (m_canvas_width / m_zoom) - 1;

    unsigned int groups = m_available_cols / m_settings.snap;
    if (m_settings.show_separators) { groups = m_available_cols / (m_settings.snap + 1); }

    m_cols = groups * m_settings.snap;
    m_rows = m_available_rows;

    // adjust scrollbar
    int position = m_start_bit / m_cols;
    int thumb_size = m_rows;
    int range = ((m_size * 8) / m_cols) + 1;
    int page_size = 3;
    m_ScrollBar->SetScrollbar(position, thumb_size, range, page_size, true);

    m_StaticTextColumns->SetLabel(wxString::Format("%u", m_cols));
}


void VisualizerPanel::GetBits()
{
    if (m_active == false) return;

    if (m_bits) { delete[] m_bits; }
    m_bits = new uint8_t[m_rows * m_cols];

    uint64_t byte_idx = m_start_bit / 8;
    unsigned int bit_idx = m_start_bit % 8;

    uint8_t byte = m_bytes[byte_idx];
    unsigned int bit;

    uint64_t current_idx = m_start_bit;

    for (unsigned int row = 0; row < m_rows; row++)
    {
        for (unsigned int col = 0; col < m_cols; col++)
        {
            // get byte (if needed)
            if (bit_idx == 0)
            {
                byte = m_bytes[byte_idx];
                byte_idx++;
            }

            // extract bit from byte
            bit = (byte >> (7 - bit_idx)) & 0x01;

            // determine if bit is "0" or "1"
            if (current_idx >= m_selection_start_bit &&
                current_idx <= m_selection_stop_bit)
            {
                if (bit == 0) { m_bits[row * m_cols + col] = 0x02; }
                else { m_bits[row * m_cols + col] = 0x03; }
            }
            else
            {
                if (bit == 0) { m_bits[row * m_cols + col] = 0x00; }
                else { m_bits[row * m_cols + col] = 0x01; }
            }

            bit_idx++;
            current_idx++;
            if (bit_idx > 7) { bit_idx = 0; }
        }
    }
}


void VisualizerPanel::Draw()
{
    if (m_active == false) { return; }

    wxClientDC dc(m_Canvas);

    dc.Clear();
    dc.SetPen(*wxTRANSPARENT_PEN);

    wxSize size = wxSize(m_zoom, m_zoom);

    bool show_separators = m_settings.show_separators;
    unsigned int snap = m_settings.snap;

    for (unsigned int row = 0; row < m_rows; row++)
    {
        unsigned int pos = 0;

        for (unsigned int col = 0; col < m_cols; col++)
        {
            if ((col > 0) && (col % snap) == 0)
            {
                if (show_separators) { pos++; }
            }

            uint8_t bit = m_bits[(row * m_cols) + col];
            switch (bit)
            {
                case 0x00:
                default:
                    dc.SetBrush(m_brush_normal_zero);
                    break;

                case 0x01:
                    dc.SetBrush(m_brush_normal_one);
                    break;

                case 0x02:
                    dc.SetBrush(m_brush_selection_zero);
                    break;

                case 0x03:
                    dc.SetBrush(m_brush_selection_one);
                    break;
            }

            pos++;
            dc.DrawRectangle(wxPoint(pos * m_zoom, (row + 1) * m_zoom), size);
        }
    }
}