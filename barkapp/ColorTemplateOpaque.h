#ifndef __BARK_APP___COLOR_TEMPLATE_OPAQUE_H__
#define __BARK_APP___COLOR_TEMPLATE_OPAQUE_H__

#include <vector>
using namespace std;

#include "ColorTemplate.h"



namespace bark
{
    namespace app
    {
        typedef struct ColorTemplateOpaque
        {
            vector<ColorRange> ranges;
        } ColorTemplateOpaque;

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___COLOR_TEMPLATE_OPAQUE_H__