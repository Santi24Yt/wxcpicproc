#pragma once

#include "wxWidgets/wxFbApp.h"

class FilePickerDialog : public FilePickerDialogV
{
  public:
  FilePickerDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("File"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE )
  : FilePickerDialogV(parent, id, title, pos, size, style)
  {};

  void previewImage(wxFileDirPickerEvent& event) override;
  void OpenImg( wxCommandEvent& event ) override;

  bool validimg = false;
  wxImage image;
};