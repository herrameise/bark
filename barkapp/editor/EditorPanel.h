#ifndef __BARK_APP___EDITOR_PANEL_H__
#define __BARK_APP___EDITOR_PANEL_H__

#include <cstdint>
#include <vector>
using std::vector;

class wxWindow;
#include <wx/richtext/richtextctrl.h>

#include <bark/Blade.h>
#include "EditorForms.h"
#include "EditorSettings.h"



#define TEXT_CTRL_BORDER                2   // pixels
#define TEXT_CTRL_PADDING               5   // pixels
#define SCROLLBAR_WIDTH                 24  // pixels

#define EDITOR_MENU_ID_COPY             1
#define EDITOR_MENU_ID_PASTE_OVERWRITE  2
#define EDITOR_MENU_ID_PASTE_INSERT     3
#define EDITOR_MENU_ID_DELETE           4
#define EDITOR_MENU_ID_FILL             5
#define EDITOR_MENU_ID_FILL_ZERO        6
#define EDITOR_MENU_ID_XOR_MASK         7
#define EDITOR_MENU_ID_REVERSE          8



namespace bark
{
    namespace app
    {
        class Logger;
        class Manager;
        class Specimen;
        class ColorTemplate;

        typedef enum _EDITOR_TEXT_CTRL
        {
            EDITOR_TEXT_CTRL_RAW = 0,
            EDITOR_TEXT_CTRL_ASCII = 1,
            EDITOR_TEXT_CTRL_UNKNOWN = 0xFFFFFFFF
        } EDITOR_TEXT_CTRL;

        typedef enum _EDITOR_DISPLAY_MODE
        {
            EDITOR_DISPLAY_MODE_BYTES = 0,
            EDITOR_DISPLAY_MODE_BITS = 1
        } EDITOR_DISPLAY_MODE;

        typedef struct _LocalColorRange
        {
            wxRichTextRange     range;
            wxRichTextAttr      attr;
        } LocalColorRange;

        class EditorPanel : public EditorPanelForm
        {
        public:
            EditorPanel(
                wxWindow*   parent,
                Logger*     logger,
                Manager*    manager,
                Specimen*   specimen);

            ~EditorPanel();

            void BuildContextMenus();

            void BindEvents();

            void OnButtonSettings(
                wxCommandEvent& event);

            void OnComboBoxDisplayMode(
                wxCommandEvent& event);

            void OnCheckBoxColorTemplate(
                wxCommandEvent& event);

            void OnResize(
                wxSizeEvent& event);

            void OnScroll(
                wxScrollEvent& event);

            void OnLeaveWindow(
                wxMouseEvent& event);

            void OnLeftMouseButtonDown(
                wxMouseEvent& event);

            void OnLeftMouseButtonUp(
                wxMouseEvent& event);

            void OnContextMenuEvent(
                wxCommandEvent& event);

            void OnKeyUp(
                wxKeyEvent& event);

            EditorSettings* GetSettings();

            void SyncWithSpecimen();

            void ApplySettings();

            void AdjustSizes();

            void Scroll(
                int position);

            void MouseMovement(
                void*   source,
                int     local_byte);

            void GenerateHeaders();

            void GenerateText();

            void SetSelection(
                uint64_t    selection_start_byte,
                uint8_t     selection_start_bit,
                uint64_t    selection_stop_byte,
                uint8_t     selection_stop_bit);

            void ClearSelection();

            void LocalizeSelectionRange();

            void FormatText();

            void AddColorTemplate(
                ColorTemplate* color_template);

            void RemoveColorTemplate(
                ColorTemplate* color_template);

            void LocalizeColorTemplate();

        private:
            Logger*                 m_logger;                       //!< Pointer to Logger.
            Manager*                m_manager;                      //!< Pointer to Manager.
            Specimen*               m_specimen;                     //!< Pointer to Specimen.

            EditorSettings          m_settings;                     //!< Editor settings.

            uint8_t*                m_bytes;                        //!< Pointer to raw bytes (uint8_t*) of Specimen.
            uint64_t                m_size;                         //!< Size of Specimen [bytes].

            bool                    m_active;                       //!< Is the window is large enough to display at least 1 byte/8 bits + 1 ASCII character?
            EDITOR_DISPLAY_MODE     m_display_mode;                 //!< Display mode ("bytes" vs. "bits").

            unsigned int            m_char_width;                   //!< Character width [pixels].
            unsigned int            m_char_height;                  //!< Character height [pixels].

            unsigned int            m_lines;                        //!< Number of lines.
            unsigned int            m_bytes_per_line;               //!< Number of full bytes (2 hex digits/8 binary digits + space + 1 ASCII digit) per line.
            wxString                m_offset_format;                //!< Offset format string (ex: "0x%05x").

            uint64_t                m_first_byte;                   //!< Global Specimen offset of first byte shown in Editor.
            uint64_t                m_last_byte;                    //!< Global Offset of last (theoretical) byte shown in Editr. NOTE: m_last_byte can be > m_size!

            bool                    m_selecting;                    //!< Is the user currently selecting a range (LMB down + drag)?
            bool                    m_selection_exists;             //!< Is there a selection?
            uint64_t                m_selection_start_byte;         //!< Global selection start byte.
            uint64_t                m_selection_start_byte_local;   //!< Localized selection start byte.
            uint8_t                 m_selection_start_bit;          //!< Global selection start bit.
            uint64_t                m_selection_stop_byte;          //!< Global selection stop byte.
            uint64_t                m_selection_stop_byte_local;    //!< Localized selection stop byte.
            uint8_t                 m_selection_stop_bit;           //!< Global selection stop bit.

            EDITOR_TEXT_CTRL        m_text_ctrl;                    //!< wxRichTextCtrl in focus ("raw" vs "ASCII").
            bool                    m_mouse_byte_exists;            //!< Is there actually valid Specimen data under the mouse cursor?
            uint64_t                m_mouse_byte;                   //!< Global byte offset underneath mouse cursor.
            uint64_t                m_mouse_byte_local;             //!< Byte index underneath mouse cursor (local).
            uint8_t                 m_mouse_bit;                    //!< Bit index underneath mouse cursor.

            bool                        m_show_color_template;      //!< show color template (checkbox)
            ColorTemplate*              m_color_template;           //!< color template for coloring ranges
            vector<LocalColorRange>     m_data_ranges;              //!< localized hex byte ranges for color template
            vector<LocalColorRange>     m_ascii_ranges;             //!< localized ASCII byte ranges for color template

            wxMenu* m_raw_menu;
            wxMenu* m_ascii_menu;
            void ContextMenuCopy();
            void ContextMenuPasteOverwrite();
            void ContextMenuPasteInsert();
            void ContextMenuDelete();
            void ContextMenuFill();
            void ContextMenuFillZero();
            void ContextMenuXorMask();
            void ContextMenuReverse();
            uint8_t*    m_copy_buffer;
            size_t      m_copy_buffer_size;
        };

    } // namespace "app"
}


#endif // __BARK_APP___EDITOR_PANEL_H__