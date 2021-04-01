///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BladeEntriesListCtrl.h"

#include "ManagerForms.h"

///////////////////////////////////////////////////////////////////////////
using namespace bark::app;

DeployBladeDialogForm::DeployBladeDialogForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* TopSizer;
	TopSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_AvailableBladesLabel = new wxStaticText( this, wxID_ANY, wxT("Available Blades"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_AvailableBladesLabel->Wrap( -1 );
	m_AvailableBladesLabel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	TopSizer->Add( m_AvailableBladesLabel, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	MainSizer->Add( TopSizer, 0, wxEXPAND, 5 );
	
	m_BladeEntriesListCtrl = new bark::app::BladeEntriesListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VIRTUAL|wxLC_VRULES );
	MainSizer->Add( m_BladeEntriesListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* BottomSizer;
	BottomSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_ButtonDeploy = new wxButton( this, wxID_ANY, wxT("Deploy"), wxDefaultPosition, wxDefaultSize, 0 );
	BottomSizer->Add( m_ButtonDeploy, 1, wxALL, 5 );
	
	m_ButtonClose = new wxButton( this, wxID_ANY, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	BottomSizer->Add( m_ButtonClose, 0, wxALL, 5 );
	
	
	MainSizer->Add( BottomSizer, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_ButtonDeploy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeployBladeDialogForm::OnButtonDeploy ), NULL, this );
	m_ButtonClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeployBladeDialogForm::OnButtonClose ), NULL, this );
}

DeployBladeDialogForm::~DeployBladeDialogForm()
{
	// Disconnect Events
	m_ButtonDeploy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeployBladeDialogForm::OnButtonDeploy ), NULL, this );
	m_ButtonClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeployBladeDialogForm::OnButtonClose ), NULL, this );
	
}
