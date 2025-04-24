#include "MainWindow.h"
#include "myForms/HTMLSaveDialog.h"
#include "myForms/OneValuePickerSlider.h"
#include "myForms/ToTextOptions.h"
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
  FilePickerDialog* fdiag = new FilePickerDialog();
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

  RGBPickerDialog* rgbdiag = new RGBPickerDialog();

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

void MainWindow::Threshold( wxCommandEvent& event )
{
  if (!imgloaded) return;

  OneValuePickerSlider* valuepicker = new OneValuePickerSlider("Threshold", 0, 255, 128);

  if (valuepicker->ShowModal() == wxID_OK)
  {
    img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());
    
    img.threshold(valuepicker->value);
  }

  reloadModImg();
}

void MainWindow::HighContrast( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

  img.threshold(128);

  reloadModImg();
}

void MainWindow::Negative( wxCommandEvent& event )
{
  if (!imgloaded) return;

  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());
  
  img.threshold(128, true);

  reloadModImg();
}

void MainWindow::Brightness( wxCommandEvent& event )
{
  if (!imgloaded) return;

  OneValuePickerSlider* valuepicker = new OneValuePickerSlider("Brightness", -255, 255, 0);

  if (valuepicker->ShowModal() == wxID_OK)
  {
    img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());
    
    img.brightness(valuepicker->value);
  }

  reloadModImg();
}

void MainWindow::ToCharCust( wxCommandEvent& event )
{
  if (!imgloaded) return;

  ToTextOptions* txtoptions = new ToTextOptions(2, std::max(2, img.w/10), 2, 2, std::max(2, img.h/10), 2);

  if (txtoptions->ShowModal() == wxID_OK)
  {
    img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

    std::string r = img.toTextHTML(
                    txtoptions->XRegSizSlider->GetValue(), 
                    txtoptions->YRegSizSlider->GetValue(),
                    txtoptions->FontSizeSlider->GetValue(),
                    txtoptions->CharIn->GetValue().c_str()[0]
                    );

    HTMLSaveDialog* savediag = new HTMLSaveDialog();

    if (savediag->ShowModal() == wxID_OK)
    {
      wxFile file;
      if (file.Create(savediag->path, true)) {
          file.Write(r);
          file.Close();
      } else {
        wxMessageBox("Failed to save file!", "Error", wxOK | wxICON_ERROR);
      }
    }
  }

  reloadModImg();
}

void MainWindow::ToCharM( wxCommandEvent& event )
{
  if (!imgloaded) return;

  ToTextOptions* txtoptions = new ToTextOptions(2, std::max(2, img.w/10), 2, 2, std::max(2, img.h/10), 2, 'M');

  if (txtoptions->ShowModal() == wxID_OK)
  {
    img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

    std::string r = img.toTextHTML(
                    txtoptions->XRegSizSlider->GetValue(), 
                    txtoptions->YRegSizSlider->GetValue(),
                    txtoptions->FontSizeSlider->GetValue(),
                    'M'
                    );

    HTMLSaveDialog* savediag = new HTMLSaveDialog();

    if (savediag->ShowModal() == wxID_OK)
    {
      wxFile file;
      if (file.Create(savediag->path, true)) {
          file.Write(r);
          file.Close();
      } else {
        wxMessageBox("Failed to save file!", "Error", wxOK | wxICON_ERROR);
      }
    }
  }

  reloadModImg();
}

void MainWindow::ToCharAt( wxCommandEvent& event )
{
  if (!imgloaded) return;

  ToTextOptions* txtoptions = new ToTextOptions(2, std::max(2, img.w/10), 2, 2, std::max(2, img.h/10), 2, '@');

  if (txtoptions->ShowModal() == wxID_OK)
  {
    img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

    std::string r = img.toTextHTML(
                    txtoptions->XRegSizSlider->GetValue(), 
                    txtoptions->YRegSizSlider->GetValue(),
                    txtoptions->FontSizeSlider->GetValue(),
                    '@'
                    );

    HTMLSaveDialog* savediag = new HTMLSaveDialog();

    if (savediag->ShowModal() == wxID_OK)
    {
      wxFile file;
      if (file.Create(savediag->path, true)) {
          file.Write(r);
          file.Close();
      } else {
        wxMessageBox("Failed to save file!", "Error", wxOK | wxICON_ERROR);
      }
    }
  }

  reloadModImg();
}