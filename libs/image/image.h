#pragma once

#include <vector>
#include <cstdint>

typedef unsigned char byte;
typedef std::uint32_t pixel;
typedef std::vector<std::vector<pixel>> Pixels;

class Image
{
  public:
  Pixels pixels = std::vector<std::vector<pixel>>(0, std::vector<pixel>(0));
  int w = -1;
  int h = -1;

  Image();
  Image(int wi, int hi, byte* rgb, byte* alpha = nullptr);
  Image(byte* rgb, byte* alpha = nullptr);
  Image(int wi, int hi);
  Image(const Image &i);

  void spx(int x, int y, pixel v);
  static void spx(Pixels &pxs, int x, int y, pixel v)
  {
    if (x >= 0 && x < (int)pxs[0].size() && y >= 0 && y < (int)pxs.size())
    {
      pxs[y][x] = v;
    }
  }
  void spx(int x, int y, byte r, byte g, byte b, byte a = 0xFF);
  static void spx(Pixels &px, int x, int y, byte r, byte g, byte b, byte a = 0xFF)
  {
    pixel v = (r << 24) | (g << 16) | (b << 8) | a;
    Image::spx(px, x, y, v);
  }
  pixel gpx(int x, int y);
  static pixel gpx(Pixels &pxs, int x, int y)
  {
    if (x >= 0 && x < (int)pxs[0].size() && y >= 0 && y < (int)pxs.size())
    {
      return pxs[y][x];
    }
    return 0x000000FF;
  }
  void setpxs(byte* rgb, byte* alpha = nullptr);
  static byte R(pixel p)
  {
    return (p >> 24) & 0xFF;
  }
  static byte G(pixel p)
  {
    return (p >> 16) & 0xFF;
  }
  static byte B(pixel p)
  {
    return (p >> 8) & 0xFF;
  }
  static byte A(pixel p)
  {
    return p & 0xFF;
  }
  static byte T(int c)
  {
    return std::min(std::max(0, c), 255);
  }

  byte* data();
  byte* alpha();

  static byte grayperceptual(pixel px)
  {
    int g = (0.299 * R(px) + 0.587 * G(px) + 0.114 * B(px));
    return (byte)std::min(255, g);
  }

  static byte grayaverage(pixel px)
  {
    int g = (R(px) + G(px) + B(px))/3;
    return (byte)std::min(255, g);
  }

  void rmwatermarkpostcard();
  Image rmwatermarkpostcardc();

  void channelred();
  Image channelredc();
  void channelgreen();
  Image channelgreenc();
  void channelblue();
  Image channelbluec();
  void channelalpha();
  Image channelalphac();
  void channelrgba(uint32_t c);
  Image channelrgbac(uint32_t c);

  void grayscaleaverage();
  Image grayscaleaveragec();
  void grayscaleperceptual();
  Image grayscaleperceptualc();

  void mosaic(int size);
  Image mosaicc(int size);

  void threshold(int th, bool inv = false);
  Image thresholdc(int th, bool inv = false);

  void brightness(int br);
  Image brightnessc(int br);
};