#include "MainWindow.h"
#include "myForms/OneValuePickerSlider.h"
#include "wx/app.h"
#include "FilePickerDialog.h"
#include "FileSaveDialog.h"
#include "RGBPickerDialog.h"
#include "wx/image.h"
#include "wx/msgdlg.h"
#include "wx/string.h"
#include <cmath>
#include <cstdlib>

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
      wxogimg = fdiag->image;
      if (wxogimg.IsOk())
      {
        int cw1 = OgImg->GetSize().GetWidth();
        int ch1 = OgImg->GetSize().GetHeight();
        int w1 = wxogimg.GetWidth();
        int h1 = wxogimg.GetHeight();
        double aspect1 = (double)w1/(double)h1;

        if ((double)cw1/(double)ch1 > aspect1)
        {
          cw1 = (int)(ch1 * aspect1);
        } else {
          ch1 = (int)(cw1 * 1/aspect1);
        }

        OgImg->SetBitmap(wxBitmap(wxogimg.Scale(cw1, ch1, wxIMAGE_QUALITY_NEAREST)));

        Layout();


        img = Image(wxogimg.GetWidth(),wxogimg.GetHeight());
        img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

        reloadModImg();

        imgloaded = true;
      }
    }
  }
}

void MainWindow::OpenSaveDialog( wxCommandEvent& event )
{
  FileSaveDialog* fsdiag = new FileSaveDialog(this);
  if (fsdiag->ShowModal() == wxID_OK)
  {
    if (imgloaded)
    {
      wxString p = fsdiag->path;
      wxImage tmpImg = wxImage(img.w, img.h, img.data(), img.alpha());
      bool r = tmpImg.SaveFile(p);
      if (!r)
        wxMessageBox("Failed to save image!", "Error", wxOK | wxICON_ERROR);
    }
  }
}

void MainWindow::reloadModImg()
{
  wxImage wxmimg = wxImage(img.w, img.h, img.data(), img.alpha());
  int cw2 = ModImg->GetSize().GetWidth();
  int ch2 = ModImg->GetSize().GetHeight();
  int w2 = wxmimg.GetWidth();
  int h2 = wxmimg.GetHeight();
  double aspect2 = (double)w2/(double)h2;

  if ((double)cw2/(double)ch2 > aspect2)
  {
    cw2 = (int)(ch2 * aspect2);
  } else {
    ch2 = (int)(cw2 * 1/aspect2);
  }

  ModImg->SetBitmap(wxBitmap(wxmimg.Scale(cw2, ch2, wxIMAGE_QUALITY_NEAREST)));
  Layout();
}

void MainWindow::RmWaterBW( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

  img.rmwatermarkpostcard();

  reloadModImg();
}

void MainWindow::ChannelR( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

  img.channelred();

  reloadModImg();
}

void MainWindow::ChannelG( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

  img.channelgreen();

  reloadModImg();
}

void MainWindow::ChannelB( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

  img.channelblue();

  reloadModImg();
}

void MainWindow::ChannelA( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

  img.channelalpha();

  reloadModImg();
}

void MainWindow::ChannelRGBA( wxCommandEvent& event )
{
  if (!imgloaded) return;

  RGBPickerDialog* rgbdiag = new RGBPickerDialog(NULL);

  if (rgbdiag->ShowModal() == wxID_OK)
  {
    img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

    img.channelrgba(rgbdiag->color);
  }

  reloadModImg();
}

void MainWindow::GrayscaleAverage( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());
  
  img.grayscaleaverage();

  reloadModImg();
}

void MainWindow::GrayscalePerceptual( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());
  
  img.grayscaleperceptual();

  reloadModImg();
}

void MainWindow::Mosaic( wxCommandEvent& event )
{
  if (!imgloaded) return;

  OneValuePickerSlider* valuepicker = new OneValuePickerSlider("Mosaic Size", 2, std::max(img.h, img.w), 2);

  if (valuepicker->ShowModal() == wxID_OK)
  {
    img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());
    
    img.mosaic(valuepicker->value);
  }

  reloadModImg();
}
