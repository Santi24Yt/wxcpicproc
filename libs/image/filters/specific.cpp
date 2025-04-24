#include "../image.h"
#include <string>
#include <unordered_map>

void Image::rmwatermarkpostcard()
{
  Pixels pixog = Pixels(pixels);
  float m = 1.347;

  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(pixog, x,y);
      byte r = R(px);
      byte g = G(px);
      byte a = A(px);
      
      int count = 0;
      if (r - g >= 8)
      {
        std::unordered_map<int, int> grays;
        int maxgray = -1;

        for (int dy = -1; dy <= 1; dy++)
        {
          for (int dx = -1; dx <= 1; dx++)
          {
            int ny = y + dy;
            int nx = x + dx;
            if (nx >= 0 && nx < w && ny >= 0 && ny < h)
            {
              int n = gpx(pixog, nx,ny);
              byte nr = R(n);
              byte ng = G(n);
              if (nr - ng < 8)
              {
                int ngr = (int)grayperceptual(n);
                if (ngr > 250)
                  ngr = 255;
                grays[ngr]++;
                if (maxgray == -1)
                {
                  maxgray = ngr;
                }
                if (grays[ngr] > grays[maxgray])
                {
                  maxgray = ngr;
                }
                count++;
              }
            }
          }
        }

        byte c = (byte)maxgray;

        // if (rand() % 100 < 50 && count > 0)
        // {
        //   int off = rand() % grays.size();
        //   auto it = grays.begin();
        //   for (int i = 0; i < off; i++)
        //   {
        //     it++;
        //   }
        //   int ng = it->first;
        //   c = (byte)ng;
        // }

        if (count > 0)
        {
          spx(x,y,c,c,c, a);
        }
      }
    }
  }

  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x,y);
      byte r = R(px);
      byte g = G(px);
      byte a = A(px);

      if (r - g >= 8)
      {
        byte gray = T(grayperceptual(px) * m);
        byte bc = gray;
        if (bc < 240)
          bc = std::max(0, gray-9);
        spx(x,y, gray,gray,bc, a);
      }
    }
  }
}

Image Image::rmwatermarkpostcardc()
{
  Image ni = Image(*this);
  ni.rmwatermarkpostcard();
  return ni;
}

std::string Image::toTextHTML(int sx, int sy, int fs, char txt, bool gr)
{
  if (txt == ' ' || txt == '\0') txt = '.';

  std::string res = "<!DOCTYPE html>\n<title>wxcpicproc image to text</title>\n<style>body {font-family: monospace; line-height: 50%;}</style>";

  for (int ym = 0; ym < h; ym += sy)
  {
    for (int xm = 0; xm < w; xm += sx)
    {
      long long sr = 0;
      int nr = 0;
      long long sg = 0;
      int ng = 0;
      long long sb = 0;
      int nb = 0;
      bool empty = true;

      for (int x = xm; x < std::min(xm+sx, w); x++)
      {
        for (int y = ym; y < std::min(ym+sy, h); y++)
        {
          pixel px = gpx(x, y);
          if (A(px) != 0)
          {
            empty = false;
            sr += R(px);
            nr++;
            sg += G(px);
            ng++;
            sb += B(px);
            nb++;
          }
        }
      }

      if (empty)
      {
        res.append("<font size=\""+std::to_string(fs)+"\" color=\"rgba(0, 0, 0, 0)\">&nbsp;</font>");
      } else {
        byte r = (byte)std::min((long long)255, sr/nr);
        byte g = (byte)std::min((long long)255, sg/ng);
        byte b = (byte)std::min((long long)255, sb/nb);
        for (int x = xm; x < xm+sx; x++)
        {
          for (int y = ym; y < ym+sy; y++)
          {
            spx(x, y, r, g, b);
            if (gr)
            {
              byte grc = grayaverage(gpx(x,y));
              spx(x,y,grc,grc,grc);
              r = grc;
              g = grc;
              b = grc;
            }
          }
        }

        res.append("<font size=\""+std::to_string(fs)+"\" color=\"rgb("+std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+")\">"+txt+"</font>");
      }
    }
    res.append("<br>\n");
  }

  return res;
}