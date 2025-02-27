#include "FileSaveDialog.h"

void FileSaveDialog::SaveFile( wxFileDirPickerEvent& event )
{
  path = fileSaver->GetPath();
  EndModal(wxID_OK);
}