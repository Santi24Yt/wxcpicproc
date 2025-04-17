#pragma once

#include "wxWidgets/wxFbApp.h"
#include <cstdint>

class RGBPickerDialog : public RGBPickerDialogV
{
  public:
  RGBPickerDialog( wxWindow* parent = NULL )
  : RGBPickerDialogV(parent, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
  {}

  void RGBPickerSelected( wxColourPickerEvent& event ) override;
  uint32_t color;
};