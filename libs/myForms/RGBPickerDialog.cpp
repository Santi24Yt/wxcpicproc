#include "RGBPickerDialog.h"

void RGBPickerDialog::RGBPickerSelected( wxColourPickerEvent& event )
{
  wxColour c = RGBPickerDialogControl->GetColour();
  color = (c.Red() << 24) | (c.Green() << 16) | (c.Blue() << 8) | c.Alpha();
  EndModal(wxID_OK);
}