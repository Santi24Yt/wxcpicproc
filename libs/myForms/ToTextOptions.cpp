#include "ToTextOptions.h"

ToTextOptions::ToTextOptions( int min1, int max1, int def1, int min2, int max2, int def2, char c, wxWindow* parent)
  : ToTextOptionsV(parent,wxID_ANY,wxT("Text Options"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE)
{
  XRegSizSlider->SetRange(min1, max1);
  XRegSizSlider->SetValue(def1);
  YRegSizSlider->SetRange(min2, max2);
  YRegSizSlider->SetValue(def2);
  CharIn->SetValue(wxString(c));
}

void ToTextOptions::TextOptionsSelect( wxCommandEvent& event )
{
  EndModal(wxID_OK);
}