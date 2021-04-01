///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __EDITORFORMS_H__
#define __EDITORFORMS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
namespace bark{ namespace app{ class EditorTextCtrl; } }

#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/scrolbar.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////

namespace bark
{
	namespace app
	{
		#define WXID_PANEL_DATAINTERPRETER 1000
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class EditorPanelForm
		///////////////////////////////////////////////////////////////////////////////
		class EditorPanelForm : public wxPanel 
		{
			private:
			
			protected:
				wxPanel* m_ToolbarPanel;
				wxButton* m_SettingsButton;
				wxStaticLine* StaticLine1;
				wxStaticText* m_DisplayModeLabel;
				wxComboBox* m_DisplayModeComboBox;
				wxStaticLine* StaticLine2;
				wxCheckBox* m_ColorTemplateCheckBox;
				wxPanel* m_EditorPanel;
				wxStaticText* m_OffsetsHeader;
				wxRichTextCtrl* m_Offsets;
				wxStaticText* m_RawDataHeader;
				bark::app::EditorTextCtrl* m_RawData;
				wxStaticText* m_AsciiDataHeader;
				wxStaticText* m_ScrollbarHeader;
				wxScrollBar* m_Scrollbar;
			
			public:
				bark::app::EditorTextCtrl* m_AsciiData;
				
				EditorPanelForm( wxWindow* parent, wxWindowID id = WXID_PANEL_DATAINTERPRETER, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxFULL_REPAINT_ON_RESIZE|wxHSCROLL|wxTAB_TRAVERSAL ); 
				~EditorPanelForm();
			
		};
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class EditorSettingsDialogForm
		///////////////////////////////////////////////////////////////////////////////
		class EditorSettingsDialogForm : public wxDialog 
		{
			private:
			
			protected:
				wxPanel* m_SettingsPanel;
				wxComboBox* m_ComboBoxFontFaceName;
				wxComboBox* m_ComboBoxFontPointSize;
				wxRadioBox* m_RadioBoxCapitalization;
				wxButton* m_SaveButton;
				wxButton* m_CancelButton;
			
			public:
				
				EditorSettingsDialogForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Editor Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 588,204 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP ); 
				~EditorSettingsDialogForm();
			
		};
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class FillValueDialogForm
		///////////////////////////////////////////////////////////////////////////////
		class FillValueDialogForm : public wxDialog 
		{
			private:
			
			protected:
				wxStaticText* m_StaticTextByte;
				wxTextCtrl* m_TextCtrl;
				wxButton* m_ButtonOK;
				wxButton* m_ButtonCancel;
			
			public:
				
				FillValueDialogForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Fill Value"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 373,88 ), long style = wxDEFAULT_DIALOG_STYLE ); 
				~FillValueDialogForm();
			
		};
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class MaskValueDialogForm
		///////////////////////////////////////////////////////////////////////////////
		class MaskValueDialogForm : public wxDialog 
		{
			private:
			
			protected:
				wxStaticText* m_StaticTextByte;
				wxTextCtrl* m_TextCtrl;
				wxButton* m_ButtonOK;
				wxButton* m_ButtonCancel;
			
			public:
				
				MaskValueDialogForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("XOR Mask"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 373,88 ), long style = wxDEFAULT_DIALOG_STYLE ); 
				~MaskValueDialogForm();
			
		};
		
	} // namespace app
} // namespace bark

#endif //__EDITORFORMS_H__
