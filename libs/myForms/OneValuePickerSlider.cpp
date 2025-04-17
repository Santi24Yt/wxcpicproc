#include "OneValuePickerSlider.h"

OneValuePickerSlider::OneValuePickerSlider( std::string name, int min, int max, int def, wxWindow* parent)
  : OneValuePickerSliderV(parent,wxID_ANY,wxT("Value"),wxDefaultPosition,wxSize( 250,275 ),wxDEFAULT_DIALOG_STYLE)
{
  ValueSlider->SetRange(min, max);
  ValueSlider->SetValue(def);
  ValueLabel->SetLabel(wxString(name));
}

void OneValuePickerSlider::SelectValue( wxCommandEvent& event )
{
  value = ValueSlider->GetValue();
  EndModal(wxID_OK);
}

void OneValuePickerSlider::ValueUpdateTxt( wxCommandEvent& event )
{
  ValueInput->SetValue(wxString(std::to_string(ValueSlider->GetValue())));
}

void OneValuePickerSlider::ValueUpdateSlider( wxCommandEvent& event )
{
  int v = 2;
  try
  {
    v = std::stoi(ValueInput->GetValue().ToStdString());
  } catch (...) {

  }
  ValueSlider->SetValue(v);
}