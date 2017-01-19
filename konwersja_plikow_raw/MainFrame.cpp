///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	MenuBar = new wxMenuBar( 0 );
	Menu = new wxMenu();
	MenuBar->Append( Menu, wxT("Opcje") ); 
	openCatalogue = new wxMenuItem(Menu,MainFrame::ID_MENU_ITEM, "Otwórz Katalog", "Wybierz katalog ze zdjêciami RAW do konwersji");
	Menu->Append(openCatalogue);

	
	this->SetMenuBar( MenuBar );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	MainSizer->SetMinSize( wxSize( -1,100 ) ); 
	wxBoxSizer* GallerySizer;
	GallerySizer = new wxBoxSizer( wxVERTICAL );
	
	Gallery = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxSTATIC_BORDER|wxVSCROLL );
	Gallery->SetScrollRate( 5, 5 );
	Gallery->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	
	GallerySizer->Add( Gallery, 0, wxEXPAND, 5 );
	
	
	MainSizer->Add( GallerySizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* HorizontalSizer;
	HorizontalSizer = new wxBoxSizer( wxHORIZONTAL );
	
	ResultPicturePanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 1150,700 ), wxTAB_TRAVERSAL );
	ResultPicturePanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	
	HorizontalSizer->Add( ResultPicturePanel, 1, wxALL, 5 );
	
	wxBoxSizer* SideBarSizer;
	SideBarSizer = new wxBoxSizer( wxVERTICAL );
	
	SideBarSizer->SetMinSize( wxSize( 100,700 ) ); 
	SideBar = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 100,700 ), wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	SideBar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	
	SideBarSizer->Add( SideBar, 1, wxEXPAND | wxALL, 5 );
	
	
	HorizontalSizer->Add( SideBarSizer, 0, wxALIGN_BOTTOM|wxFIXED_MINSIZE, 0 );
	
	
	MainSizer->Add( HorizontalSizer, 0, 0, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );

	wxImage::AddHandler(new wxJPEGHandler);

	/*DEBUG*/
	info = new wxStaticText(ResultPicturePanel,wxID_ANY,wxString("info"));
}

MainFrame::~MainFrame()
{
}

void MainFrame::chooseCatalog(wxCommandEvent& event)
{
	wxDirDialog dirDialog(NULL, _T("Choose directory"), "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	dirDialog.SetPath(_T("D:"));

	//wxID_OK jesli uzytkownik wybral katalog i nacisnal ok.
	if (dirDialog.ShowModal() == wxID_OK) {
		PathToRAW = new wxString();
		*PathToRAW = dirDialog.GetPath();

		this->showGalleryIcons(*PathToRAW);
	}
	else {

	}
}

void MainFrame::showGalleryIcons(wxString PathToRAW)
{
	wxArrayString* files = new wxArrayString();
	wxDir::GetAllFiles(PathToRAW, files);

	wxBitmapToggleButton** buttons = new wxBitmapToggleButton*[files->GetCount()];

	int pos = 1;
	for (int i = 0; i < files->GetCount(); ++i) {
		if (files->Item(i).AfterLast(wxUniChar('.')) == "jpg") {
			continue;
		}

		// tworzy thumbnail kazdego obrazu z wybranego folderu w formacie jpg
		wxString cmd("dcraw.exe -e ");
		wxShell(cmd.append(wxString("\"")).append(files->Item(i)).append("\""));

		// tworzy przycisk BitmapToggleButton z kazdego thumbnail i dodaje go do galerii	
		wxString thumbnail(files->Item(i).BeforeLast(wxUniChar('.')));
		thumbnail.append(".thumb.jpg");
		buttons[i] = new wxBitmapToggleButton(Gallery, wxID_ANY, wxBitmap(wxImage(thumbnail, wxBITMAP_TYPE_JPEG).Scale(150, 90)), wxPoint(pos, 1));
		pos += 159;
	}
}
