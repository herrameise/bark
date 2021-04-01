#ifndef __BLADE_APP___BLADE_TEMPLATE___MAIN_PANEL_H__
#define __BLADE_APP___BLADE_TEMPLATE___MAIN_PANEL_H__

#include "BladeTemplateForms.h"

#include <wx/string.h>
class wxWindow;



namespace blade
{
    namespace blade_template
    {
        namespace app
        {
            class MainPanel : public MainPanelForm
            {
            public:
                MainPanel(
                    wxWindow*   parent);

                ~MainPanel();

                void WriteMessage(
                    wxString string);
            };
        }
    }
}



#endif // __BLADE_APP___BLADE_TEMPLATE___MAIN_PANEL_H__