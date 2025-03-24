#pragma once

#include "wxWidgets/wxFbApp.h"
#include <cstdint>

class RGBPickerDialog : public RGBPickerDialogV
{
  public:
  RGBPickerDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("RGB"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE )
  : RGBPickerDialogV(parent,id,title,pos,size,style)
  {}

  void RGBPickerSelected( wxColourPickerEvent& event ) override;
  uint32_t color;
};