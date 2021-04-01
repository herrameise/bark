///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MANAGERFORMS_H__
#define __MANAGERFORMS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
namespace bark{ namespace app{ class BladeEntriesListCtrl; } }

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

namespace bark
{
	namespace app
	{
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class DeployBladeDialogForm
		///////////////////////////////////////////////////////////////////////////////
		class DeployBladeDialogForm : public wxDialog 
		{
			private:
			
			protected:
				wxStaticText* m_AvailableBladesLabel;
				bark::app::BladeEntriesListCtrl* m_BladeEntriesListCtrl;
				wxButton* m_ButtonDeploy;
				wxButton* m_ButtonClose;
				
				// Virtual event handlers, overide them in your derived class
				virtual void OnButtonDeploy( wxCommandEvent& event ) { event.Skip(); }
				virtual void OnButtonClose( wxCommandEvent& event ) { event.Skip(); }
				
			
			public:
				
				DeployBladeDialogForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Deploy Blade"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 743,364 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
				~DeployBladeDialogForm();
			
		};
		
	} // namespace app
} // namespace bark

#endif //__MANAGERFORMS_H__
