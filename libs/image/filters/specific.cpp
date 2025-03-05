#include "../image.h"
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
                int ngr = (int)perceptualgray(n);
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
        byte gray = C(perceptualgray(px) * m);
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