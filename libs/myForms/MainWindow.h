#pragma once

#include "wxWidgets/wxFbApp.h"
#include "image/image.h"

class MainWindow : public MainWindowV
{
  public:
  MainWindow(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("CPicProcwx"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1280,720 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL)
  : MainWindowV(parent, id, title, pos, size, style)
  {};

  void ExitAll(wxCloseEvent& event) override;
  void OpenFileDialog(wxCommandEvent& event) override;
  void OpenSaveDialog( wxCommandEvent& event ) override;
  void RmWaterBW( wxCommandEvent& event ) override;
  // void RmWaterR( wxCommandEvent& event ) override;

  bool imgloaded = false;
  wxImage wxogimg;
  Image img;

  void reloadModImg();
};