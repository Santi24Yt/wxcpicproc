#pragma once

#include "wxWidgets/wxFbApp.h"

class FileSaveDialog : public FileSaveDialogV
{
  public:
  FileSaveDialog( wxWindow* parent = NULL )
  : FileSaveDialogV(parent, wxID_ANY, wxT("Save"), wxDefaultPosition, wxSize( -1,-1 ), wxDEFAULT_DIALOG_STYLE)
  {}

  void SaveFile( wxFileDirPickerEvent& event ) override;
  wxString path;
};