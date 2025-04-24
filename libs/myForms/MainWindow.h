#pragma once

#include "wxWidgets/wxFbApp.h"
#include "image/image.h"

class MainWindow : public MainWindowV
{
  public:
  MainWindow(wxWindow* parent = NULL )
  : MainWindowV(parent,  wxID_ANY, wxT("CPicProcwx"), wxDefaultPosition, wxSize( 1280,720 ), wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL)
  {};

  void ExitAll(wxCloseEvent& event) override;
  void OpenFileDialog(wxCommandEvent& event) override;
  void OpenSaveDialog( wxCommandEvent& event ) override;
  void RmWaterBW( wxCommandEvent& event ) override;
  // void RmWaterR( wxCommandEvent& event ) override;
  void ChannelR( wxCommandEvent& event ) override;
  void ChannelG( wxCommandEvent& event ) override;
  void ChannelB( wxCommandEvent& event ) override;
  void ChannelA( wxCommandEvent& event ) override;
  void ChannelRGBA( wxCommandEvent& event ) override;
  void GrayscaleAverage( wxCommandEvent& event ) override;
  void GrayscalePerceptual( wxCommandEvent& event ) override;
  void Mosaic( wxCommandEvent& event ) override;
  void Threshold( wxCommandEvent& event ) override;
  void HighContrast( wxCommandEvent& event ) override;
  void Negative( wxCommandEvent& event ) override;
  void Brightness( wxCommandEvent& event ) override;
  void ToCharCust( wxCommandEvent& event ) override;
  void ToCharM( wxCommandEvent& event ) override;
  void ToCharAt( wxCommandEvent& event ) override;



  bool imgloaded = false;
  wxImage wxogimg;
  Image img;

  void reloadModImg();
};