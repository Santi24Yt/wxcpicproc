#pragma once

#include "wxWidgets/wxFbApp.h"

class OneValuePickerSlider : public OneValuePickerSliderV
{
  public:
  OneValuePickerSlider( std::string name, int min = 0, int max = 100, int def = 50, wxWindow* parent = NULL);

  void SelectValue( wxCommandEvent& event ) override;
  int value;

  void ValueUpdateTxt( wxCommandEvent& event ) override;
  void ValueUpdateSlider( wxCommandEvent& event ) override;
};