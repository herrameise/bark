///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "LoggerForms.h"

///////////////////////////////////////////////////////////////////////////
using namespace bark::app;

LoggerPanelForm::LoggerPanelForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* m_MainSizer;
	m_MainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_RichTextCtrl = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxVSCROLL|wxHSCROLL|wxWANTS_CHARS|wxBORDER_NONE );
	m_RichTextCtrl->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	m_RichTextCtrl->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	m_MainSizer->Add( m_RichTextCtrl, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( m_MainSizer );
	this->Layout();
}

LoggerPanelForm::~LoggerPanelForm()
{
}
