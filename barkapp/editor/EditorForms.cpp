///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "EditorTextCtrl.h"

#include "EditorForms.h"

///////////////////////////////////////////////////////////////////////////
using namespace bark::app;

EditorPanelForm::EditorPanelForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* m_MainSizer;
	m_MainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_ToolbarPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_ToolbarSizer;
	m_ToolbarSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_SettingsButton = new wxButton( m_ToolbarPanel, wxID_ANY, wxT("Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ToolbarSizer->Add( m_SettingsButton, 0, wxALL|wxEXPAND, 5 );
	
	StaticLine1 = new wxStaticLine( m_ToolbarPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_ToolbarSizer->Add( StaticLine1, 0, wxEXPAND | wxALL, 5 );
	
	m_DisplayModeLabel = new wxStaticText( m_ToolbarPanel, wxID_ANY, wxT("Display Mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DisplayModeLabel->Wrap( -1 );
	m_ToolbarSizer->Add( m_DisplayModeLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_DisplayModeComboBox = new wxComboBox( m_ToolbarPanel, wxID_ANY, wxT("Bytes"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	m_DisplayModeComboBox->Append( wxT("Bytes") );
	m_DisplayModeComboBox->Append( wxT("Bits") );
	m_DisplayModeComboBox->SetSelection( 0 );
	m_ToolbarSizer->Add( m_DisplayModeComboBox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	StaticLine2 = new wxStaticLine( m_ToolbarPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_ToolbarSizer->Add( StaticLine2, 0, wxEXPAND | wxALL, 5 );
	
	m_ColorTemplateCheckBox = new wxCheckBox( m_ToolbarPanel, wxID_ANY, wxT("Show color templates"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ToolbarSizer->Add( m_ColorTemplateCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	m_ToolbarPanel->SetSizer( m_ToolbarSizer );
	m_ToolbarPanel->Layout();
	m_ToolbarSizer->Fit( m_ToolbarPanel );
	m_MainSizer->Add( m_ToolbarPanel, 0, wxEXPAND | wxALL, 0 );
	
	m_EditorPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_EditorSizer;
	m_EditorSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* m_OffsetsSizer;
	m_OffsetsSizer = new wxBoxSizer( wxVERTICAL );
	
	m_OffsetsHeader = new wxStaticText( m_EditorPanel, wxID_ANY, wxT("Off"), wxDefaultPosition, wxDefaultSize, 0 );
	m_OffsetsHeader->Wrap( -1 );
	m_OffsetsHeader->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	
	m_OffsetsSizer->Add( m_OffsetsHeader, 0, wxLEFT|wxRIGHT, 7 );
	
	m_Offsets = new wxRichTextCtrl( m_EditorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxFULL_REPAINT_ON_RESIZE|wxHSCROLL|wxSUNKEN_BORDER );
	m_Offsets->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	
	m_OffsetsSizer->Add( m_Offsets, 1, wxALL, 0 );
	
	
	m_EditorSizer->Add( m_OffsetsSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* m_RawDataSizer;
	m_RawDataSizer = new wxBoxSizer( wxVERTICAL );
	
	m_RawDataHeader = new wxStaticText( m_EditorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_RawDataHeader->Wrap( -1 );
	m_RawDataHeader->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	
	m_RawDataSizer->Add( m_RawDataHeader, 0, wxLEFT|wxRIGHT, 7 );
	
	m_RawData = new bark::app::EditorTextCtrl( m_EditorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxFULL_REPAINT_ON_RESIZE|wxSUNKEN_BORDER );
	m_RawData->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	m_RawDataSizer->Add( m_RawData, 1, wxALL, 0 );
	
	
	m_EditorSizer->Add( m_RawDataSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* m_AsciiDataSizer;
	m_AsciiDataSizer = new wxBoxSizer( wxVERTICAL );
	
	m_AsciiDataHeader = new wxStaticText( m_EditorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_AsciiDataHeader->Wrap( -1 );
	m_AsciiDataHeader->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Consolas") ) );
	
	m_AsciiDataSizer->Add( m_AsciiDataHeader, 0, wxLEFT|wxRIGHT, 7 );
	
	m_AsciiData = new bark::app::EditorTextCtrl( m_EditorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxFULL_REPAINT_ON_RESIZE|wxSUNKEN_BORDER );
	m_AsciiData->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	m_AsciiDataSizer->Add( m_AsciiData, 1, wxALL, 0 );
	
	
	m_EditorSizer->Add( m_AsciiDataSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* m_ScrollbarSizer;
	m_ScrollbarSizer = new wxBoxSizer( wxVERTICAL );
	
	m_ScrollbarHeader = new wxStaticText( m_EditorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_ScrollbarHeader->Wrap( -1 );
	m_ScrollbarHeader->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	
	m_ScrollbarSizer->Add( m_ScrollbarHeader, 0, wxLEFT|wxRIGHT, 7 );
	
	m_Scrollbar = new wxScrollBar( m_EditorPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_VERTICAL );
	m_ScrollbarSizer->Add( m_Scrollbar, 1, wxALL, 0 );
	
	
	m_EditorSizer->Add( m_ScrollbarSizer, 0, wxEXPAND, 5 );
	
	
	m_EditorPanel->SetSizer( m_EditorSizer );
	m_EditorPanel->Layout();
	m_EditorSizer->Fit( m_EditorPanel );
	m_MainSizer->Add( m_EditorPanel, 1, wxALL|wxEXPAND, 0 );
	
	
	this->SetSizer( m_MainSizer );
	this->Layout();
	m_MainSizer->Fit( this );
}

EditorPanelForm::~EditorPanelForm()
{
}

EditorSettingsDialogForm::EditorSettingsDialogForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_SettingsPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* SettingsSizer;
	SettingsSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* UpperSizer;
	UpperSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* FontSizer;
	FontSizer = new wxStaticBoxSizer( new wxStaticBox( m_SettingsPanel, wxID_ANY, wxT("Font") ), wxHORIZONTAL );
	
	m_ComboBoxFontFaceName = new wxComboBox( FontSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_SORT ); 
	FontSizer->Add( m_ComboBoxFontFaceName, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_ComboBoxFontPointSize = new wxComboBox( FontSizer->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	m_ComboBoxFontPointSize->Append( wxT("8") );
	m_ComboBoxFontPointSize->Append( wxT("9") );
	m_ComboBoxFontPointSize->Append( wxT("10") );
	m_ComboBoxFontPointSize->Append( wxT("11") );
	m_ComboBoxFontPointSize->Append( wxT("12") );
	m_ComboBoxFontPointSize->Append( wxT("14") );
	m_ComboBoxFontPointSize->Append( wxT("16") );
	m_ComboBoxFontPointSize->SetSelection( 2 );
	FontSizer->Add( m_ComboBoxFontPointSize, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	UpperSizer->Add( FontSizer, 1, wxEXPAND, 5 );
	
	wxString m_RadioBoxCapitalizationChoices[] = { wxT("0123456789abcdef"), wxT("0123456789ABCDEF") };
	int m_RadioBoxCapitalizationNChoices = sizeof( m_RadioBoxCapitalizationChoices ) / sizeof( wxString );
	m_RadioBoxCapitalization = new wxRadioBox( m_SettingsPanel, wxID_ANY, wxT("Capitalization"), wxDefaultPosition, wxDefaultSize, m_RadioBoxCapitalizationNChoices, m_RadioBoxCapitalizationChoices, 1, wxRA_SPECIFY_COLS );
	m_RadioBoxCapitalization->SetSelection( 1 );
	m_RadioBoxCapitalization->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	UpperSizer->Add( m_RadioBoxCapitalization, 1, wxALL|wxEXPAND, 5 );
	
	
	SettingsSizer->Add( UpperSizer, 1, wxEXPAND, 5 );
	
	
	SettingsSizer->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonsSizer;
	ButtonsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_SaveButton = new wxButton( m_SettingsPanel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonsSizer->Add( m_SaveButton, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CancelButton = new wxButton( m_SettingsPanel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonsSizer->Add( m_CancelButton, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	SettingsSizer->Add( ButtonsSizer, 1, wxEXPAND, 5 );
	
	
	m_SettingsPanel->SetSizer( SettingsSizer );
	m_SettingsPanel->Layout();
	SettingsSizer->Fit( m_SettingsPanel );
	MainSizer->Add( m_SettingsPanel, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

EditorSettingsDialogForm::~EditorSettingsDialogForm()
{
}

FillValueDialogForm::FillValueDialogForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_StaticTextByte = new wxStaticText( this, wxID_ANY, wxT("byte:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StaticTextByte->Wrap( -1 );
	MainSizer->Add( m_StaticTextByte, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_TextCtrl = new wxTextCtrl( this, wxID_ANY, wxT("56"), wxDefaultPosition, wxSize( 60,-1 ), wxTE_CENTRE );
	m_TextCtrl->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Courier New") ) );
	
	MainSizer->Add( m_TextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	MainSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonSizer;
	ButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_ButtonOK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( m_ButtonOK, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_ButtonCancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( m_ButtonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	MainSizer->Add( ButtonSizer, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

FillValueDialogForm::~FillValueDialogForm()
{
}

MaskValueDialogForm::MaskValueDialogForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_StaticTextByte = new wxStaticText( this, wxID_ANY, wxT("byte:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StaticTextByte->Wrap( -1 );
	MainSizer->Add( m_StaticTextByte, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_TextCtrl = new wxTextCtrl( this, wxID_ANY, wxT("56"), wxDefaultPosition, wxSize( 60,-1 ), wxTE_CENTRE );
	m_TextCtrl->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Courier New") ) );
	
	MainSizer->Add( m_TextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	MainSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonSizer;
	ButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_ButtonOK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( m_ButtonOK, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_ButtonCancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( m_ButtonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	MainSizer->Add( ButtonSizer, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MaskValueDialogForm::~MaskValueDialogForm()
{
}
