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
