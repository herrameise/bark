///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BladeTemplateForms.h"

///////////////////////////////////////////////////////////////////////////
using namespace blade::blade_template::app;

MainPanelForm::MainPanelForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_RichTextCtrl = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	MainSizer->Add( m_RichTextCtrl, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
}

MainPanelForm::~MainPanelForm()
{
}
