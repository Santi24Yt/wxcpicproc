#include "MainWindow.h"
#include "wx/app.h"
#include "FilePickerDialog.h"
#include "FileSaveDialog.h"
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
  img.setpxs(wxogimg.GetData(), wxogimg.GetAlpha());

  img.rmwatermarkpostcard();

  reloadModImg();
}

// void MainWindow::RmWaterR( wxCommandEvent& event )
// {
//   setImg(wxogimg.GetData(), wxogimg.GetAlpha());

//   int nwm = 0;
//   double rav = 0.0;
//   double gav = 0.0;
//   double bav = 0.0;

//   for (int x = 0; x < w; x++)
//   {
//     for (int y = 0; y < h; y++)
//     {
//       unsigned char r = (img[y][x] >> 24) & 0xFF;
//       unsigned char g = (img[y][x] >> 16) & 0xFF;
//       unsigned char b = (img[y][x] >> 8) & 0xFF;

//       if (std::abs(r-g) > 10)
//       {
//         nwm++;
//         rav += r;
//         gav += g;
//         bav += b;
//         // img[y][x] = 0x0000FFFF;
//       }
//     }
//   }

//   if (nwm == 0)
//     return;

//   rav = rav/nwm;
//   gav = gav/nwm;
//   bav = bav/nwm;

//   unsigned char ravc = (unsigned char)rav;
//   unsigned char gavc = (unsigned char)gav;
//   unsigned char bavc = (unsigned char)bav;

//   for (int x = 0; x < w; x++)
//   {
//     for (int y = 0; y < h; y++)
//     {
//       unsigned char a = (img[y][x] >> 0) & 0xFF;
//       img[y][x] &= (ravc << 24) | (gavc << 16) | (bavc << 8) | a;
//     }
//   }

//   reloadModImg();
// }

// void MainWindow::RmWaterBW( wxCommandEvent& event )
// {
//   setImg(wxogimg.GetData(), wxogimg.GetAlpha());

//   // float m = 1.3475;

//   // unsigned char rmax = 0;
//   // unsigned char gmax = 0;
//   // unsigned char bmax = 0;

//   // unsigned char rmin = 255;
//   // unsigned char gmin = 255;
//   // unsigned char bmin = 255;

//   // for (int x = 0; x < w; x++)
//   // {
//   //   for (int y = 0; y < h; y++)
//   //   {
//   //     int px = img[y][x];
//   //     unsigned char r = (px >> 24) & 0xFF;
//   //     unsigned char g = (px >> 16) & 0xFF;
//   //     unsigned char b = (px >> 8) & 0xFF;

//   //     if (r - g >= 10)
//   //     {
//   //       if (r > rmax)
//   //         rmax = r;
//   //       if (g > gmax)
//   //         gmax = g;
//   //       if (b > bmax)
//   //         bmax = b;

//   //       if (r < rmin)
//   //         rmin = r;
//   //       if (g < gmin)
//   //         gmin = g;
//   //       if (b < bmin)
//   //         bmin = b;
//   //     }
//   //   }
//   // }

//   // std::cout << "rmin: " << (int)rmin << ", rmax: " << (int)rmax << std::endl;
//   // std::cout << "gmin: " << (int)gmin << ", gmax: " << (int)gmax << std::endl;
//   // std::cout << "bmin: " << (int)bmin << ", bmax: " << (int)bmax << std::endl;

//   // for (int x = 0; x < w; x++)
//   // {
//   //   for (int y = 0; y < h; y++)
//   //   {
//   //     int px = img[y][x];
//   //     unsigned char r = (px >> 24) & 0xFF;
//   //     unsigned char g = (px >> 16) & 0xFF;
//   //     unsigned char b = (px >> 8) & 0xFF;
//   //     unsigned char a = (px >> 0) & 0xFF;

//   //     if (r - g >= 10)
//   //     {
//   //       double bd = std::sqrt(std::pow(r-0x00,2) + std::pow(g-0x00,2) + std::pow(b-0x00,2));
//   //       double wd = std::sqrt(std::pow(0xFF-r,2) + std::pow(0xFF-g,2) + std::pow(0xFF-b,2));
//   //       if (bd < wd)
//   //       {
//   //         r = r - rmin;
//   //         g = g - gmin;
//   //         b = b - bmin;
//   //       } else {
//   //         r = r + (255 - rmax);
//   //         g = g + (255 - gmax);
//   //         b = b + (255 - bmax);
//   //       }

//   //       int gr = (0.299 * r + 0.587 * g + 0.114 * b);
//   //       img[y][x] = (gr << 24) | (gr << 16) | (gr << 8) | a;
//   //     }
//   //     int gr = (0.299 * r + 0.587 * g + 0.114 * b) * m;
//   //     if (gr > 255)
//   //     {
//   //       gr = 255;
//   //     }
//   //     unsigned char pc = (unsigned char)gr;
//   //     img[y][x] = (pc << 24) | (pc << 16) | (pc << 8) | a;
//   //   }
//   // }

//   RmWaterBWRec();
  
//   reloadModImg();
// }

// void MainWindow::RmWaterBWRec()
// {
//   int** imgCopy = (int**)malloc(h * sizeof(int*));
//   for (int y = 0; y < h; y++)
//   {
//       imgCopy[y] = (int*)malloc(w * sizeof(int));
//       memcpy(imgCopy[y], img[y], w * sizeof(int)); // Copy row data
//   }

//   // bool rem = false;
//   float m = 1.347;

//   for (int x = 0; x < w; x++)
//   {
//     for (int y = 0; y < h; y++)
//     {
//       int px = imgCopy[y][x];
//       unsigned char r = (px >> 24) & 0xFF;
//       unsigned char g = (px >> 16) & 0xFF;
//       unsigned char b = (px >> 8) & 0xFF;
//       unsigned char a = (px >> 0) & 0xFF;
      
//       int count = 0;

//       if (r - g >= 8)
//       {
//         // rem = true;
//         int gr = (0.299 * r + 0.587 * g + 0.114 * b);

//         std::unordered_map<int, int> grays;
//         int maxgray = -1;

//         for (int dy = -1; dy <= 1; dy++)
//         {
//           for (int dx = -1; dx <= 1; dx++)
//           {
//             int ny = y + dy;
//             int nx = x + dx;
//             if (nx >= 0 && nx < w && ny >= 0 && ny < h)
//             {
//               int neighbor = imgCopy[ny][nx];
//               unsigned char nr = (neighbor >> 24) & 0xFF;
//               unsigned char ng = (neighbor >> 16) & 0xFF;
//               unsigned char nb = (neighbor >> 8) & 0xFF;
//               if (nr - ng < 8)
//               {
//                 int ngr = (0.299 * nr + 0.587 * ng + 0.114 * nb);
//                 // int ngr = ((nr+ng+nb)*m/3);
//                 ngr = std::min(ngr, 255);
//                 if (ngr > 250)
//                   ngr = 255;
//                 grays[ngr]++;
//                 if (maxgray == -1)
//                 {
//                   maxgray = ngr;
//                 }
//                 if (grays[ngr] > grays[maxgray])
//                 {
//                   maxgray = ngr;
//                 }
//                 count++;
//               }
//             }
//           }
//         }

//         if (gr > 255)
//         {
//           gr = 255;
//         }
//         unsigned char pc = (unsigned char)maxgray;

//         // if (rand() % 100 < 50 && count > 0)
//         // {
//         //   int off = rand() % grays.size();
//         //   auto it = grays.begin();
//         //   for (int i = 0; i < off; i++)
//         //   {
//         //     it++;
//         //   }
//         //   int ng = it->first;
//         //   pc = (unsigned char)ng;
//         // }

//         if (count > 0)
//           img[y][x] = (pc << 24) | (pc << 16) | (pc << 8) | a;
//       }
//     }
//   }

//   for (int x = 0; x < w; x++)
//   {
//     for (int y = 0; y < h; y++)
//     {
//       int px = img[y][x];
//       unsigned char r = (px >> 24) & 0xFF;
//       unsigned char g = (px >> 16) & 0xFF;
//       unsigned char b = (px >> 8) & 0xFF;
//       unsigned char a = (px >> 0) & 0xFF;

//       if (r - g >= 8)
//       {
//         int gr = (0.299 * r + 0.587 * g + 0.114 * b) * m;
//         // int gr = ((r+g+b)*m/3);
//         if (gr > 255)
//         {
//           gr = 255;
//         }
//         unsigned char pc = (unsigned char)gr;
//         unsigned char bc = pc;
//         if (bc < 240)
//           bc = std::max(0, pc-9);
//         img[y][x] = (pc << 24) | (pc << 16) | (bc << 8) | a;
//       }

//     }
//   }

//   for (int y = 0; y < h; y++)
//   {
//       free(imgCopy[y]);
//   }
//   free(imgCopy);

//   // if (rem && loops < 100)
//   // {
//   //   loops++;
//   //   RmWaterBWRec();
//   // }
//   // loops = 0;
// }

// // void MainWindow::RmWaterBWRec()
// // {
// //   int** imgCopy = (int**)malloc(h * sizeof(int*));
// //   for (int y = 0; y < h; y++) {
// //       imgCopy[y] = (int*)malloc(w * sizeof(int));
// //       memcpy(imgCopy[y], img[y], w * sizeof(int));
// //   }

// //   bool rem = false;

// //   for (int x = 0; x < w; x++)
// //   {
// //     for (int y = 0; y < h; y++)
// //     {
// //       int px = imgCopy[y][x];
// //       unsigned char r = (px >> 24) & 0xFF;
// //       unsigned char g = (px >> 16) & 0xFF;
// //       unsigned char b = (px >> 8) & 0xFF;
// //       unsigned char a = (px >> 0) & 0xFF;
// //       int drg = r - g;
// //       // float m = 1.3475;
// //       if (drg >= 6)
// //       {
// //         rem = true;
// //         int gray = static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);
// //         int colorDeviation = std::abs(r - gray) + std::abs(g - gray) + std::abs(b - gray);

// //         if (colorDeviation > 8) {
// //             int sumGray = 0, count = 0;

// //             for (int dy = -1; dy <= 1; dy++) {
// //                 for (int dx = -1; dx <= 1; dx++) {
// //                     int ny = y + dy, nx = x + dx;
// //                     if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
// //                         int neighbor = imgCopy[ny][nx];
// //                         unsigned char nr = (neighbor >> 24) & 0xFF;
// //                         unsigned char ng = (neighbor >> 16) & 0xFF;
// //                         unsigned char nb = (neighbor >> 8) & 0xFF;

// //                         int nGray = static_cast<int>(0.299 * nr + 0.587 * ng + 0.114 * nb);
// //                         int nDeviation = std::abs(nr - nGray) + std::abs(ng - nGray) + std::abs(nb - nGray);

// //                         if (nDeviation < 20) {
// //                             sumGray += nGray;
// //                             count++;
// //                         }
// //                     }
// //                 }
// //             }

// //             if (count > 0) {
// //                 int avgGray = std::min(sumGray / count, 255);
// //                 if (avgGray > 240)
// //                 {
// //                   avgGray = 255;
// //                 }
// //                 img[y][x] = (avgGray << 24) | (avgGray << 16) | (avgGray << 8) | a;
// //             } else {
// //                 // gray *= m;
// //                 // gray = std::min(gray, 255);
// //                 // img[y][x] = (gray << 24) | (gray << 16) | (gray << 8) | a;
// //             }
// //           }

// //         // int gr = (0.299 * r + 0.587 * g + 0.114 * b) * m;
// //         // if (gr > 255)
// //         // {
// //         //   gr = 255;
// //         // }
// //         // unsigned char pc = (unsigned char)gr;
// //         // img[y][x] = (pc << 24) | (pc << 16) | (pc << 8) | a;
// //       }
// //     }
// //   }

// //   for (int y = 0; y < h; y++) {
// //       free(imgCopy[y]);
// //   }
// //   free(imgCopy);

// //   if (rem && loops < 100)
// //   {
// //     loops++;
// //     RmWaterBWRec();
// //   }
// //   loops = 0;
// // }
