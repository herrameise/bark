#include "EditorSettings.h"
using namespace bark::app;

#include <wx/fontenum.h>



EditorSettings::EditorSettings()
{
    wxFontEnumerator fontenum;
    fontenum.EnumerateFacenames();
    wxArrayString all_facenames = fontenum.GetFacenames();

    for (size_t i = 0; i < all_facenames.GetCount(); i++)
    {
        wxFont font;
        font.SetFaceName(all_facenames[i]);
        if (font.IsFixedWidth()) facenames.Add(all_facenames[i]);
    }
}