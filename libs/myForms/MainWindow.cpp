#include "MainWindow.h"
#include "wx/app.h"
#include "FilePickerDialog.h"
#include <cstring>

void MainWindow::ExitAll(wxCloseEvent& event)
{
  wxExit();
}

void MainWindow::OpenFileDialog(wxCommandEvent& event)
{
  FilePickerDialog* fdiag = new FilePickerDialog(NULL);
  if (fdiag->ShowModal() == wxID_OK)
  {
    if (fdiag->validimg)
    {
      img = fdiag->image;
      if (img.IsOk())
      {
        int cw1 = OgImg->GetSize().GetWidth();
        int ch1 = OgImg->GetSize().GetHeight();
        int w1 = img.GetWidth();
        int h1 = img.GetHeight();
        double aspect1 = (double)w1/(double)h1;

        if ((double)cw1/(double)ch1 > aspect1)
        {
          cw1 = (int)(ch1 * aspect1);
        } else {
          ch1 = (int)(cw1 * aspect1);
        }

        OgImg->SetBitmap(wxBitmap(img.Scale(cw1, ch1, wxIMAGE_QUALITY_NEAREST)));

        int cw2 = ModImg->GetSize().GetWidth();
        int ch2 = ModImg->GetSize().GetHeight();
        int w2 = img.GetWidth();
        int h2 = img.GetHeight();
        double aspect2 = (double)w2/(double)h2;

        if ((double)cw2/(double)ch2 > aspect2)
        {
          cw2 = (int)(ch2 * aspect2);
        } else {
          ch2 = (int)(cw2 * aspect2);
        }

        ModImg->SetBitmap(wxBitmap(img.Scale(cw2, ch2, wxIMAGE_QUALITY_NEAREST)));

        Layout();

        memcpy(imgdata, img.GetData(), img.GetWidth() * img.GetHeight() * 3);
      }
    }
  }
}
