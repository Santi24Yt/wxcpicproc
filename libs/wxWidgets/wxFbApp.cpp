///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxFbApp.h"

///////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1280,720 ), wxSize( 1920,1080 ) );
	this->DragAcceptFiles( true );

	m_menubar1 = new wxMenuBar( 0 );
	FileMenu = new wxMenu();
	wxMenuItem* FileMenuOpen;
	FileMenuOpen = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Open") ) + wxT('\t') + wxT("ctrl+o"), wxT("CTRL + O"), wxITEM_NORMAL );
	FileMenu->Append( FileMenuOpen );

	wxMenuItem* FileMenuSave;
	FileMenuSave = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("ctrl+s"), wxT("CTRL + S"), wxITEM_NORMAL );
	FileMenu->Append( FileMenuSave );

	m_menubar1->Append( FileMenu, wxT("File") );

	FiltersMenu = new wxMenu();
	m_menubar1->Append( FiltersMenu, wxT("Filters") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainWindow::~MainWindow()
{
}
