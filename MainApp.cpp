#include <wx/wxprec.h>
#include <wx/wx.h>
#include "MainFrame.h"

class MainApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MainApp);

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_MENU(MainFrame::ID_MENU_ITEM,MainFrame::chooseCatalog)

	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON1, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON2, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON3, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON4, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON5, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON6, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON7, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON8, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON9, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON10, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON11, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON12, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON13, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON14, MainFrame::handleOptionButton)
	EVT_TOGGLEBUTTON(MainFrame::ID_OPTION_BUTTON15, MainFrame::handleOptionButton)

	EVT_BUTTON(MainFrame::ID_PROCESS_BUTTON,MainFrame::processTask)
	EVT_BUTTON(MainFrame::ID_ZOOM_BUTTON,MainFrame::zoomButtonClicked)
	
	EVT_UPDATE_UI(ID_CANVAS_SCROLL_WINDOW, MainFrame::WxScrolledWindow1UpdateUI)
END_EVENT_TABLE()

bool MainApp::OnInit()
{
	wxFrame* Frame = new MainFrame(NULL);
	Frame->Show(TRUE);

	return TRUE;
}
	