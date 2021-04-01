///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  4 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "VisualizerForms.h"

///////////////////////////////////////////////////////////////////////////
using namespace bark::app;

VisualizerPanelForm::VisualizerPanelForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* m_MainSizer;
	m_MainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_ToolbarPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_ToolbarSizer;
	m_ToolbarSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_ButtonSettings = new wxButton( m_ToolbarPanel, wxID_ANY, wxT("Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ToolbarSizer->Add( m_ButtonSettings, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	StaticLine1 = new wxStaticLine( m_ToolbarPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_ToolbarSizer->Add( StaticLine1, 0, wxEXPAND | wxALL, 5 );
	
	StaticTextColumns = new wxStaticText( m_ToolbarPanel, wxID_ANY, wxT("Cols:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTextColumns->Wrap( -1 );
	m_ToolbarSizer->Add( StaticTextColumns, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_StaticTextColumns = new wxStaticText( m_ToolbarPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StaticTextColumns->Wrap( -1 );
	m_ToolbarSizer->Add( m_StaticTextColumns, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	StaticLine2 = new wxStaticLine( m_ToolbarPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_ToolbarSizer->Add( StaticLine2, 0, wxEXPAND | wxALL, 5 );
	
	StaticTextZoom = new wxStaticText( m_ToolbarPanel, wxID_ANY, wxT("Zoom:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTextZoom->Wrap( -1 );
	m_ToolbarSizer->Add( StaticTextZoom, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_SpinButtonZoom = new wxSpinButton( m_ToolbarPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ToolbarSizer->Add( m_SpinButtonZoom, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	m_ToolbarPanel->SetSizer( m_ToolbarSizer );
	m_ToolbarPanel->Layout();
	m_ToolbarSizer->Fit( m_ToolbarPanel );
	m_MainSizer->Add( m_ToolbarPanel, 0, wxEXPAND | wxALL, 0 );
	
	m_MainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* CanvasSizer;
	CanvasSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* CanvasTopSizer;
	CanvasTopSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_Canvas = new wxPanel( m_MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTAB_TRAVERSAL );
	m_Canvas->SetBackgroundColour( wxColour( 255, 0, 0 ) );
	
	CanvasTopSizer->Add( m_Canvas, 1, wxALL|wxEXPAND, 5 );
	
	m_ScrollBar = new wxScrollBar( m_MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_VERTICAL );
	CanvasTopSizer->Add( m_ScrollBar, 0, wxALL|wxEXPAND, 5 );
	
	
	CanvasSizer->Add( CanvasTopSizer, 1, wxBOTTOM|wxEXPAND, 5 );
	
	
	m_MainPanel->SetSizer( CanvasSizer );
	m_MainPanel->Layout();
	CanvasSizer->Fit( m_MainPanel );
	m_MainSizer->Add( m_MainPanel, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( m_MainSizer );
	this->Layout();
	m_MainSizer->Fit( this );
}

VisualizerPanelForm::~VisualizerPanelForm()
{
}

VisualizerSettingsDialogForm::VisualizerSettingsDialogForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_SettingsPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* SettingsSizer;
	SettingsSizer = new wxBoxSizer( wxVERTICAL );
	
	
	SettingsSizer->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* ColorSizer;
	ColorSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* NormalSizer;
	NormalSizer = new wxStaticBoxSizer( new wxStaticBox( m_SettingsPanel, wxID_ANY, wxT("Normal") ), wxVERTICAL );
	
	wxFlexGridSizer* ColorSizerNormal;
	ColorSizerNormal = new wxFlexGridSizer( 2, 2, 0, 0 );
	ColorSizerNormal->AddGrowableCol( 1 );
	ColorSizerNormal->SetFlexibleDirection( wxBOTH );
	ColorSizerNormal->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	StaticTextNormalZero = new wxStaticText( NormalSizer->GetStaticBox(), wxID_ANY, wxT("Binary \"0\""), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTextNormalZero->Wrap( -1 );
	ColorSizerNormal->Add( StaticTextNormalZero, 0, wxALL, 5 );
	
	m_ColorPickerNormalZero = new wxColourPickerCtrl( NormalSizer->GetStaticBox(), wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	ColorSizerNormal->Add( m_ColorPickerNormalZero, 0, wxALL|wxEXPAND, 5 );
	
	StaticTextNormalOne = new wxStaticText( NormalSizer->GetStaticBox(), wxID_ANY, wxT("Binary \"1\""), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTextNormalOne->Wrap( -1 );
	ColorSizerNormal->Add( StaticTextNormalOne, 0, wxALL, 5 );
	
	m_ColorPickerNormalOne = new wxColourPickerCtrl( NormalSizer->GetStaticBox(), wxID_ANY, wxColour( 0, 0, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	ColorSizerNormal->Add( m_ColorPickerNormalOne, 0, wxALL|wxEXPAND, 5 );
	
	
	NormalSizer->Add( ColorSizerNormal, 1, wxEXPAND, 5 );
	
	
	ColorSizer->Add( NormalSizer, 1, wxEXPAND, 5 );
	
	
	ColorSizer->Add( 10, 0, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* SelectionSizer;
	SelectionSizer = new wxStaticBoxSizer( new wxStaticBox( m_SettingsPanel, wxID_ANY, wxT("Selection") ), wxVERTICAL );
	
	wxFlexGridSizer* ColorSizerSelection;
	ColorSizerSelection = new wxFlexGridSizer( 2, 2, 0, 0 );
	ColorSizerSelection->AddGrowableCol( 1 );
	ColorSizerSelection->SetFlexibleDirection( wxBOTH );
	ColorSizerSelection->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	StaticTextSelectionZero = new wxStaticText( SelectionSizer->GetStaticBox(), wxID_ANY, wxT("Binary \"0\""), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTextSelectionZero->Wrap( -1 );
	ColorSizerSelection->Add( StaticTextSelectionZero, 0, wxALL, 5 );
	
	m_ColorPickerSelectionZero = new wxColourPickerCtrl( SelectionSizer->GetStaticBox(), wxID_ANY, wxColour( 255, 255, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	ColorSizerSelection->Add( m_ColorPickerSelectionZero, 0, wxALL|wxEXPAND, 5 );
	
	StaticTextSelectionOne = new wxStaticText( SelectionSizer->GetStaticBox(), wxID_ANY, wxT("Binary \"1\""), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTextSelectionOne->Wrap( -1 );
	ColorSizerSelection->Add( StaticTextSelectionOne, 0, wxALL, 5 );
	
	m_ColorPickerSelectionOne = new wxColourPickerCtrl( SelectionSizer->GetStaticBox(), wxID_ANY, wxColour( 0, 128, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	ColorSizerSelection->Add( m_ColorPickerSelectionOne, 0, wxALL|wxEXPAND, 5 );
	
	
	SelectionSizer->Add( ColorSizerSelection, 1, wxEXPAND, 5 );
	
	
	ColorSizer->Add( SelectionSizer, 1, wxEXPAND, 5 );
	
	
	SettingsSizer->Add( ColorSizer, 0, wxEXPAND, 5 );
	
	
	SettingsSizer->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* SnapSizer;
	SnapSizer = new wxStaticBoxSizer( new wxStaticBox( m_SettingsPanel, wxID_ANY, wxT("Snap") ), wxHORIZONTAL );
	
	m_SpinCtrlSnap = new wxSpinCtrl( SnapSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	SnapSizer->Add( m_SpinCtrlSnap, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	StaticTextBits = new wxStaticText( SnapSizer->GetStaticBox(), wxID_ANY, wxT("bits"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTextBits->Wrap( -1 );
	SnapSizer->Add( StaticTextBits, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	SnapSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_CheckBoxSeparators = new wxCheckBox( SnapSizer->GetStaticBox(), wxID_ANY, wxT("Show separators"), wxDefaultPosition, wxDefaultSize, 0 );
	SnapSizer->Add( m_CheckBoxSeparators, 0, wxALL, 5 );
	
	
	SettingsSizer->Add( SnapSizer, 1, wxEXPAND, 5 );
	
	
	SettingsSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonsSizer;
	ButtonsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_ButtonDefaults = new wxButton( m_SettingsPanel, wxID_ANY, wxT("Defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonsSizer->Add( m_ButtonDefaults, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	StaticLine = new wxStaticLine( m_SettingsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	ButtonsSizer->Add( StaticLine, 0, wxEXPAND | wxALL, 5 );
	
	m_ButtonSave = new wxButton( m_SettingsPanel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonsSizer->Add( m_ButtonSave, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_ButtonCancel = new wxButton( m_SettingsPanel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonsSizer->Add( m_ButtonCancel, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	SettingsSizer->Add( ButtonsSizer, 0, wxEXPAND, 5 );
	
	
	m_SettingsPanel->SetSizer( SettingsSizer );
	m_SettingsPanel->Layout();
	SettingsSizer->Fit( m_SettingsPanel );
	MainSizer->Add( m_SettingsPanel, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

VisualizerSettingsDialogForm::~VisualizerSettingsDialogForm()
{
}
