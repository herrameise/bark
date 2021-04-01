///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  4 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __VISUALIZERFORMS_H__
#define __VISUALIZERFORMS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/spinbutt.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/scrolbar.h>
#include <wx/clrpicker.h>
#include <wx/statbox.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

namespace bark
{
	namespace app
	{
		#define WXID_PANEL_VISUALIZER 1000
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class VisualizerPanelForm
		///////////////////////////////////////////////////////////////////////////////
		class VisualizerPanelForm : public wxPanel 
		{
			private:
			
			protected:
				wxPanel* m_ToolbarPanel;
				wxButton* m_ButtonSettings;
				wxStaticLine* StaticLine1;
				wxStaticText* StaticTextColumns;
				wxStaticText* m_StaticTextColumns;
				wxStaticLine* StaticLine2;
				wxStaticText* StaticTextZoom;
				wxSpinButton* m_SpinButtonZoom;
				wxPanel* m_MainPanel;
				wxPanel* m_Canvas;
				wxScrollBar* m_ScrollBar;
			
			public:
				
				VisualizerPanelForm( wxWindow* parent, wxWindowID id = WXID_PANEL_VISUALIZER, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxFULL_REPAINT_ON_RESIZE|wxTAB_TRAVERSAL ); 
				~VisualizerPanelForm();
			
		};
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class VisualizerSettingsDialogForm
		///////////////////////////////////////////////////////////////////////////////
		class VisualizerSettingsDialogForm : public wxDialog 
		{
			private:
			
			protected:
				wxPanel* m_SettingsPanel;
				wxStaticText* StaticTextNormalZero;
				wxColourPickerCtrl* m_ColorPickerNormalZero;
				wxStaticText* StaticTextNormalOne;
				wxColourPickerCtrl* m_ColorPickerNormalOne;
				wxStaticText* StaticTextSelectionZero;
				wxColourPickerCtrl* m_ColorPickerSelectionZero;
				wxStaticText* StaticTextSelectionOne;
				wxColourPickerCtrl* m_ColorPickerSelectionOne;
				wxSpinCtrl* m_SpinCtrlSnap;
				wxStaticText* StaticTextBits;
				wxCheckBox* m_CheckBoxSeparators;
				wxButton* m_ButtonDefaults;
				wxStaticLine* StaticLine;
				wxButton* m_ButtonSave;
				wxButton* m_ButtonCancel;
			
			public:
				
				VisualizerSettingsDialogForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Visualizer Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 455,294 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP ); 
				~VisualizerSettingsDialogForm();
			
		};
		
	} // namespace app
} // namespace bark

#endif //__VISUALIZERFORMS_H__
