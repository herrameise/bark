///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINWINDOWFORMS_H__
#define __MAINWINDOWFORMS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>

///////////////////////////////////////////////////////////////////////////

namespace bark
{
	namespace app
	{
		#define WXID_MAINWINDOW 1000
		#define WXID_MENUBAR 1001
		#define WXID_MENU_FILE_LOADSPECIMEN 1002
		#define WXID_MENU_FILE_EXIT 1003
		#define WXID_BLADES_DEPLOY 1004
		#define WXID_MENU_HELP_ABOUT 1005
		#define WXID_STATUSBAR 1006
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class MainWindowForm
		///////////////////////////////////////////////////////////////////////////////
		class MainWindowForm : public wxFrame 
		{
			private:
			
			protected:
				wxMenuBar* m_MenuBar;
				wxMenu* m_MenuFile;
				wxMenu* m_MenuBlades;
				wxMenu* m_MenuHelp;
				
				// Virtual event handlers, overide them in your derived class
				virtual void OnMenuFileLoadSpecimen( wxCommandEvent& event ) { event.Skip(); }
				virtual void OnMenuFileExit( wxCommandEvent& event ) { event.Skip(); }
				virtual void OnMenuBladesDeploy( wxCommandEvent& event ) { event.Skip(); }
				virtual void OnMenuHelpAbout( wxCommandEvent& event ) { event.Skip(); }
				
			
			public:
				wxStatusBar* m_StatusBar;
				
				MainWindowForm( wxWindow* parent, wxWindowID id = WXID_MAINWINDOW, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 852,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
				wxAuiManager m_mgr;
				
				~MainWindowForm();
			
		};
		
	} // namespace app
} // namespace bark

#endif //__MAINWINDOWFORMS_H__
