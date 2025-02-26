#include "FilePickerDialog.h"
#include "wx/msgdlg.h"

void FilePickerDialog::previewImage(wxFileDirPickerEvent& event)
{
  wxImage img = wxImage(filePicker->GetPath(), wxBITMAP_TYPE_ANY);
  if (img.IsOk())
  {
    ImgPreview->SetMinSize(wxSize(-1, 200));
    GetSizer()->Layout();
    int cw = ImgPreview->GetSize().GetWidth();
    int ch = ImgPreview->GetSize().GetHeight();
    int w = img.GetWidth();
    int h = img.GetHeight();
    double aspect = (double)w/(double)h;

    if ((double)cw/(double)ch > aspect)
    {
      cw = (int)(ch * aspect);
    } else {
      ch = (int)(cw * 1/aspect);
    }

    ImgPreview->SetBitmap(wxBitmap(img.Scale(cw, ch, wxIMAGE_QUALITY_NEAREST)));
    Layout();
    GetSizer()->Layout();
    validimg = true;
    image = img;
  } else {
    validimg = false;
    wxMessageBox("Failed to load image!", "Error", wxOK | wxICON_ERROR);
  }
}

void FilePickerDialog::OpenImg( wxCommandEvent& event )
{
  if (validimg)
  {
    EndModal(wxID_OK);
  } else {
    wxMessageBox("Failed to load image!", "Error", wxOK | wxICON_ERROR);
  }
}