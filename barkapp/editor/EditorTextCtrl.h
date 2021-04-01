#ifndef __BARK_APP___EDITOR_TEXT_CTRL_H__
#define __BARK_APP___EDITOR_TEXT_CTRL_H__

#include <wx/richtext/richtextctrl.h>



namespace bark
{
    namespace app
    {
        class Logger;
        class EditorPanel;

        class EditorTextCtrl : public wxRichTextCtrl
        {
        public:
            EditorTextCtrl(
                wxWindow*           parent,
                wxWindowID          id,
                const wxString&     value,
                const wxPoint&      pos,
                const wxSize&       size,
                long                style);

            ~EditorTextCtrl() {}

            void SetEditorPanel(
                EditorPanel* editor_panel);

            bool ProcessMouseMovement(
                wxRichTextParagraphLayoutBox*   container,
                wxRichTextObject*               obj,
                long                            position,
                const wxPoint&                  pos) override;

            void OnEnterWindow(
                wxMouseEvent& event);

        private:
            EditorPanel*        m_editor_panel;
            long                m_mouse_char;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___EDITOR_TEXT_CTRL_H__