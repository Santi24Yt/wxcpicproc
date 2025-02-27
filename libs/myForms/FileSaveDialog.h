#pragma once

#include "wxWidgets/wxFbApp.h"

class FileSaveDialog : public FileSaveDialogV
{
  public:
  FileSaveDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Save"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE )
  : FileSaveDialogV(parent,id,title,pos,size,style)
  {}

  void SaveFile( wxFileDirPickerEvent& event ) override;
  wxString path;
};