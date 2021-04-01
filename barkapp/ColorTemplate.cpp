#include "ColorTemplate.h"
#include "ColorTemplateOpaque.h"
using namespace bark::app;



ColorTemplate::ColorTemplate()
{
    m_opaque = new struct ColorTemplateOpaque;
}


ColorTemplate::~ColorTemplate()
{
    m_opaque->ranges.clear();
    delete m_opaque;
}


void ColorTemplate::AddRange(
    uint64_t    start,
    uint64_t    stop,
    wxColor     text_color,
    wxColor     background_color)
{
    ColorRange range;

    range.start = start;
    range.stop = stop;
    range.text_color = text_color;
    range.background_color = background_color;

    m_opaque->ranges.push_back(range);
}


unsigned int ColorTemplate::GetRangeCount()
{
    return m_opaque->ranges.size();
}


ColorRange* ColorTemplate::GetRange(
    unsigned int index)
{
    return &m_opaque->ranges[index];
}