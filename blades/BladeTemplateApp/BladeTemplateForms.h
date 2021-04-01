///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __BLADETEMPLATEFORMS_H__
#define __BLADETEMPLATEFORMS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

namespace blade
{
	namespace blade_template
	{
		namespace app
		{
			
			///////////////////////////////////////////////////////////////////////////////
			/// Class MainPanelForm
			///////////////////////////////////////////////////////////////////////////////
			class MainPanelForm : public wxPanel 
			{
				private:
				
				protected:
					wxRichTextCtrl* m_RichTextCtrl;
				
				public:
					
					MainPanelForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
					~MainPanelForm();
				
			};
			
		} // namespace app
	} // namespace blade_template
} // namespace blade

#endif //__BLADETEMPLATEFORMS_H__
