///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"
#include "ToggleTooltipButton.h"
#include <wx/dcclient.h>


///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	dialogTexts = initDialogTexts();

	ResultImage = 0;
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxTIFFHandler);

	DCRAWstring = new wxString("dcraw.exe ");
	OptionsString = new wxString();
	PicturePathString = new wxString();

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	MenuBar = new wxMenuBar( 0 );
	Menu = new wxMenu();
	MenuBar->Append( Menu, wxT("Opcje") ); 
	openCatalogue = new wxMenuItem(Menu,MainFrame::ID_MENU_ITEM, "Otw�rz Katalog", "Wybierz katalog ze zdj�ciami RAW do konwersji");
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
	
	ResultPicturePanel = new wxScrolledCanvas( this, MainFrame::ID_CANVAS_SCROLL_WINDOW, wxDefaultPosition, wxSize( 1150,700 ), wxTAB_TRAVERSAL );
	ResultPicturePanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	
	
	HorizontalSizer->Add( ResultPicturePanel, 1, wxALL, 5 );
	
	wxBoxSizer* SideBarSizer;
	SideBarSizer = new wxBoxSizer( wxVERTICAL );
	
	SideBarSizer->SetMinSize( wxSize( 150,700 ) ); 
	SideBar = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxSize( 150,700 ), wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	SideBar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	SideBarSizer->Add( SideBar, 1, wxEXPAND | wxALL, 5 );

	HorizontalSizer->Add( SideBarSizer, 0, wxALIGN_BOTTOM|wxFIXED_MINSIZE, 0 );

	/* PRZYCISKI OPCJI */
	optionButtons = new ToggleTooltipButton*[15];
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
	optionButtons[14] = new ToggleTooltipButton(SideBar, ID_OPTION_BUTTON15, wxString("Get .tiff format of picture"), wxString("-T"), wxPoint(1, 420));

	ZoomButton = new wxToggleButton(SideBar,MainFrame::ID_ZOOM_BUTTON,_T("ZOOM"),wxPoint(1,570));
	ProcessButton = new wxButton(SideBar, MainFrame::ID_PROCESS_BUTTON, _T("PROCESS"),wxPoint(1,600));
	
	MainSizer->Add( HorizontalSizer, 0, 0, 5 );
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}


MainFrame::~MainFrame()
{
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

wxString* MainFrame::initDialogTexts() {
	wxString* result = new wxString[14];
	result[0] = "Podaj poziom ciemno�ci";
	result[1] = "Podaj obni�enie saturacji";
	result[2] = "Podaj pr�g szumu (optymalnie od 100 do 1000)";
	result[3] = "Podaj powi�kszenie poziomu warstw czerwonych i zielonych (optymalnie od 0.999 do 1.001)";
	result[5] = "Podaj wyj�ciow� przestrze� kolor�w (zgodnie z toolTip)";
	result[8] = "Podaj opcj� z toolTipa";
	result[11] = "Podaj dzielnik poziomu bieli (1.0 domy�lnie)";
	result[12] = "Podaj warto�� krzywej gamma";
	result[13] = "Podaj warto�� obr�cenia (zgodnie z opcjami na przycisku)";

	return result;
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

	// liczy ile jest plikow RAW w folderze
	// w kazdym momencie w folderze powinny znajdowac sie TYLKO pliki RAW + wygenerowane thumbnail JPG i wyniki TIFF
	int RAWfiles = 0;
	for (int i = 0; i < files->GetCount(); ++i) {
		if (files->Item(i).AfterLast(wxUniChar('.')) == "jpg" || 
			files->Item(i).AfterLast(wxUniChar('.')) == "tiff" ||
			files->Item(i).AfterLast(wxUniChar('.')) == "ppm") {
			continue;
		}
		RAWfiles++;
	}

	buttonsCount = RAWfiles;
	buttons = new wxBitmapToggleButton*[RAWfiles];
	buttonsDescr = new wxString[RAWfiles];

	int pos = 1, index = 0;
	for (int i = 0; i < files->GetCount(); ++i) {
		if (files->Item(i).AfterLast(wxUniChar('.')) == "jpg" ||
			files->Item(i).AfterLast(wxUniChar('.')) == "tiff" ||
			files->Item(i).AfterLast(wxUniChar('.')) == "ppm") {
			continue;
		}

		// dodanie sciezke do zdjecia z danego obrazu
		buttonsDescr[index] = files->Item(i);

		// tworzy thumbnail kazdego obrazu z wybranego folderu w formacie jpg
		wxString cmd("dcraw.exe -e ");
		wxShell(cmd.append(wxString("\"")).append(files->Item(i)).append("\""));

		// tworzy przycisk BitmapToggleButton z kazdego thumbnail i dodaje go do galerii	
		wxString thumbnail(files->Item(i).BeforeLast(wxUniChar('.')));
		thumbnail.append(".thumb.jpg");
		buttons[index] = new wxBitmapToggleButton(Gallery, wxID_ANY, wxBitmap(wxImage(thumbnail, wxBITMAP_TYPE_JPEG).Scale(150, 90)), wxPoint(pos, 1));
		
		pos += 159;
		index++;
	}
}

bool MainFrame::doFuncNeedDialog(wxCommandEvent& event) {
	int evtId = event.GetId();
	if (evtId == ID_OPTION_BUTTON1 ||
		evtId == ID_OPTION_BUTTON2 ||
		evtId == ID_OPTION_BUTTON3 ||
		evtId == ID_OPTION_BUTTON4 ||
		evtId == ID_OPTION_BUTTON6 ||
		evtId == ID_OPTION_BUTTON9 ||
		evtId == ID_OPTION_BUTTON12 ||
		evtId == ID_OPTION_BUTTON13 ||
		evtId == ID_OPTION_BUTTON14)
		return true;
	else return false;
}

wxString MainFrame::getOnlyOption(wxString string) {
	return string.BeforeFirst(wxUniChar(' '));
}

void MainFrame::handleOptionButton(wxCommandEvent& event) {
	bool doNeedDialog = doFuncNeedDialog(event);

	dialog = nullptr;
	userInput = new wxString();
	
		wxToggleButton* TestToggleButton = dynamic_cast<wxToggleButton*>(event.GetEventObject());
	if (doNeedDialog == false) {
		if (TestToggleButton->GetValue() == true) {
			OptionsString->Append(" ");
			OptionsString->Append(TestToggleButton->GetLabel());
			OptionsString->Append(" ");
		}
	}
	else {
		if (TestToggleButton->GetValue() == true) {
			OptionsString->Append(" ");
			OptionsString->Append(getOnlyOption(TestToggleButton->GetLabel()));
			OptionsString->Append(" ");
			dialog = new wxTextEntryDialog(this, dialogTexts[event.GetId()-10001]);
			dialog->ShowModal();

			*userInput = dialog->GetValue();	// w userInput jest to co uzytkownik wpisze w pop-up dialog
			OptionsString->append(*userInput);
			OptionsString->append(" ");
		}
	}
}

void MainFrame::processTask(wxCommandEvent& event) {
	try {
		DCRAWstring->Append(" ");
		DCRAWstring->Append(*OptionsString);
		DCRAWstring->Append(" ");

		PicturePathString->append("\"");
		PicturePathString->append(getPicturePath());
		PicturePathString->append("\"");

		DCRAWstring->Append(*PicturePathString);

		wxShell(*DCRAWstring);

		printTiffToResultPanel(PicturePathString);


		reset();

	}
	catch (wxString msg) {
		wxSafeShowMessage("Blad",msg);
	}
}

void MainFrame::reset() {
	delete(DCRAWstring);
	DCRAWstring = new wxString("dcraw.exe ");
	delete(OptionsString);
	OptionsString = new wxString();
	delete(PicturePathString);
	PicturePathString = new wxString();

	for (int i = 0; i < 15; i++) {
		optionButtons[i]->SetValue(false);
	}
	for (int i = 0; i < buttonsCount; i++) {
		buttons[i]->SetValue(false);
	}
}

wxString MainFrame::getPicturePath() {
	int buttonNumb = -1;
	for (int i = 0; i < buttonsCount; i++) {
		if (buttons[i]->GetValue() == true) {
			buttonNumb = i;
		}
	}
	if (buttonNumb == -1) {
		throw wxString("Nie wybrano obrazka.");
	}

	wxString result = buttonsDescr[buttonNumb];
	return result;
}


void MainFrame::printTiffToResultPanel(wxString* pathToResultPicture) {
	wxString TiffPicturePath = pathToResultPicture->BeforeLast(wxUniChar('.'));
	TiffPicturePath.append(".tiff\"");
	TiffPicturePath.Replace(wxString("\""), wxString(""));

	
	ResultImage = new wxImage(TiffPicturePath, wxBITMAP_TYPE_TIFF);
	
	int a, b;
	ResultPicturePanel->GetSize(&a, &b);

	*ResultImage = ResultImage->Scale(a,b);

	wxBitmap bmp(*ResultImage);

	wxClientDC dc(ResultPicturePanel);
	dc.DrawBitmap(bmp, 0,0,true);

	ResultPicturePanel->DoPrepareDC(dc);
}

void MainFrame::WxScrolledWindow1UpdateUI(wxUpdateUIEvent& event)
{
	if (ResultImage != 0) {
		wxBitmap bitmap(*ResultImage);           // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
		wxClientDC dc(ResultPicturePanel);   // Pobieramy kontekst okna
		ResultPicturePanel->DoPrepareDC(dc); // Musimy wywolac w przypadku wxScrolledWindow, zeby suwaki prawidlowo dzialaly
		dc.DrawBitmap(bitmap, 0, 0, true);  // Rysujemy bitmape na kontekscie urzadzenia
	}
}
	

void MainFrame::zoomButtonClicked(wxCommandEvent& event) {
	int a, b;
	ResultPicturePanel->GetSize(&a, &b);
	if (dynamic_cast<wxToggleButton*>(event.GetEventObject())->GetValue() == true) {
		if (ResultImage != nullptr) {
			*ResultImage = ResultImage->Scale(5 * a, 5 * b);

			ResultPicturePanel->SetScrollbars(25, 25, a / 5, b / 5);
		}
	}
	else {
		ResultPicturePanel->SetScrollbars(0, 0,0,0);

		*ResultImage = ResultImage->Scale(a, b);

		wxBitmap bmp(*ResultImage);

		wxClientDC dc(ResultPicturePanel);
		dc.DrawBitmap(bmp, 0, 0, true);

		ResultPicturePanel->DoPrepareDC(dc);
	}
}
