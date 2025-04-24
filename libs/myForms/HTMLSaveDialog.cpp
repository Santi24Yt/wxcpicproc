#include "HTMLSaveDialog.h"

void HTMLSaveDialog::SaveFile( wxFileDirPickerEvent& event )
{
  path = fileSaver->GetPath();
  EndModal(wxID_OK);
}