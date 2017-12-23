/*

 SRC/ZILOG_SPRITES.C

 Tile Source File.

 Info:
  Form                 : All tiles as one unit.
  Format               : Gameboy 4 color.
  Compression          : None.
  Counter              : None.
  Tile size            : 8 x 16
  Tiles                : 0 to 12

  Palette colors       : Included.
  SGB Palette          : None.
  CGB Palette          : 1 Byte per entry.

  Convert to metatiles : No.

 This file was generated by GBTD v2.2

*/

/* */

	#include "Zilog_Sprites.h"

	const int Zilog_SpritesPAL[] = 

	{

	Zilog_SpritesCGBPal0c0,Zilog_SpritesCGBPal0c1,Zilog_SpritesCGBPal0c2,Zilog_SpritesCGBPal0c3,

	Zilog_SpritesCGBPal1c0,Zilog_SpritesCGBPal1c1,Zilog_SpritesCGBPal1c2,Zilog_SpritesCGBPal1c3,

	Zilog_SpritesCGBPal2c0,Zilog_SpritesCGBPal2c1,Zilog_SpritesCGBPal2c2,Zilog_SpritesCGBPal2c3,

	Zilog_SpritesCGBPal3c0,Zilog_SpritesCGBPal3c1,Zilog_SpritesCGBPal3c2,Zilog_SpritesCGBPal3c3,

	Zilog_SpritesCGBPal4c0,Zilog_SpritesCGBPal4c1,Zilog_SpritesCGBPal4c2,Zilog_SpritesCGBPal4c3,

	Zilog_SpritesCGBPal5c0,Zilog_SpritesCGBPal5c1,Zilog_SpritesCGBPal5c2,Zilog_SpritesCGBPal5c3,

	Zilog_SpritesCGBPal6c0,Zilog_SpritesCGBPal6c1,Zilog_SpritesCGBPal6c2,Zilog_SpritesCGBPal6c3,

	Zilog_SpritesCGBPal7c0,Zilog_SpritesCGBPal7c1,Zilog_SpritesCGBPal7c2,Zilog_SpritesCGBPal7c3,

	};/* */
const unsigned  char Zilog_SpritesCGB[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00
};
/* Start of tile array. */
const unsigned  char Zilog_Sprites[] =
{
  0x00,0x00,0x3F,0x3F,0x40,0x7F,0x40,0x7F,
  0x46,0x7F,0x49,0x79,0x49,0x79,0x46,0x7F,
  0x40,0x7F,0x40,0x7F,0x21,0x3F,0x22,0x3E,
  0x22,0x3E,0x22,0x3E,0x1C,0x1C,0x00,0x00,
  0x00,0x00,0x83,0x83,0x4C,0xCF,0x30,0xFF,
  0x21,0xFF,0x42,0xFE,0x42,0xFE,0x44,0xFC,
  0x44,0xFC,0x44,0xFC,0xA2,0xBE,0x21,0x3F,
  0x10,0x1F,0x08,0x0F,0x07,0x07,0x00,0x00,
  0x03,0x03,0xF2,0xF3,0x0A,0xFB,0x06,0xFF,
  0xC2,0xFF,0x22,0x3F,0x12,0x1F,0x12,0x1F,
  0x12,0x1F,0x22,0x3F,0x22,0x3F,0xC2,0xFF,
  0x06,0xFF,0x19,0xF9,0xE0,0xE0,0x00,0x00,
  0x80,0x80,0x46,0xC6,0x49,0xCF,0x51,0xDF,
  0x51,0xDF,0x21,0xFF,0x01,0xFF,0x00,0xFF,
  0x00,0xFF,0x08,0xFF,0x14,0xF7,0x14,0xF7,
  0x24,0xE7,0xC4,0xC7,0x03,0x03,0x00,0x00,
  0x00,0x00,0x01,0x01,0x1D,0x1D,0x22,0x3F,
  0x22,0x3F,0x46,0x7F,0x44,0x7F,0x84,0xFF,
  0x0C,0xFF,0x14,0xF7,0x14,0xF7,0x24,0xE7,
  0x24,0xE7,0x46,0xC7,0x81,0x81,0x00,0x00,
  0x00,0x00,0xF9,0xF9,0x06,0xFF,0x02,0xFF,
  0x7E,0xFF,0x42,0xC3,0x7A,0xFB,0x06,0xFF,
  0x06,0xFF,0x7A,0xFB,0x84,0x87,0x74,0xF7,
  0x0C,0xFF,0x0A,0xFB,0xF9,0xF9,0x00,0x00,
  0x00,0x00,0xFC,0xFC,0x02,0xFE,0x01,0xFF,
  0x30,0xFF,0x28,0xEF,0x30,0xFF,0x00,0xFF,
  0x03,0xFF,0x05,0xFD,0x03,0xFF,0x21,0xFF,
  0x51,0xDF,0x49,0xCF,0x8E,0x8E,0x00,0x00,
  0x00,0x00,0x7E,0x7E,0x41,0x7F,0x80,0xFF,
  0x9E,0xFF,0x91,0xF1,0x8E,0xFE,0x81,0xFF,
  0x01,0xFF,0x3E,0xFE,0x20,0xE0,0x1C,0xFC,
  0x02,0xFE,0x82,0xFE,0x7E,0x7E,0x00,0x00,
  0x00,0x00,0x7F,0x7F,0x80,0xFF,0x80,0xFF,
  0x86,0xFF,0x89,0xF9,0x88,0xF8,0x88,0xF8,
  0x48,0x78,0x48,0x78,0x49,0x79,0x46,0x7F,
  0x40,0x7F,0x40,0x7F,0x3F,0x3F,0x00,0x00,
  0x00,0x00,0x80,0x80,0x40,0xC0,0x20,0xE0,
  0x10,0xF0,0x10,0xF0,0x90,0xF0,0x90,0xF0,
  0x90,0xF0,0x90,0xF0,0x10,0xF0,0x10,0xF0,
  0x20,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0F,0x0F,0x10,0x1F,0x10,0x1F,
  0x11,0x1F,0x12,0x1E,0x11,0x1F,0x10,0x1F,
  0x10,0x1F,0x10,0x1F,0x09,0x0F,0x08,0x0F,
  0x08,0x0F,0x08,0x0F,0x07,0x07,0x00,0x00,
  0x00,0x00,0xE0,0xE0,0x18,0xF8,0x26,0xFE,
  0xA1,0xFF,0x50,0x7F,0x88,0xFF,0x16,0xF7,
  0x09,0xF9,0xC4,0xFC,0x24,0x3C,0xC4,0xFC,
  0x04,0xFC,0x18,0xF8,0xE0,0xE0,0x00,0x00,
  0x38,0x38,0x48,0x78,0x48,0x78,0x48,0x78,
  0x88,0xF8,0x08,0xF8,0x08,0xF8,0x10,0xF0,
  0x88,0xF8,0x48,0x78,0x44,0x7C,0x44,0x7C,
  0x24,0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00
};

/* End of SRC/ZILOG_SPRITES.C */
