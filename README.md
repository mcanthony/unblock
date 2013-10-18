### UnBlock

Remove 8x8-pixel "blocky" artifacts from a heavily compressed JPEG image.

### How to build on Ubuntu

`make`

### How to run

`./unblock in.bmp out.bmp`

`./unblock in.png out.png`

### Software used

This is a wrapper around an algorithm by John Costella.
His [webpage](http://johncostella.webs.com/unblock/)
includes before-and-after pictures showing the algorithm's effectiveness.

Instead of porting John's C# source code to C/C++,
I built on Alexander Balakhnin's C port,
in the context of a [plugin](http://avisynth.org.ru/unblock/unblock.html)
for [AviSynth](http://sourceforge.net/projects/avisynth2/),
based on John's own 2007 C port of "the Costella libraries."

Files in .bmp format are read and written by [EasyBMP](http://easybmp.sourceforge.net/),
files in .png format by [libpng](http://www.libpng.org/pub/png/libpng.html).
Why not .jpg for a JPEG utility?
Because my source images are still frames from mjpeg-format video;
extracting frames as bmp rather than jpg with, say, ffmpeg, avoids further degradation.

### Bugs

Images whose width is not a multiple of 16 pixels may misbehave.
