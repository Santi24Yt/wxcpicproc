# Proceso Digital de Imagenes

Código fuente: [GitHub](https://github.com/Santi24Yt/wxcpicproc)

[App (linux)](https://github.com/Santi24Yt/wxcpicproc/releases/latest)

---------------------

## Tarea 1

- Componente RGB (mica)

Filters > Channels > RGB

[Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L79)

![micargb1](resources/screenshots/micargb1.png)
![micargb2](resources/screenshots/micargb2.png)

- Mosaico

Filters > Mosaic

[Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L138)

![mosaico1](resources/screenshots/mosaico1.png)
![mosaico2](resources/screenshots/mosaico2.png)

- Color a tono de gris
  - `(R+G+B)/3`

    Filters > Grayscale > Average

  [Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L98)

  ![grayavg](resources/screenshots/grayavg.png)

  - `R*0.299 + G*0.587 + B*0.114` [valores LUMA](https://en.wikipedia.org/wiki/Grayscale#Luma_coding_in_video_systems)

    Filters > Grayscale > Perceptual

  [Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L118)

  ![graypercep](resources/screenshots/graypercep.png)

Comparación (bajón de calidad por compresión de gif)

![graycomp](resources/screenshots/graycomp.gif)

- Alto contraste

Filters > Contrast > High Contrast

[Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L193)  con valor `128` (mitad)

![hcontr](resources/screenshots/hcontr.png)

- Inverso del Alto contraste (negativo)

Filters > Contrast > Negative

*Misma función pero con la opción de invertido activada*

![neg](resources/screenshots/neg.png)

- Rojo, Verde, Azul, Alpha (extra)

Filters > Channels > Red/Green/Blue/Alpha

  - Rojo

  [Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L3)

  ![redc](resources/screenshots/redc.png)

  - Verde

  [Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L22)

  ![greenc](resources/screenshots/greenc.png)

  - Azul

  [Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L41)

  ![bluec](resources/screenshots/bluec.png)

  - Alpha (extra)

  [Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L60)

  ![alphac](resources/screenshots/alphac.png)

- Brillo (sumar/restar)

Filters > Brightness

[Función](https://github.com/Santi24Yt/wxcpicproc/blob/15cdf6e72c51f5620ae3a33739d39366522fa616/libs/image/filters/common.cpp#L226)

![bright1](resources/screenshots/bright1.png)
![bright2](resources/screenshots/bright2.png)
![bright3](resources/screenshots/bright3.png)