#pragma once

#include "wxWidgets/wxFbApp.h"

class FilePickerDialog : public FilePickerDialogV
{
  public:
  FilePickerDialog( wxWindow* parent = NULL )
  : FilePickerDialogV(parent, wxID_ANY, wxT("File"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
  {};

  void previewImage(wxFileDirPickerEvent& event) override;
  void OpenImg( wxCommandEvent& event ) override;

  bool validimg = false;
  wxImage image;
};