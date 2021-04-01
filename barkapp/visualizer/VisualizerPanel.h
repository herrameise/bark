#ifndef __BARK_APP___VISUALIZER_PANEL_H__
#define __BARK_APP___VISUALIZER_PANEL_H__

#include <cstdint>
#include <vector>
using std::vector;

class wxWindow;
#include <wx/brush.h>
#include <wx/pen.h>
#include <wx/richtext/richtextctrl.h>

#include <bark/Blade.h>
#include "VisualizerForms.h"
#include "VisualizerSettings.h"



namespace bark
{
    namespace app
    {
        class Logger;
        class Manager;
        class Specimen;

        class VisualizerPanel : public VisualizerPanelForm
        {
        public:
            VisualizerPanel(
                wxWindow*   parent,
                Logger*     logger,
                Manager*    manager,
                Specimen*   specimen);

            ~VisualizerPanel();

            inline VisualizerSettings* GetSettings() { return &m_settings; }

            void BuildContextMenu();

            void BindEvents();

            inline void Activate() { m_active = true; }
            inline void Deactivate() { m_active = false; }

            void OnButtonSettings(
                wxCommandEvent& event);

            void OnSpinButtonZoom(
                wxSpinEvent& event);

            void OnResize(
                wxSizeEvent& event);

            void OnScroll(
                wxScrollEvent& event);

            void SyncWithSpecimen();

            void SetSelection(
                uint64_t    start,
                uint64_t    stop);

            void ApplySettings();

            void Scroll(
                int position);

            void Resize();

            void GetBits();

            void Draw();

        private:
            Logger*                 m_logger;
            Manager*                m_manager;
            Specimen*               m_specimen;

            VisualizerSettings      m_settings;

            uint8_t*                m_bytes;
            uint64_t                m_size;

            bool                    m_active;

            unsigned int            m_canvas_width;
            unsigned int            m_canvas_height;

            unsigned int            m_zoom;
            unsigned int            m_available_rows;
            unsigned int            m_available_cols;

            unsigned int            m_rows;
            unsigned int            m_cols;

            uint64_t                m_start_bit;
            uint64_t                m_stop_bit;
            uint8_t*                m_bits;

            bool                    m_selection_exists;
            uint64_t                m_selection_start_bit;
            uint64_t                m_selection_stop_bit;

            wxBrush                 m_brush_normal_zero;
            wxBrush                 m_brush_normal_one;
            wxBrush                 m_brush_selection_zero;
            wxBrush                 m_brush_selection_one;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___VISUALIZER_PANEL_H__