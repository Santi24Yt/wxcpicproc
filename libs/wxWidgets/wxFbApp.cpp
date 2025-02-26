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
