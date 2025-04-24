#pragma once

#include "wxWidgets/wxFbApp.h"

class ToTextOptions : public ToTextOptionsV
{
  public:
  ToTextOptions( int min1, int max1, int def1, int min2, int max2, int def2, char c = '.', wxWindow* parent = NULL);

  void TextOptionsSelect( wxCommandEvent& event ) override;
};