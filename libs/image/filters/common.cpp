#include "../image.h"

void  Image::channelred()
{
  for (int x = 0; x < w; x++)
  {
    for (int y = 0; y < h; y++)
    {
      spx(x, y, R(gpx(x, y)), 0, 0, A(gpx(x, y)));
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
      spx(x, y, 0, G(gpx(x, y)), 0, A(gpx(x, y)));
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
      spx(x, y, 0, 0, B(gpx(x, y)), A(gpx(x, y)));
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
      spx(x, y, A(gpx(x, y)));
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
      spx(x, y, gpx(x,y) & c);
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
      byte g = grayaverage(gpx(x, y));
      spx(x, y, g, g, g, A(gpx(x, y)));
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
      byte g = grayperceptual(gpx(x, y));
      spx(x, y, g, g, g, A(gpx(x, y)));
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
          if (A(gpx(x, y)) != 0)
          {
            empty = false;
            sr += R(gpx(x, y));
            nr++;
            sg += G(gpx(x,y));
            ng++;
            sb += B(gpx(x,y));
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