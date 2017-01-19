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
END_EVENT_TABLE()

bool MainApp::OnInit()
{
	wxFrame* Frame = new MainFrame(NULL);
	Frame->Show(TRUE);

	return TRUE;
}
	