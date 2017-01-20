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
#include <wx/button.h>
#include <wx/tglbtn.h>

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
		wxScrolledCanvas* ResultPicturePanel;
		wxPanel* SideBar;

		wxString* PathToRAW;

		wxImage* ResultImage;


		wxStaticText* info;

		wxString* DCRAWstring;
		wxString* OptionsString;
		wxString* PicturePathString;

		wxButton* ProcessButton;
		wxButton* ZoomButton;

		wxToggleButton* TestToggleButton;




		enum {
			ID_MENU_ITEM = 10000,
			ID_PROCESS_BUTTON = 10001,
			ID_TEST_TOGGLE_BUTTON = 10002,
			ID_CANVAS_SCROLL_WINDOW = 10003
		};
	
	public:


		void showGalleryIcons(wxString PathToRaw);

		void testProcessing(wxCommandEvent& event);
		void WxScrolledWindow1UpdateUI(wxUpdateUIEvent& event);
		void showGalleryIcons();
		void processTask(wxCommandEvent& event);


		void chooseCatalog(wxCommandEvent& event);
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1263,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainFrame();

		DECLARE_EVENT_TABLE()

private:
	void printTiffToResultPanel(wxString*);
	
};



#endif //__NONAME_H__
