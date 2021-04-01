#include <wx/wx.h>

#include "MainWindow.h"
using namespace bark::app;



class BarkApp : public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;
};



#ifdef _DEBUG
wxIMPLEMENT_APP_CONSOLE(BarkApp);
#else // (release)
wxIMPLEMENT_APP(BarkApp);
#endif // _DEBUG



bool BarkApp::OnInit()
{
	if (!wxApp::OnInit()) return false;

    MainWindow* mainwindow = new MainWindow();
    mainwindow->Show(true);

    return true;
}