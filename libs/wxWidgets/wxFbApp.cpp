///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxFbApp.h"

///////////////////////////////////////////////////////////////////////////

MainWindowV::MainWindowV( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1280,720 ), wxSize( 1920,1080 ) );
	this->DragAcceptFiles( true );

	MainMenubar = new wxMenuBar( 0 );
	FileMenu = new wxMenu();
	wxMenuItem* FileMenuOpen;
	FileMenuOpen = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Open") ) + wxT('\t') + wxT("ctrl+o"), wxT("CTRL + O"), wxITEM_NORMAL );
	FileMenu->Append( FileMenuOpen );

	wxMenuItem* FileMenuSave;
	FileMenuSave = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("ctrl+s"), wxT("CTRL + S"), wxITEM_NORMAL );
	FileMenu->Append( FileMenuSave );

	MainMenubar->Append( FileMenu, wxT("File") );

	FiltersMenu = new wxMenu();
	WatermarksM = new wxMenu();
	wxMenuItem* WatermarksMItem = new wxMenuItem( FiltersMenu, wxID_ANY, wxT("Remove Watermark"), wxEmptyString, wxITEM_NORMAL, WatermarksM );
	wxMenuItem* WatermarkRB;
	WatermarkRB = new wxMenuItem( WatermarksM, wxID_ANY, wxString( wxT("Red watermark (Bad)") ) , wxEmptyString, wxITEM_NORMAL );
	WatermarksM->Append( WatermarkRB );

	wxMenuItem* WatermarkBWM;
	WatermarkBWM = new wxMenuItem( WatermarksM, wxID_ANY, wxString( wxT("B&W Image Color Watermark (Good)") ) , wxEmptyString, wxITEM_NORMAL );
	WatermarksM->Append( WatermarkBWM );

	FiltersMenu->Append( WatermarksMItem );

	ChannelsM = new wxMenu();
	wxMenuItem* ChannelsMItem = new wxMenuItem( FiltersMenu, wxID_ANY, wxT("Channels"), wxEmptyString, wxITEM_NORMAL, ChannelsM );
	wxMenuItem* ChannelR;
	ChannelR = new wxMenuItem( ChannelsM, wxID_ANY, wxString( wxT("Red") ) , wxEmptyString, wxITEM_NORMAL );
	ChannelsM->Append( ChannelR );

	wxMenuItem* ChannelG;
	ChannelG = new wxMenuItem( ChannelsM, wxID_ANY, wxString( wxT("Green") ) , wxEmptyString, wxITEM_NORMAL );
	ChannelsM->Append( ChannelG );

	wxMenuItem* ChannelB;
	ChannelB = new wxMenuItem( ChannelsM, wxID_ANY, wxString( wxT("Blue") ) , wxEmptyString, wxITEM_NORMAL );
	ChannelsM->Append( ChannelB );

	wxMenuItem* ChannelA;
	ChannelA = new wxMenuItem( ChannelsM, wxID_ANY, wxString( wxT("Alpha") ) , wxEmptyString, wxITEM_NORMAL );
	ChannelsM->Append( ChannelA );

	wxMenuItem* ChannelRGBA;
	ChannelRGBA = new wxMenuItem( ChannelsM, wxID_ANY, wxString( wxT("RGB") ) , wxEmptyString, wxITEM_NORMAL );
	ChannelsM->Append( ChannelRGBA );

	FiltersMenu->Append( ChannelsMItem );

	GrayscaleM = new wxMenu();
	wxMenuItem* GrayscaleMItem = new wxMenuItem( FiltersMenu, wxID_ANY, wxT("Grayscale"), wxEmptyString, wxITEM_NORMAL, GrayscaleM );
	wxMenuItem* GrayscaleAvg;
	GrayscaleAvg = new wxMenuItem( GrayscaleM, wxID_ANY, wxString( wxT("Average") ) , wxEmptyString, wxITEM_NORMAL );
	GrayscaleM->Append( GrayscaleAvg );

	wxMenuItem* GrayscalePercep;
	GrayscalePercep = new wxMenuItem( GrayscaleM, wxID_ANY, wxString( wxT("Perceptual") ) , wxEmptyString, wxITEM_NORMAL );
	GrayscaleM->Append( GrayscalePercep );

	FiltersMenu->Append( GrayscaleMItem );

	wxMenuItem* MosaicM;
	MosaicM = new wxMenuItem( FiltersMenu, wxID_ANY, wxString( wxT("Mosaic") ) , wxEmptyString, wxITEM_NORMAL );
	FiltersMenu->Append( MosaicM );

	MainMenubar->Append( FiltersMenu, wxT("Filters") );

	this->SetMenuBar( MainMenubar );

	wxBoxSizer* MainBSizer;
	MainBSizer = new wxBoxSizer( wxVERTICAL );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	MainBSizer->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxGridSizer* ContentGrid;
	ContentGrid = new wxGridSizer( 1, 2, 0, 20 );

	LeftPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* LeftPanelHSizer;
	LeftPanelHSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* LeftPanelVSizer;
	LeftPanelVSizer = new wxBoxSizer( wxVERTICAL );

	LeftPanelVSizer->SetMinSize( wxSize( -1,1000 ) );
	OgImg = new wxStaticBitmap( LeftPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	OgImg->SetMinSize( wxSize( -1,1000 ) );

	LeftPanelVSizer->Add( OgImg, 0, wxEXPAND, 5 );


	LeftPanelHSizer->Add( LeftPanelVSizer, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	LeftPanel->SetSizer( LeftPanelHSizer );
	LeftPanel->Layout();
	LeftPanelHSizer->Fit( LeftPanel );
	ContentGrid->Add( LeftPanel, 0, wxALL|wxEXPAND, 5 );

	RightPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* RightPanelHSizer;
	RightPanelHSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* RightPanelVSizer;
	RightPanelVSizer = new wxBoxSizer( wxVERTICAL );

	RightPanelVSizer->SetMinSize( wxSize( -1,1000 ) );
	ModImg = new wxStaticBitmap( RightPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ModImg->SetMinSize( wxSize( -1,1000 ) );

	RightPanelVSizer->Add( ModImg, 0, wxEXPAND, 5 );


	RightPanelHSizer->Add( RightPanelVSizer, 1, wxALIGN_CENTER_VERTICAL, 5 );


	RightPanel->SetSizer( RightPanelHSizer );
	RightPanel->Layout();
	RightPanelHSizer->Fit( RightPanel );
	ContentGrid->Add( RightPanel, 0, wxALL|wxEXPAND, 5 );


	MainBSizer->Add( ContentGrid, 1, wxEXPAND, 5 );


	this->SetSizer( MainBSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainWindowV::ExitAll ) );
	FileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::OpenFileDialog ), this, FileMenuOpen->GetId());
	FileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::OpenSaveDialog ), this, FileMenuSave->GetId());
	WatermarksM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::RmWaterR ), this, WatermarkRB->GetId());
	WatermarksM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::RmWaterBW ), this, WatermarkBWM->GetId());
	ChannelsM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::ChannelR ), this, ChannelR->GetId());
	ChannelsM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::ChannelG ), this, ChannelG->GetId());
	ChannelsM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::ChannelB ), this, ChannelB->GetId());
	ChannelsM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::ChannelA ), this, ChannelA->GetId());
	ChannelsM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::ChannelRGBA ), this, ChannelRGBA->GetId());
	GrayscaleM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::GrayscaleAverage ), this, GrayscaleAvg->GetId());
	GrayscaleM->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::GrayscalePerceptual ), this, GrayscalePercep->GetId());
	FiltersMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowV::Mosaic ), this, MosaicM->GetId());
}

MainWindowV::~MainWindowV()
{
}

FilePickerDialogV::FilePickerDialogV( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 600,120 ), wxSize( 600,400 ) );

	wxBoxSizer* HSizer;
	HSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* VSizer;
	VSizer = new wxBoxSizer( wxVERTICAL );

	VSizer->SetMinSize( wxSize( -1,10000 ) );
	filePicker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Images (*.jpg;*.jpeg;*.png;*.gif;*.bmp;*.tiff;*.tif;*.webp;*.ico;*.xpm)|*.jpg;*.jpeg;*.png;*.gif;*.bmp;*.tiff;*.tif;*.webp;*.ico;*.xpm"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	filePicker->SetMinSize( wxSize( 1000,-1 ) );

	VSizer->Add( filePicker, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	OpenImgB = new wxButton( this, wxID_ANY, wxT("Open Image"), wxDefaultPosition, wxDefaultSize, 0 );
	VSizer->Add( OpenImgB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	ImgPreview = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( ImgPreview, 0, wxEXPAND, 5 );


	VSizer->Add( bSizer9, 0, wxEXPAND, 5 );


	HSizer->Add( VSizer, 1, 0, 5 );


	this->SetSizer( HSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	filePicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( FilePickerDialogV::previewImage ), NULL, this );
	OpenImgB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FilePickerDialogV::OpenImg ), NULL, this );
}

FilePickerDialogV::~FilePickerDialogV()
{
}

FileSaveDialogV::FileSaveDialogV( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );

	wxBoxSizer* HSizer;
	HSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* VSizer;
	VSizer = new wxBoxSizer( wxVERTICAL );

	fileSaver = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Save file"), wxT("Images (*.jpg;*.jpeg;*.png;*.gif;*.bmp;*.tiff;*.tif;*.webp;*.ico;*.xpm)|*.jpg;*.jpeg;*.png;*.gif;*.bmp;*.tiff;*.tif;*.webp;*.ico;*.xpm"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	VSizer->Add( fileSaver, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	HSizer->Add( VSizer, 1, 0, 5 );


	this->SetSizer( HSizer );
	this->Layout();
	HSizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	fileSaver->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( FileSaveDialogV::SaveFile ), NULL, this );
}

FileSaveDialogV::~FileSaveDialogV()
{
}

RGBPickerDialogV::RGBPickerDialogV( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* HSizer;
	HSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* VSizer;
	VSizer = new wxBoxSizer( wxVERTICAL );

	RBGPickerLabel = new wxStaticText( this, wxID_ANY, wxT("RGB Color"), wxDefaultPosition, wxDefaultSize, 0 );
	RBGPickerLabel->Wrap( -1 );
	VSizer->Add( RBGPickerLabel, 0, wxALL, 5 );

	RGBPickerDialogControl = new wxColourPickerCtrl( this, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ), wxDefaultPosition, wxSize( -1,-1 ), wxCLRP_SHOW_LABEL );
	VSizer->Add( RGBPickerDialogControl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	HSizer->Add( VSizer, 1, 0, 5 );


	this->SetSizer( HSizer );
	this->Layout();
	HSizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	RGBPickerDialogControl->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( RGBPickerDialogV::RGBPickerSelected ), NULL, this );
}

RGBPickerDialogV::~RGBPickerDialogV()
{
}

OneValuePickerSliderV::OneValuePickerSliderV( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* HSizer;
	HSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* VSizer;
	VSizer = new wxBoxSizer( wxVERTICAL );

	ValueLabel = new wxStaticText( this, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	ValueLabel->Wrap( -1 );
	VSizer->Add( ValueLabel, 0, wxALL, 5 );

	ValueSlider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( 175,75 ), wxSL_HORIZONTAL|wxSL_LABELS );
	VSizer->Add( ValueSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	ValueInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	VSizer->Add( ValueInput, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	SelectB = new wxButton( this, wxID_ANY, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	VSizer->Add( SelectB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	HSizer->Add( VSizer, 1, wxALIGN_CENTER_VERTICAL, 5 );


	this->SetSizer( HSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	ValueSlider->Connect( wxEVT_SLIDER, wxCommandEventHandler( OneValuePickerSliderV::ValueUpdateTxt ), NULL, this );
	ValueInput->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( OneValuePickerSliderV::ValueUpdateSlider ), NULL, this );
	SelectB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OneValuePickerSliderV::SelectValue ), NULL, this );
}

OneValuePickerSliderV::~OneValuePickerSliderV()
{
}
