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
#include <wx/textctrl.h>
#include <wx/textdlg.h>
#include "ToggleTooltipButton.h"
#include <wx/button.h>

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

		
		wxScrolledWindow* SideBar;

		// przyciski galerii
		int buttonsCount;
		wxBitmapToggleButton** buttons;
		wxString* buttonsDescr;


		// pop-up dialog
		wxTextEntryDialog* dialog;
		wxString* userInput;

		//sideBar
		ToggleTooltipButton** optionButtons;

		wxScrolledCanvas* ResultPicturePanel;

		wxString* PathToRAW;

		wxImage* ResultImage;
		wxImage* ResultImageCopy;



		wxString* DCRAWstring;
		wxString* OptionsString;
		wxString* PicturePathString;

		wxButton* ProcessButton;
		wxToggleButton* ZoomButton;

		




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
			ID_OPTION_BUTTON15 = 10018,
			ID_PROCESS_BUTTON = 10016,
			ID_CANVAS_SCROLL_WINDOW = 10017,
			ID_ZOOM_BUTTON = 10019

		};
	
	public:

		wxString getOnlyOption(wxString);
		void showGalleryIcons(wxString PathToRaw);
		void processTask(wxCommandEvent& event);
		void zoomButtonClicked(wxCommandEvent& event);


		
		void WxScrolledWindow1UpdateUI(wxUpdateUIEvent& event);
		void showGalleryIcons();
		



		void chooseCatalog(wxCommandEvent& event);
		void handleOptionButton(wxCommandEvent& event);
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1263,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainFrame();

		DECLARE_EVENT_TABLE()

private:
	void printTiffToResultPanel(wxString*);
	wxString getPicturePath();
	void reset();
	bool doFuncNeedDialog(wxCommandEvent& event);
	wxString* initDialogTexts();

private:
	wxString* dialogTexts;

	
};



#endif //__NONAME_H__
