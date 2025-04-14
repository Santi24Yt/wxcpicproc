#include "../image.h"

void  Image::channelred()
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y) ;
      spx(x, y, R(px), 0, 0, A(px));
    }
  }
}

Image Image::channelredc()
{
  Image ni = Image(*this);
  ni.channelred();
  return ni;
}

void  Image::channelgreen()
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);
      spx(x, y, 0, G(px), 0, A(px));
    }
  }
}

Image Image::channelgreenc()
{
  Image ni = Image(*this);
  ni.channelgreen();
  return ni;
}

void  Image::channelblue()
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);
      spx(x, y, 0, 0, B(px), A(px));
    }
  }
}

Image Image::channelbluec()
{
  Image ni = Image(*this);
  ni.channelblue();
  return ni;
}

void  Image::channelalpha()
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);
      spx(x, y, A(px));
    }
  }
}

Image Image::channelalphac()
{
  Image ni = Image(*this);
  ni.channelalpha();
  return ni;
}

void Image::channelrgba(uint32_t c)
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);
      spx(x, y, px & c);
    }
  }
}

Image Image::channelrgbac(uint32_t c)
{
  Image ni = Image(*this);
  ni.channelrgba(c);
  return ni;
}

void Image::grayscaleaverage()
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);
      byte g = grayaverage(px);
      spx(x, y, g, g, g, A(px));
    }
  }
}

Image Image::grayscaleaveragec()
{
  Image ni = Image(*this);
  ni.grayscaleaverage();
  return ni;
}

void Image::grayscaleperceptual()
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);
      byte g = grayperceptual(px);
      spx(x, y, g, g, g, A(px));
    }
  }
}

Image Image::grayscaleperceptualc()
{
  Image ni = Image(*this);
  ni.grayscaleperceptual();
  return ni;
}

void Image::mosaic(int size)
{
  for (int xm = 0; xm < w; xm += size)
  {
    for (int ym = 0; ym < h; ym += size)
    {
      long long sr = 0;
      int nr = 0;
      long long sg = 0;
      int ng = 0;
      long long sb = 0;
      int nb = 0;
      bool empty = true;

      for (int x = xm; x < std::min(xm+size, w); x++)
      {
        for (int y = ym; y < std::min(ym+size, h); y++)
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

      if (empty) continue;

      byte r = (byte)std::min((long long)255, sr/nr);
      byte g = (byte)std::min((long long)255, sg/ng);
      byte b = (byte)std::min((long long)255, sb/nb);
      for (int x = xm; x < xm+size; x++)
      {
        for (int y = ym; y < ym+size; y++)
        {
          spx(x, y, r, g, b);
        }
      }
    }
  }
}

Image Image::mosaicc(int size)
{
  Image ni = Image(*this);
  ni.mosaic(size);
  return ni;
}

void Image::threshold(int th, bool inv)
{
  byte c1 = 0xFF;
  byte c2 = 0x00;
  if (inv)
  {
    c1 = 0x00;
    c2 = 0xFF;
  }

  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);
      byte g = grayaverage(px);
      if (g >= th)
      {
        spx(x, y, c1, c1, c1, A(px));
      } else {
        spx(x, y, c2, c2, c2, A(px));
      }
    }
  }
}

Image Image::thresholdc(int th, bool inv)
{
  Image ni = Image(*this);
  ni.threshold(th, inv);
  return ni;
}

void Image::brightness(int br)
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      pixel px = gpx(x, y);

      byte r = T(R(px) + br);
      byte g = T(G(px) + br);
      byte b = T(B(px) + br);

      spx(x, y, r, g, b, A(px));
    }
  }
}

Image Image::brightnessc(int br)
{
  Image ni = Image(*this);
  ni.brightness(br);
  return ni;
}