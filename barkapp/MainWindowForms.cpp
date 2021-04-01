///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainWindowForms.h"

///////////////////////////////////////////////////////////////////////////
using namespace bark::app;

MainWindowForm::MainWindowForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_ALLOW_FLOATING|wxAUI_MGR_TRANSPARENT_HINT);
	
	m_MenuBar = new wxMenuBar( 0 );
	m_MenuFile = new wxMenu();
	wxMenuItem* m_MenuFileLoadSpecimen;
	m_MenuFileLoadSpecimen = new wxMenuItem( m_MenuFile, WXID_MENU_FILE_LOADSPECIMEN, wxString( wxT("Load Specimen") ) , wxEmptyString, wxITEM_NORMAL );
	m_MenuFile->Append( m_MenuFileLoadSpecimen );
	
	wxMenuItem* m_MenuFileExit;
	m_MenuFileExit = new wxMenuItem( m_MenuFile, WXID_MENU_FILE_EXIT, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_MenuFile->Append( m_MenuFileExit );
	
	m_MenuBar->Append( m_MenuFile, wxT("File") ); 
	
	m_MenuBlades = new wxMenu();
	wxMenuItem* wxMenuBladesDeploy;
	wxMenuBladesDeploy = new wxMenuItem( m_MenuBlades, WXID_BLADES_DEPLOY, wxString( wxT("Deploy ...") ) , wxEmptyString, wxITEM_NORMAL );
	m_MenuBlades->Append( wxMenuBladesDeploy );
	
	m_MenuBar->Append( m_MenuBlades, wxT("Blades") ); 
	
	m_MenuHelp = new wxMenu();
	wxMenuItem* m_MenuHelpAbout;
	m_MenuHelpAbout = new wxMenuItem( m_MenuHelp, WXID_MENU_HELP_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_MenuHelp->Append( m_MenuHelpAbout );
	
	m_MenuBar->Append( m_MenuHelp, wxT("Help") ); 
	
	this->SetMenuBar( m_MenuBar );
	
	m_StatusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, WXID_STATUSBAR );
	
	m_mgr.Update();
	this->Centre( wxBOTH );
	
	// Connect Events
	m_MenuFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowForm::OnMenuFileLoadSpecimen ), this, m_MenuFileLoadSpecimen->GetId());
	m_MenuFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowForm::OnMenuFileExit ), this, m_MenuFileExit->GetId());
	m_MenuBlades->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowForm::OnMenuBladesDeploy ), this, wxMenuBladesDeploy->GetId());
	m_MenuHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowForm::OnMenuHelpAbout ), this, m_MenuHelpAbout->GetId());
}

MainWindowForm::~MainWindowForm()
{
	// Disconnect Events
	
	m_mgr.UnInit();
	
}
