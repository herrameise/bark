#ifndef __BARK_APP___VISUALIZER_SETTINGS_H__
#define __BARK_APP___VISUALIZER_SETTINGS_H__

#include <wx/colour.h>



namespace bark
{
    namespace app
    {
        class VisualizerSettings
        {
        public:
            VisualizerSettings();

            ~VisualizerSettings();

            wxColor         normal_zero;
            wxColor         normal_one;
            wxColor         selection_zero;
            wxColor         selection_one;

            unsigned int    snap;
            bool            show_separators;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___VISUALIZER_SETTINGS_H__