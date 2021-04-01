#ifndef __BARK_APP___COLOR_TEMPLATE_H__
#define __BARK_APP___COLOR_TEMPLATE_H__

#include <cstdint>
#include <vector>
using namespace std;

#include <wx/colour.h>

#include "Export.h"



namespace bark
{
    namespace app
    {
        typedef struct ColorRange
        {
            uint64_t    start;
            uint64_t    stop;
            wxColor     text_color;
            wxColor     background_color;
        } ColorRange;

        struct ColorTemplateOpaque;

        class BARK_APP_EXPORT ColorTemplate
        {
        public:
            ColorTemplate();

            ~ColorTemplate();

            void AddRange(
                uint64_t    start,
                uint64_t    stop,
                wxColor     text_color,
                wxColor     background_color);

            unsigned int GetRangeCount();

            ColorRange* GetRange(
                unsigned int index);

        private:
            struct ColorTemplateOpaque* m_opaque;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___COLOR_TEMPLATE_H__