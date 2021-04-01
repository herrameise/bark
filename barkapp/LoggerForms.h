///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __LOGGERFORMS_H__
#define __LOGGERFORMS_H__

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

namespace bark
{
	namespace app
	{
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class LoggerPanelForm
		///////////////////////////////////////////////////////////////////////////////
		class LoggerPanelForm : public wxPanel 
		{
			private:
			
			protected:
				wxRichTextCtrl* m_RichTextCtrl;
			
			public:
				
				LoggerPanelForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString ); 
				~LoggerPanelForm();
			
		};
		
	} // namespace app
} // namespace bark

#endif //__LOGGERFORMS_H__
