///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/dirdlg.h>
#include <wx/dir.h>
#include <wx/tglbtn.h>
#include <wx/stattext.h>
#include <wx/log.h>
//#include "ToggleTooltipButton.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	protected:
		wxMenuBar* MenuBar;
		wxMenu* Menu;
		wxMenuItem* openCatalogue;
		wxScrolledWindow* Gallery;
		wxPanel* ResultPicturePanel;
		wxScrolledWindow* SideBar;

		// przyciski galerii
		wxBitmapToggleButton** buttons;
		wxString* buttonsDescr;

		wxString* PathToRAW;

		wxStaticText* info;

		enum {
			ID_MENU_ITEM = 10000,
			ID_OPTION_BUTTON1 = 10001,
			ID_OPTION_BUTTON2 = 10002,
			ID_OPTION_BUTTON3 = 10003,
			ID_OPTION_BUTTON4 = 10004,
			ID_OPTION_BUTTON5 = 10005,
			ID_OPTION_BUTTON6 = 10006,
			ID_OPTION_BUTTON7 = 10007,
			ID_OPTION_BUTTON8 = 10008,
			ID_OPTION_BUTTON9 = 10009,
			ID_OPTION_BUTTON10 = 10010,
			ID_OPTION_BUTTON11 = 10011,
			ID_OPTION_BUTTON12 = 10012,
			ID_OPTION_BUTTON13 = 10013,
			ID_OPTION_BUTTON14 = 10014,
		};
	
	public:

		void showGalleryIcons(wxString PathToRaw);
		void chooseCatalog(wxCommandEvent& event);
		void handleOptionButton(wxCommandEvent& event);
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1263,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainFrame();

		DECLARE_EVENT_TABLE()
	
};



#endif //__NONAME_H__
