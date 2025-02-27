///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainWindowV
///////////////////////////////////////////////////////////////////////////////
class MainWindowV : public wxFrame
{
	private:

	protected:
		wxMenuBar* MainMenubar;
		wxMenu* FileMenu;
		wxMenu* FiltersMenu;
		wxMenu* WatermarksM;
		wxStaticLine* m_staticline1;
		wxPanel* LeftPanel;
		wxStaticBitmap* OgImg;
		wxPanel* RightPanel;
		wxStaticBitmap* ModImg;

		// Virtual event handlers, override them in your derived class
		virtual void ExitAll( wxCloseEvent& event ) { event.Skip(); }
		virtual void OpenFileDialog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenSaveDialog( wxCommandEvent& event ) { event.Skip(); }
		virtual void RmWaterR( wxCommandEvent& event ) { event.Skip(); }
		virtual void RmWaterBW( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainWindowV( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("CPicProcwx"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1280,720 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainWindowV();

};

///////////////////////////////////////////////////////////////////////////////
/// Class FilePickerDialogV
///////////////////////////////////////////////////////////////////////////////
class FilePickerDialogV : public wxDialog
{
	private:

	protected:
		wxFilePickerCtrl* filePicker;
		wxButton* OpenImgB;
		wxStaticBitmap* ImgPreview;

		// Virtual event handlers, override them in your derived class
		virtual void previewImage( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OpenImg( wxCommandEvent& event ) { event.Skip(); }


	public:

		FilePickerDialogV( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("File"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,120 ), long style = wxDEFAULT_DIALOG_STYLE );

		~FilePickerDialogV();

};

///////////////////////////////////////////////////////////////////////////////
/// Class FileSaveDialogV
///////////////////////////////////////////////////////////////////////////////
class FileSaveDialogV : public wxDialog
{
	private:

	protected:
		wxFilePickerCtrl* fileSaver;

		// Virtual event handlers, override them in your derived class
		virtual void SaveFile( wxFileDirPickerEvent& event ) { event.Skip(); }


	public:

		FileSaveDialogV( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Save"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );

		~FileSaveDialogV();

};

