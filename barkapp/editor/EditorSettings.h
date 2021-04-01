#ifndef __BARK_APP___EDITOR_SETTINGS_H__
#define __BARK_APP___EDITOR_SETTINGS_H__

#include <wx/arrstr.h>
#include <wx/font.h>
#include <wx/richtext/richtextctrl.h>



namespace bark
{
    namespace app
    {
        class EditorSettings
        {
        public:
            EditorSettings();

            wxFont          font;
            bool            capital_hex;

            wxArrayString   facenames;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___EDITOR_SETTINGS_H__