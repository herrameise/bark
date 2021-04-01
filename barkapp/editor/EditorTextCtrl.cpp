#include "EditorTextCtrl.h"
using namespace bark::app;

#include <wx/cursor.h>

#include "EditorPanel.h"
#include "../Logger.h"



EditorTextCtrl::EditorTextCtrl(
    wxWindow*           parent,
    wxWindowID          id,
    const wxString&     value,
    const wxPoint&      pos,
    const wxSize&       size,
    long                style) :
    wxRichTextCtrl(parent, id, value, pos, size, style)
{
    m_mouse_char = -1;

    Bind(wxEVT_ENTER_WINDOW, &EditorTextCtrl::OnEnterWindow, this);
}


void EditorTextCtrl::SetEditorPanel(
    EditorPanel* editor_panel)
{
    m_editor_panel = editor_panel;
}


bool EditorTextCtrl::ProcessMouseMovement(
    wxRichTextParagraphLayoutBox*   container,
    wxRichTextObject*               obj,
    long                            position,
    const wxPoint&                  pos)
{
    if (position != m_mouse_char)
    {
        m_mouse_char = position;
        m_editor_panel->MouseMovement(this, position);
    }

    return true;
}


void EditorTextCtrl::OnEnterWindow(
    wxMouseEvent& event)
{
    SetCursor(wxCURSOR_ARROW);
}