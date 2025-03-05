#include "image.h"
#include <stdexcept>

Image::Image()
{

}

Image::Image(int wi, int hi, byte* rgb, byte* alpha)
{
  w = wi;
  h = hi;
  pixels = std::vector<std::vector<pixel>>(h, std::vector<pixel>(w));
  setpxs(rgb, alpha);
}

Image::Image(byte* rgb, byte* alpha)
{
  if (w == -1 || h == -1)
    throw std::logic_error("Image dimensions uninitialized");

  pixels = std::vector<std::vector<pixel>>(h, std::vector<pixel>(w));
  setpxs(rgb, alpha);
}

Image::Image(int wi, int hi)
{
  w = wi;
  h = hi;
  pixels = std::vector<std::vector<pixel>>(h, std::vector<pixel>(w, 0x000000FF));
}

Image::Image(const Image &i)
{
  w = i.w;
  h = i.h;
  pixels = i.pixels;
}

void Image::spx(int x, int y, pixel v)
{
  if (x >= 0 && x < w && y >= 0 && y < h)
  {
    pixels[y][x] = v;
  }
}

void Image::spx(int x, int y, byte r, byte g, byte b, byte a)
{
  pixel v = (r << 24) | (g << 16) | (b << 8) | a;
  spx(x,y, v);
}


pixel Image::gpx(int x, int y)
{
  if (x >= 0 && x < w && y >= 0 && y < h)
  {
    return pixels[y][x];
  }
  return 0x000000FF;
}

void Image::setpxs(byte* rgb, byte* alpha)
{
  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      int offset = ((y*w) + x);
      int index = 3 *offset;
      pixel pix =
        (rgb[index+0] << 24) |
        (rgb[index+1] << 16) |
        (rgb[index+2] << 8)  |
        0x00;
      if (alpha != nullptr)
      {
        pix |= alpha[offset];
      } else {
        pix |= 0xFF;
      }
      spx(x,y, pix);
    }
  }
}

byte* Image::data()
{
  byte* d = (byte*)malloc(w*h*3);

  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      pixel pixel = gpx(x,y);
      int index = 3 * ((y * w) + x);
      d[index+0] = (pixel >> 24) & 0xFF;
      d[index+1] = (pixel >> 16) & 0xFF;
      d[index+2] = (pixel >> 8) & 0xFF;
    }
  }

  return d;
}

byte* Image::alpha()
{
  byte* d = (byte*)malloc(w*h);

  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      pixel pixel = gpx(x,y);
      int index = ((y * w) + x);
      d[index] = pixel & 0xFF;
    }
  }

  return d;
}
