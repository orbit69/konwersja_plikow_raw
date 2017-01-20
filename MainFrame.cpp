///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"
#include "ToggleTooltipButton.h"
//#include "CustomDialog.h"


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
	SideBar = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxSize( 150,700 ), wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	SideBar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	SideBarSizer->Add( SideBar, 1, wxEXPAND | wxALL, 5 );
	HorizontalSizer->Add( SideBarSizer, 0, wxALIGN_BOTTOM|wxFIXED_MINSIZE, 0 );

	/* PRZYCISKI OPCJI */
	ToggleTooltipButton* optionButtons[14];
	optionButtons[0] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON1, wxString("When shadows appear foggy, you need to raise the darkness level."), wxString("-k darkness"), wxPoint(1, 1));
	optionButtons[1] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON2, wxString("When highlights appear pink, you need to lower the saturation level."), wxString("-s saturation"), wxPoint(1, 30));
	optionButtons[2] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON3, wxString("Use wavelets to erase noise while preserving real detail. The best threshold should be somewhere between 100 and 1000."), wxString("-n noise_threshold"), wxPoint(1, 60));
	optionButtons[3] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON4, wxString("Enlarge the raw red and blue layers by the given factors, typically 0.999 to 1.001, to correct chromatic aberration."), wxString("-c red_mag blue_mag"), wxPoint(1, 90));
	optionButtons[4] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON5, wxString("Calculate the white balance by averaging the entire image."), wxString("-a"), wxPoint(1, 120));
	optionButtons[5] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON6, wxString("Select the output colorspace when the -p option is not used:\n0   Raw color(unique to each camera)\n1   sRGB D65(default)\n2   Adobe RGB(1998) D65\n3   Wide Gamut RGB D65\n4   Kodak ProPhoto RGB D65\n5   XYZ\n6   ACES"), wxString("-o [0-6]"), wxPoint(1, 150));
	optionButtons[6] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON7, wxString("Show the raw data as a grayscale image with no interpolation. Good for photographing black-and-white documents."), wxString("-d"), wxPoint(1, 180));
	optionButtons[7] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON8, wxString("Output a half-size color image."), wxString("-h"), wxPoint(1, 210));
	optionButtons[8] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON9, wxString("0  Use high-speed, low-quality bilinear interpolation.\n1  Use Variable Number of Gradients (VNG) interpolation.\n2  Use Patterned Pixel Grouping (PPG) interpolation.\n3  Use Adaptive Homogeneity-Directed (AHD) interpolation."), wxString("-q [0-3]"), wxPoint(1, 240));
	optionButtons[9] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON10, wxString("Interpolate RGB as four colors. Use this if the output shows false 2x2 meshes with VNG or mazes with AHD."), wxString("-f"), wxPoint(1, 270));
	optionButtons[10] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON11, wxString("Use a fixed white level, ignoring the image histogram."), wxString("-W"), wxPoint(1, 300));
	optionButtons[11] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON12, wxString("Divide the white level by this number, 1.0 by default."), wxString("-b brightness"), wxPoint(1, 330));
	optionButtons[12] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON13, wxString("Set the gamma curve, by default BT.709 (-g 2.222 4.5). If you prefer sRGB gamma, use -g 2.4 12.92. For a simple power curve, set the toe slope to zero."), wxString("-g power toe_slope"), wxPoint(1, 360));
	optionButtons[13] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON14, wxString("Flip the output image. By default, dcraw applies the flip specified by the camera. -t 0 disables all flipping."), wxString("-t [0-7,90,180,270]"), wxPoint(1, 390));
	
	
	MainSizer->Add( HorizontalSizer, 0, 0, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );

	wxImage::AddHandler(new wxJPEGHandler);
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

	buttons = new wxBitmapToggleButton*[files->GetCount()];
	buttonsDescr = new wxString[files->GetCount()];

	int pos = 1;
	for (int i = 0; i < files->GetCount(); ++i) {
		if (files->Item(i).AfterLast(wxUniChar('.')) == "jpg") {
			continue;
		}

		// dodanie sciezke do zdjecia z danego obrazu
		buttonsDescr[i] = files->Item(i);

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

/*DEBUG*/
void reverse(unsigned char *str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}
int intToStr(int x, unsigned char str[], int d)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

void MainFrame::handleOptionButton(wxCommandEvent& event) {
	dialog = nullptr;
	userInput = new wxString();

	switch (event.GetId()) {
	case 10001:
		dialog = new wxTextEntryDialog(this, wxString("Tutaj jakas informacja jaki ma byc input"));
		dialog->ShowModal();

		*userInput = dialog->GetValue();	// w userInput jest to co uzytkownik wpisze w pop-up dialog
		break;
	case 10002:

		break;
	case 10003:

		break;
	case 10004:

		break;
	case 10005:

		break;
	case 10006:

		break;
	case 10007:

		break;
	case 10008:

		break;
	case 10009:

		break;
	case 10010:

		break;
	case 10011:

		break;
	case 10012:

		break;
	case 10013:

		break;
	case 10014:

		break;
	}
}