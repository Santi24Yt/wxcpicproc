#pragma once

#include "wxWidgets/wxFbApp.h"

class HTMLSaveDialog : public HTMLSaveDialogV
{
  public:
  HTMLSaveDialog( wxWindow* parent = NULL )
  : HTMLSaveDialogV(parent, wxID_ANY, wxT("Save"), wxDefaultPosition, wxSize( -1,-1 ), wxDEFAULT_DIALOG_STYLE)
  {}

  void SaveFile( wxFileDirPickerEvent& event ) override;
  wxString path;
};