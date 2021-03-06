/*

 SRC/TOWER_ANIM_TILES.B9.C

 Tile Source File.

 Info:
  Form                 : All tiles as one unit.
  Format               : Gameboy 4 color.
  Compression          : None.
  Counter              : None.
  Tile size            : 8 x 8
  Tiles                : 0 to 239

  Palette colors       : Included.
  SGB Palette          : None.
  CGB Palette          : 1 Byte per entry.

  Convert to metatiles : No.

 This file was generated by GBTD v2.2

*/

/* */

	#include "tower_anim_tiles.h"

	const int tower_anim_tilesPAL[] = 

	{

	tower_anim_tilesCGBPal0c0,tower_anim_tilesCGBPal0c1,tower_anim_tilesCGBPal0c2,tower_anim_tilesCGBPal0c3,

	tower_anim_tilesCGBPal1c0,tower_anim_tilesCGBPal1c1,tower_anim_tilesCGBPal1c2,tower_anim_tilesCGBPal1c3,

	tower_anim_tilesCGBPal2c0,tower_anim_tilesCGBPal2c1,tower_anim_tilesCGBPal2c2,tower_anim_tilesCGBPal2c3,

	tower_anim_tilesCGBPal3c0,tower_anim_tilesCGBPal3c1,tower_anim_tilesCGBPal3c2,tower_anim_tilesCGBPal3c3,

	tower_anim_tilesCGBPal4c0,tower_anim_tilesCGBPal4c1,tower_anim_tilesCGBPal4c2,tower_anim_tilesCGBPal4c3,

	tower_anim_tilesCGBPal5c0,tower_anim_tilesCGBPal5c1,tower_anim_tilesCGBPal5c2,tower_anim_tilesCGBPal5c3,

	tower_anim_tilesCGBPal6c0,tower_anim_tilesCGBPal6c1,tower_anim_tilesCGBPal6c2,tower_anim_tilesCGBPal6c3,

	tower_anim_tilesCGBPal7c0,tower_anim_tilesCGBPal7c1,tower_anim_tilesCGBPal7c2,tower_anim_tilesCGBPal7c3,

	};/* */
const unsigned  char tower_anim_tilesCGB[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
/* Start of tile array. */
const unsigned  char tower_anim_tiles[] =
{
  0xEF,0xFF,0xFD,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFE,0xFF,0xD4,0xFF,0xEC,0xFF,
  0x15,0xFF,0x9F,0xF7,0x06,0xFF,0xF7,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xEA,0xFF,0xFC,0xFF,
  0x6C,0xB3,0x1D,0xE2,0x8F,0xF0,0xCB,0xF4,
  0xFF,0xFF,0xFF,0xFF,0x7E,0xBF,0x7A,0xBF,
  0xE7,0xF0,0xEF,0xF0,0xE7,0xF8,0xF9,0xFE,
  0xFF,0xFF,0xFF,0xFF,0x81,0xFF,0x1F,0xE1,
  0xF7,0x07,0x37,0x07,0x37,0x07,0xFF,0x07,
  0xFF,0xFF,0xFF,0xFF,0x8A,0xF5,0xCF,0xB0,
  0x0C,0x00,0x02,0x00,0xEF,0x00,0x3E,0xC1,
  0xFF,0xFF,0xFF,0xFF,0x3F,0xFC,0xFF,0x1C,
  0xEB,0x60,0xEF,0x60,0xFE,0x61,0xFF,0xFF,
  0xFF,0xFF,0x9F,0xFF,0xF7,0x0F,0xFB,0x07,
  0xBB,0x67,0xBB,0x67,0x2F,0xFF,0xFF,0xFF,
  0xFD,0xFF,0xCD,0x3F,0xE5,0x1F,0xF7,0x0D,
  0xB6,0xFF,0xD7,0xFF,0xB5,0xFF,0xDD,0xFF,
  0xAE,0xFF,0xF6,0xFF,0xAB,0xFF,0xFB,0xFF,
  0x25,0xFE,0xB2,0xFF,0x2A,0xF7,0xB7,0xFB,
  0xA9,0xF7,0xA9,0xF7,0x60,0xFF,0x25,0xFE,
  0x7C,0xBF,0x79,0xBE,0x1F,0xFC,0x78,0xBE,
  0x9F,0xFC,0x3F,0xFC,0x9B,0xFC,0xBF,0xFC,
  0x7B,0x81,0xB1,0x41,0xDF,0x21,0xD5,0x21,
  0x49,0x31,0xF5,0x09,0xD5,0x29,0x7D,0x81,
  0x9E,0xE0,0xFA,0xC0,0xEA,0xC0,0xE3,0xC0,
  0xE1,0xC0,0x81,0xC0,0x8C,0xC0,0xC0,0xC0,
  0x3F,0x1C,0x1F,0x1C,0x5C,0x1C,0x3D,0x1C,
  0x1C,0x1C,0xFD,0x1C,0x9C,0x1C,0x7C,0x1C,
  0x57,0x03,0x9F,0x03,0xAF,0x03,0x57,0x03,
  0xAF,0x03,0xBF,0x03,0xCF,0x03,0x77,0x03,
  0xF5,0x0F,0xF7,0x0D,0xF7,0x0D,0xF5,0x0F,
  0xF3,0x0D,0xF5,0x0F,0xF7,0x0D,0xF5,0x0F,
  0xCE,0xFF,0xEF,0xFF,0xFE,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xBE,0xFF,0xAB,0xFE,0xB6,0xFF,
  0xAA,0xFF,0x2E,0xFF,0x0F,0xFF,0xFF,0xEF,
  0xFF,0xFF,0xFF,0xFF,0xE8,0xFF,0xDC,0xFF,
  0xD9,0x67,0x1B,0xE5,0x1F,0xE1,0x8B,0xF5,
  0xFF,0xFF,0xFF,0xFF,0xFE,0x3F,0x74,0xBF,
  0xBD,0xE2,0x9E,0xE0,0xE6,0xF8,0xD5,0xFA,
  0xFF,0xFF,0xFF,0xFF,0x83,0xFF,0x3F,0xC3,
  0xEE,0x0E,0x6E,0x0E,0x6F,0x0E,0xFE,0x0F,
  0xFF,0xFF,0xFF,0xFF,0x84,0xFB,0x9F,0xE0,
  0x1C,0x00,0x01,0x00,0xDF,0x00,0x7F,0x81,
  0xFF,0xFF,0xFF,0xFF,0x3F,0xF8,0xFF,0x38,
  0xCF,0xC0,0xD7,0xC0,0xFF,0xC0,0xDF,0xFF,
  0xFF,0xFF,0xBF,0xFE,0xE7,0x1E,0xFF,0x06,
  0xF9,0x67,0x73,0xEF,0x6F,0xFF,0xFF,0xFF,
  0xFD,0xFF,0xCD,0x3F,0xAD,0x5F,0xFD,0x0F,
  0xBA,0xFF,0x94,0xFF,0xBC,0xFF,0xD6,0xFF,
  0xBB,0xFE,0xAE,0xFF,0xB4,0xFF,0xAC,0xFF,
  0xB6,0xFD,0x44,0xFF,0xB4,0xEF,0xAE,0xF7,
  0xB1,0xEF,0xB3,0xEF,0xA1,0xFF,0xAA,0xFD,
  0xF8,0x3F,0x7B,0xBC,0x73,0xBC,0x7A,0xBC,
  0x72,0xBC,0x7F,0xB8,0xF7,0xB8,0xFE,0xB9,
  0x73,0x83,0xFB,0x03,0x3F,0xC3,0xB7,0x43,
  0x9B,0x63,0xCB,0x33,0xEF,0x13,0x7F,0x83,
  0xBD,0xC0,0xF4,0x80,0xE4,0x80,0xC6,0x80,
  0xC2,0x80,0xC3,0x80,0x98,0x80,0x88,0x80,
  0x7F,0x38,0x3D,0x38,0x3D,0x38,0xBC,0x38,
  0x39,0x38,0xB9,0x38,0xB9,0x38,0xF8,0x38,
  0x7F,0x06,0x1F,0x06,0x57,0x06,0x9F,0x06,
  0xAE,0x06,0x6F,0x06,0x56,0x06,0x6F,0x06,
  0xF9,0x0F,0xFD,0x0F,0xFD,0x0F,0xF5,0x0F,
  0x7D,0x8F,0xF5,0x0F,0xFD,0x0F,0xB5,0x4F,
  0xEE,0xFF,0x8B,0xFF,0xFE,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xDD,0xFF,0xE9,0xFF,0xED,0xFF,
  0x7A,0xEF,0x3C,0xEF,0x0F,0xFF,0xED,0xFF,
  0xFF,0xFF,0xFD,0xFF,0xD4,0xFF,0xFA,0xFD,
  0x73,0xCD,0xB0,0xCD,0x37,0xC9,0x17,0xE9,
  0xFF,0xFF,0xFF,0xFF,0xED,0x7F,0xFC,0x7F,
  0xFB,0xC4,0xFC,0xC0,0xAE,0xF0,0xDB,0xF4,
  0xFF,0xFF,0xFF,0xFF,0x0F,0xF7,0x7F,0x87,
  0xFE,0x1C,0x5E,0x1C,0xFF,0x1C,0xFC,0x1F,
  0xFF,0xFF,0xFF,0xFF,0x08,0xF7,0x3F,0xC0,
  0x39,0x01,0x83,0x01,0xBF,0x01,0xFD,0x03,
  0xFF,0xFF,0xFF,0xFF,0x7F,0xF0,0xFF,0x70,
  0xDF,0xC0,0xE7,0xC0,0xFE,0xC1,0xEF,0xFF,
  0xFF,0xFF,0xFF,0xFE,0xCF,0x3E,0xFF,0x0E,
  0xF7,0x4B,0x73,0xCF,0x6F,0xDF,0xFF,0xFF,
  0xFF,0xFF,0x9D,0x7F,0xCD,0x3F,0xFD,0x0F,
  0xF5,0xFF,0xEF,0xFF,0xF5,0xFF,0xD7,0xFF,
  0xFB,0xFF,0xED,0xFF,0xEF,0xFF,0xF3,0xFF,
  0x29,0xFE,0x48,0xFF,0x5C,0xEF,0x72,0xEF,
  0x46,0xFF,0x05,0xFF,0x41,0xFF,0xD9,0xFF,
  0x68,0xFF,0xEE,0x79,0xF7,0x78,0xFF,0x78,
  0x67,0xF8,0xF7,0x78,0x6F,0xF0,0xFC,0x73,
  0xF7,0x07,0x77,0x87,0x7F,0x87,0x2F,0xC7,
  0xBD,0x47,0x17,0xE7,0xCF,0x37,0xEF,0x17,
  0x3C,0xC0,0x68,0x80,0x2C,0x80,0x0C,0x80,
  0x06,0x80,0x87,0x00,0x91,0x00,0x14,0x00,
  0xFE,0x70,0x7E,0x70,0x7A,0x70,0x79,0x70,
  0x7A,0x70,0x75,0x70,0xF1,0x70,0xF0,0x70,
  0xBD,0x0E,0x1D,0x0E,0xAD,0x0E,0x3D,0x0E,
  0xAD,0x0E,0xBF,0x0E,0x5D,0x0E,0x4D,0x0E,
  0xFD,0x0F,0xF5,0x0F,0xED,0x1F,0xF5,0x0F,
  0xFF,0x0D,0xFD,0x0F,0xFF,0x0D,0xBD,0x4F,
  0xDD,0xFF,0xFE,0xFF,0xFD,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xDD,0xFF,0xB5,0xFF,0xD9,0xFF,
  0x16,0xFD,0x1C,0xFF,0x1E,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFD,0xFF,0xD1,0xFE,0xF1,0xFE,
  0xA7,0xDB,0x67,0x9B,0x7F,0x83,0x0F,0xF3,
  0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xF4,0xFF,
  0xFF,0x80,0xF0,0x88,0xDD,0xE0,0xEB,0xF4,
  0xFF,0xFF,0xFF,0xFF,0x0E,0xFF,0xFE,0x0F,
  0xFC,0x38,0xFC,0x38,0xFF,0x38,0xF9,0x3E,
  0xFF,0xFF,0xFF,0xFF,0x08,0xF7,0x7F,0x80,
  0xF3,0x03,0x07,0x03,0xB7,0x03,0xFB,0x07,
  0xFF,0xFF,0xFF,0xFF,0x77,0xE8,0xFF,0x60,
  0xBF,0x80,0xCF,0x80,0xFE,0x81,0x8F,0xFF,
  0xFF,0xFF,0xFF,0xFC,0x5F,0xBC,0xEF,0x1C,
  0xF3,0xCF,0xF3,0xCF,0xCF,0xFF,0xFF,0xFF,
  0xF9,0xFF,0xBD,0x7B,0xBD,0x5B,0xED,0x1B,
  0xEC,0xFF,0xE9,0xFF,0xD8,0xFF,0xED,0xFF,
  0xD8,0xFF,0xEF,0xFD,0xB4,0xFF,0xD9,0xFF,
  0x5C,0xFB,0x49,0xFE,0x8C,0xFF,0x65,0xDE,
  0xEE,0xDF,0x44,0xFF,0x92,0xFF,0xD6,0xFB,
  0xD0,0xFF,0xE6,0xF9,0xFE,0xF1,0xBE,0xF1,
  0xEF,0xF0,0xEF,0xF0,0xED,0xF2,0x6D,0xF2,
  0xEF,0x0F,0xFE,0x0F,0x7E,0x8F,0x6E,0x8F,
  0x7E,0x8F,0x3F,0xCE,0x1F,0xEE,0xDF,0x2E,
  0x7C,0x80,0xF0,0x00,0x98,0x00,0x98,0x00,
  0x8C,0x00,0x0E,0x00,0x23,0x00,0x39,0x00,
  0xFC,0x60,0xFC,0x60,0x74,0x60,0x72,0x60,
  0x72,0x60,0xF3,0x60,0x74,0x60,0xF1,0x60,
  0xBF,0x0C,0x1F,0x0C,0xED,0x0C,0x3F,0x0C,
  0x5F,0x0C,0xDF,0x0C,0x3D,0x0C,0x9D,0x0C,
  0xED,0x1B,0xED,0x1B,0xFD,0x0B,0xED,0x1B,
  0xED,0x1B,0xFD,0x0B,0xED,0x1B,0xED,0x1B,
  0xDC,0xFF,0xD6,0xFF,0xFC,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xDB,0xFF,0xB3,0xFF,0xDF,0xFF,
  0xB9,0xFF,0xB5,0xFF,0x3C,0xFF,0xF7,0xFF,
  0xFF,0xFF,0xFD,0xFF,0xA3,0xFD,0x71,0xFF,
  0x67,0x9F,0x6F,0x97,0x9F,0x67,0x5F,0xA7,
  0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xE8,0xFF,
  0xEF,0x10,0x79,0x80,0x1B,0xE0,0xD7,0xE8,
  0xFF,0xFF,0xFF,0xFF,0x1C,0xFF,0xFD,0x1F,
  0xF9,0x70,0xFA,0x70,0xF7,0x78,0xF3,0x7C,
  0xFF,0xFF,0xFF,0xFF,0x12,0xEF,0xBF,0x40,
  0x67,0x03,0x03,0x03,0x7F,0x03,0xFB,0x07,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xEF,0xD0,
  0x1E,0x01,0xAA,0x01,0xFC,0x03,0x0F,0xFF,
  0xFF,0xFF,0xFF,0xF8,0x1F,0xF8,0xFF,0x18,
  0xBB,0x87,0xE7,0x9F,0xCF,0xBF,0xFF,0xFF,
  0xF9,0xFF,0x39,0xFF,0xBB,0x5D,0xFD,0x1B,
  0xEA,0xFF,0xF6,0xFF,0xDA,0xFF,0xEE,0xFF,
  0xDA,0xFF,0xED,0xFF,0xDA,0xFF,0xEF,0xFF,
  0xA3,0xFD,0x88,0xFF,0x98,0xFF,0x94,0xFF,
  0xB9,0xDF,0x0C,0xFF,0x97,0xFF,0x62,0xFF,
  0xA1,0xFE,0xED,0xF2,0xCC,0xF3,0xCC,0xF3,
  0xFE,0xE1,0x7E,0xE1,0xDA,0xE5,0xF9,0xE6,
  0xDE,0x1F,0xFF,0x1E,0xFF,0x1E,0xFF,0x1E,
  0x7F,0x9E,0x7C,0x9E,0xBC,0x5E,0x9E,0x7C,
  0xF1,0x00,0xF0,0x00,0x30,0x00,0x18,0x00,
  0x18,0x00,0x1E,0x00,0x66,0x00,0x62,0x00,
  0xFD,0xC0,0xF8,0xC0,0xC4,0xE0,0xC0,0xE0,
  0xE6,0xC0,0xEA,0xC0,0xE5,0xC0,0xE0,0xC0,
  0x7F,0x18,0xBB,0x18,0x7B,0x18,0x5B,0x18,
  0xBB,0x18,0xDB,0x18,0x3B,0x18,0x99,0x18,
  0xFB,0x1D,0xED,0x1B,0xFB,0x1D,0xEB,0x1D,
  0xFD,0x1B,0xFB,0x1D,0xFD,0x1B,0xFD,0x1B,
  0x9B,0xFF,0xDC,0xFF,0xF8,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xAB,0xFF,0xDB,0xFF,0xF3,0xFF,
  0xF2,0xBF,0xBA,0xFF,0x7C,0xBF,0xF6,0xFF,
  0xFF,0xFF,0xFB,0xFF,0x57,0xF9,0xA3,0xFD,
  0x8E,0x7F,0xDA,0x2F,0x9F,0x6F,0x5F,0xAF,
  0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xD1,0xFE,
  0xFF,0x00,0x93,0x60,0x77,0x80,0xAF,0xD0,
  0xFF,0xFF,0xFF,0xFF,0x38,0xFF,0xFA,0x3F,
  0x63,0x70,0x78,0x60,0x6E,0x70,0xE3,0x7C,
  0xFF,0xFF,0xFF,0xFF,0x01,0xFF,0xFF,0x01,
  0xC7,0x06,0x4F,0x06,0xBF,0x06,0xF6,0x0F,
  0xFF,0xFF,0xFF,0xFF,0xEE,0xD1,0xFF,0xC0,
  0x3B,0x01,0x5F,0x01,0xFD,0x03,0x4F,0xBF,
  0xFF,0xFF,0xFD,0xFA,0x3F,0xF8,0xFF,0x38,
  0xFF,0x87,0xE7,0x9F,0x8F,0xFF,0xFF,0xFF,
  0xFD,0xF7,0x79,0xF7,0x9D,0x73,0xF9,0x17,
  0xA9,0xFF,0xB1,0xFF,0xD9,0xFF,0xE9,0xFF,
  0xD9,0xFF,0xD1,0xFF,0xB9,0xFF,0xEB,0xFF,
  0x63,0xFD,0x33,0xFD,0x99,0xFF,0x0B,0xFD,
  0x99,0xFF,0x0F,0xFD,0xAF,0xFD,0x67,0xFD,
  0xE3,0xFC,0x89,0xF6,0x59,0xE6,0xD8,0xE7,
  0x5C,0xE3,0x7C,0xC3,0xF5,0xCA,0xF3,0xCC,
  0xBD,0x3E,0xFF,0x3C,0xFF,0x3C,0xFE,0x3C,
  0xFE,0x3C,0x7A,0xBC,0x38,0xFC,0xB8,0x7C,
  0xF3,0x01,0xE1,0x01,0x61,0x01,0x31,0x01,
  0x39,0x01,0x3D,0x01,0xCD,0x01,0xE7,0x01,
  0xF9,0xC0,0xF0,0xC0,0xE8,0xC0,0xE8,0xC0,
  0xC9,0xC0,0xCC,0xC0,0xC5,0xC0,0xC1,0xC0,
  0xFF,0x38,0x7F,0x38,0xBB,0x38,0x7B,0x38,
  0xBF,0x38,0xFF,0x38,0x3B,0x38,0x3B,0x38,
  0xD3,0x35,0xF3,0x15,0xF9,0x17,0xFD,0x13,
  0xFB,0x15,0xF3,0x15,0xF9,0x17,0xF1,0x17,
  0xEA,0xFF,0xFD,0xFF,0xF4,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xD7,0xFF,0xFF,0xFF,0xD6,0xFF,
  0x67,0xFE,0x7C,0xFF,0x71,0xFE,0xFC,0xFF,
  0xFF,0xFF,0xF3,0xFF,0x47,0xFB,0xE7,0xFB,
  0x9F,0x7E,0x8F,0x7E,0x3F,0xDF,0xBD,0x5F,
  0xFF,0xFF,0xFF,0xFF,0xF8,0xFF,0xAB,0xFC,
  0xBF,0x40,0xA6,0x40,0x76,0x80,0x57,0xA8,
  0xFF,0xFF,0xFF,0xFF,0x74,0xBF,0xF0,0x3F,
  0xE3,0xE0,0xF4,0xE0,0xFE,0xE0,0xE7,0xF8,
  0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,
  0x8E,0x0E,0x9E,0x0E,0x6F,0x0E,0xEE,0x1F,
  0xFF,0xFF,0xFF,0xFF,0xDC,0xA3,0xFF,0x80,
  0xBF,0x01,0xAD,0x03,0xFD,0x03,0x4F,0xBF,
  0xFF,0xFF,0xFE,0xF1,0x7F,0xF0,0xFF,0x30,
  0xEF,0x15,0xF7,0x0D,0x8F,0x7F,0xFF,0xFF,
  0xF3,0xFF,0x79,0xF7,0x7B,0xB5,0xDD,0x33,
  0xFB,0xFF,0xA9,0xFF,0xFA,0xFF,0xAD,0xFF,
  0xF5,0xFF,0xDA,0xFF,0xED,0xFF,0xEE,0xFF,
  0x42,0xFF,0x73,0xFF,0x13,0xFF,0x31,0xFF,
  0x2B,0xFF,0x3F,0xFB,0x4A,0xFF,0xCA,0xFF,
  0xC7,0xF8,0x63,0xDC,0xF1,0xCE,0x71,0xCE,
  0x78,0xC7,0xB8,0xC7,0xEA,0x95,0xA6,0xD9,
  0xA9,0x3E,0xEF,0x38,0xEE,0x38,0xE8,0x3C,
  0xEC,0x38,0xAC,0x38,0x29,0xB8,0x69,0xB8,
  0xE5,0x03,0xC3,0x03,0xE1,0x03,0x61,0x03,
  0x73,0x03,0x73,0x03,0xD9,0x03,0xEF,0x03,
  0xB1,0xC0,0xD0,0x80,0xE5,0x80,0xD0,0x80,
  0xC9,0x80,0x85,0x80,0x98,0x80,0x86,0x80,
  0xFF,0x30,0x77,0x30,0xB6,0x30,0xF7,0x30,
  0x77,0x30,0x77,0x30,0xFD,0x30,0x77,0x30,
  0xDB,0x35,0xDD,0x33,0xDB,0x35,0xDD,0x33,
  0xFB,0x35,0xD9,0x37,0xDD,0x33,0xDD,0x33,
  0xB7,0xFF,0xB9,0xFF,0xF8,0xFF,0xFF,0xFF,
  0xF7,0xFF,0xB7,0xFF,0xE6,0xFF,0xB7,0xFF,
  0xE5,0x7E,0xF5,0x7E,0x79,0xFE,0xF4,0xFF,
  0xFF,0xFF,0xE7,0xFF,0xA7,0xFF,0xCF,0xF7,
  0x3F,0xDC,0x39,0xDE,0x7C,0x9F,0x7F,0x9F,
  0xFF,0xFF,0xFF,0xFF,0xF0,0xFF,0x57,0xF8,
  0x3B,0xC5,0x4D,0x81,0xEF,0x01,0x2F,0xD1,
  0xFF,0xFF,0xFF,0xFF,0xF8,0x7F,0xFA,0x7D,
  0xE5,0xC0,0xEC,0xC0,0xFD,0xC0,0xCF,0xF0,
  0xFF,0xFF,0xFF,0xFF,0x07,0xFF,0xFF,0x07,
  0x9C,0x1C,0x1E,0x1C,0xFF,0x1C,0xFC,0x1F,
  0xFF,0xFF,0xFF,0xFF,0x74,0x8B,0xBF,0x40,
  0x37,0x03,0xBF,0x03,0xFB,0x07,0xCF,0x3F,
  0xFF,0xFF,0xFE,0xE1,0xFE,0xE1,0xFF,0x60,
  0xF7,0x0D,0xED,0x1F,0x0F,0xFF,0xFF,0xFF,
  0xF3,0xFF,0xF1,0xFF,0xB9,0x77,0xF9,0x37,
  0xE2,0xFF,0xB5,0xFF,0xE5,0xFF,0xF2,0xFF,
  0xD6,0xFF,0xB3,0xFF,0xE5,0xFF,0xB5,0xFF,
  0x86,0xFF,0x77,0xFF,0x52,0xFF,0x67,0xFF,
  0x35,0xFF,0x37,0xFF,0xDD,0xFF,0x57,0xFF,
  0x87,0xF8,0xA3,0xDC,0xE3,0x9C,0xFB,0x8C,
  0x31,0xCE,0xF0,0x8F,0x48,0xB7,0x4E,0xB1,
  0x7B,0x7C,0xF7,0x78,0xF6,0x78,0xF0,0x78,
  0xF0,0x78,0xF9,0x70,0xFB,0x70,0xFB,0x70,
  0xC7,0x07,0xC7,0x07,0xC7,0x07,0xC7,0x07,
  0xE7,0x07,0xF7,0x07,0xFF,0x07,0x9F,0x07,
  0x65,0x80,0xA0,0x00,0xC5,0x00,0xA0,0x00,
  0x92,0x00,0x8B,0x00,0x30,0x00,0x84,0x00,
  0xFF,0x60,0xEE,0x60,0xEF,0x60,0xE5,0x60,
  0xE7,0x60,0x6F,0x60,0xE7,0x60,0x6B,0x60,
  0xA5,0x7B,0xE5,0x3B,0xF9,0x37,0xE5,0x3B,
  0xF9,0x37,0xFD,0x33,0x61,0x3F,0xFD,0x33,
  0xBE,0xFF,0xB2,0xFF,0xF8,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xBF,0xFF,0xEF,0xFF,0xBD,0xFF,
  0xCA,0xFD,0xFA,0xFD,0xE2,0xFD,0xF8,0xFF,
  0xFF,0xFF,0xC7,0xFF,0x4F,0xF7,0xCF,0xF7,
  0xFA,0xBD,0x72,0xBD,0xFC,0x3F,0x7C,0xBF,
  0xFF,0xFF,0xFF,0xFF,0xE1,0xFE,0x67,0xF8,
  0x7E,0x83,0xDF,0x03,0xFF,0x03,0x6F,0x93,
  0xFF,0xFF,0xFF,0xFF,0xE8,0xFF,0xFD,0xFA,
  0xCE,0x80,0xDA,0x80,0xB1,0xC0,0x8F,0xF0,
  0xFF,0xFF,0xFF,0xFF,0x0F,0xFE,0xFF,0x0E,
  0x38,0x38,0xBA,0x38,0x7F,0x38,0xF9,0x3E,
  0xFF,0xFF,0xFF,0xFF,0x69,0x97,0x7F,0x80,
  0xEE,0x06,0x5F,0x06,0xFF,0x06,0xAF,0x5F,
  0xFF,0xFF,0xED,0xF3,0xFF,0xE0,0xFF,0xE0,
  0xFD,0x0F,0xDD,0x2F,0x4F,0xBF,0xFF,0xFF,
  0xE7,0xFF,0xFB,0xE7,0x37,0xEB,0xB5,0x6B,
  0xEE,0xFF,0xBA,0xFF,0xDA,0xFF,0xDA,0xFF,
  0xFC,0xFF,0xAE,0xFF,0xFB,0xFF,0xDE,0xFF,
  0x85,0xFF,0xED,0xF7,0x5E,0xF7,0x75,0xFF,
  0x5E,0xF7,0x7D,0xF7,0xA6,0xFF,0x9F,0xF7,
  0x8E,0xF0,0x47,0xB8,0x43,0xBC,0x63,0x9C,
  0x63,0x9C,0xA5,0x5E,0xC9,0x36,0x8D,0x72,
  0xF5,0xFA,0xEF,0xF0,0xED,0xF0,0xF9,0xF0,
  0xE9,0xF0,0xE1,0xF0,0xF7,0xE0,0xF7,0xE0,
  0x8E,0x0F,0x8F,0x0E,0x8E,0x0F,0xCE,0x0F,
  0xCF,0x0E,0xEF,0x0E,0xFF,0x0E,0x7F,0x0E,
  0xC3,0x00,0xE0,0x00,0x0B,0x00,0x41,0x00,
  0x05,0x00,0x36,0x00,0x21,0x00,0x08,0x00,
  0xFF,0xE0,0xED,0xE0,0xFD,0xE0,0xEE,0xE0,
  0xEF,0xE0,0xEF,0xE0,0xFB,0xE0,0xEB,0xE0,
  0xB9,0x67,0xF5,0x2B,0xA9,0x67,0xB5,0x6B,
  0xB9,0x67,0x35,0x6B,0x99,0x67,0xB9,0x67,
  0xEB,0xFF,0xFB,0xFF,0xF1,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xAF,0xFF,0xED,0xFF,0xB7,0xFF,
  0xED,0xFB,0xBE,0xF9,0xD0,0xFF,0xF0,0xFF,
  0xFF,0xFF,0xCF,0xFF,0x0F,0xFF,0x9D,0xEF,
  0x74,0xFB,0xF0,0x7F,0xF6,0x7D,0xFD,0x7E,
  0xFF,0xFF,0xFF,0xFF,0xE3,0xFD,0x4F,0xF1,
  0xEF,0x17,0x8F,0x17,0xFF,0x07,0x7F,0x87,
  0xFF,0xFF,0xFF,0xFF,0xD0,0xFF,0xF5,0xFA,
  0x9E,0x00,0xB0,0x00,0x7B,0x80,0x7F,0xC0,
  0xFF,0xFF,0xFF,0xFF,0x0E,0xFD,0xFE,0x0D,
  0xB0,0x30,0x7A,0x30,0x7E,0x30,0xB1,0x7E,
  0xFF,0xFF,0xFF,0xFF,0xB3,0x4F,0xFF,0x00,
  0xEE,0x06,0xBF,0x06,0xF7,0x0E,0x2F,0xDF,
  0xFF,0xFF,0xD9,0xE7,0xFE,0xC1,0xFF,0xC0,
  0xED,0x1F,0xED,0x1F,0x1F,0xFF,0xFF,0xFF,
  0xE7,0xFF,0xFB,0xE7,0x67,0xFB,0xF7,0x6B,
  0xEA,0xFF,0xDB,0xFF,0xE4,0xFF,0xF6,0xFF,
  0xB4,0xFF,0xDD,0xFF,0xE7,0xFF,0xBA,0xFF,
  0xCB,0xFF,0x6B,0xFF,0xCD,0xFF,0xAB,0xFF,
  0xCA,0xFF,0x6A,0xFF,0xAC,0xFF,0xAA,0xFF,
  0x0F,0xF1,0x8F,0x71,0xE7,0x39,0xD7,0x39,
  0xC3,0x3D,0xC3,0x3D,0x91,0x6F,0x8B,0x75,
  0xEB,0xF4,0xFF,0xE0,0xDB,0xE0,0xF3,0xE0,
  0xF3,0xE0,0xD3,0xE0,0xEF,0xC0,0xC7,0xE0,
  0x5D,0x0E,0x0D,0x0E,0x8D,0x0E,0x8D,0x0E,
  0xCC,0x0E,0xCE,0x0C,0xEE,0x0C,0xEE,0x0C,
  0xE3,0x00,0x85,0x00,0x02,0x00,0x15,0x00,
  0x85,0x00,0xAD,0x00,0x42,0x00,0x11,0x00,
  0xFB,0xC0,0xDF,0xC0,0xD5,0xC0,0xDF,0xC0,
  0xCD,0xC0,0xDF,0xC0,0xD6,0xC0,0xD7,0xC0,
  0xFF,0x63,0xF7,0x6B,0xFF,0x63,0xF7,0x6B,
  0xFF,0x63,0xF7,0x6B,0xF9,0x67,0xFB,0x67,
  0xED,0xFF,0xF5,0xFF,0xF1,0xFF,0xFF,0xFF,
  0xDF,0xFF,0xEF,0xFF,0xCD,0xFF,0xE7,0xFF,
  0xA0,0xFF,0xF7,0xFA,0xC1,0xFE,0xF1,0xFE,
  0xFF,0xFF,0x9F,0xFF,0x1F,0xFF,0x9D,0xFF,
  0xE9,0xF6,0xE1,0xFE,0xF1,0xFE,0xFA,0xFD,
  0xFF,0xFF,0xFF,0xFF,0xC7,0xFB,0x4F,0xF3,
  0xEE,0x1F,0x5F,0x2E,0xFE,0x0F,0xBE,0x4F,
  0xFF,0xFF,0xFF,0xFF,0xA0,0xFF,0xE3,0xFC,
  0x3E,0x00,0x70,0x00,0xEB,0x00,0xBF,0xC0,
  0xFF,0xFF,0xFF,0xFF,0x1C,0xFF,0xFD,0x1E,
  0x71,0x70,0xF0,0x70,0x7E,0x70,0x75,0xFA,
  0xFF,0xFF,0xFF,0xFF,0xD7,0x2F,0xFF,0x01,
  0xDD,0x0C,0xBF,0x0C,0xFF,0x0C,0x5F,0xBF,
  0xFF,0xFF,0xEB,0xD7,0xFE,0x81,0xFF,0x80,
  0xED,0x1B,0xCD,0x3B,0x0F,0xFF,0xFF,0xFF,
  0xEF,0xFF,0xF1,0xCF,0xFB,0xC7,0x6F,0xD3,
  0xA5,0xFF,0xA5,0xFF,0xCD,0xFF,0xC4,0xFF,
  0xA5,0xFF,0xA5,0xFF,0xCA,0xFF,0xAB,0xFF,
  0x4A,0xFF,0xCB,0xFE,0x5B,0xFE,0xCA,0xFF,
  0xBB,0xFE,0xD4,0xFF,0xA9,0xFE,0x6D,0xFE,
  0xBF,0xC3,0x0F,0xF3,0xAF,0x73,0xE7,0x3B,
  0x87,0x7B,0x9F,0x7B,0x23,0xDF,0x33,0xCF,
  0x5F,0xE0,0x5E,0xE0,0x7D,0xC2,0x67,0xC0,
  0xE3,0xC0,0x6D,0xC2,0x0F,0xC0,0xAE,0xC0,
  0x3F,0x1C,0x1F,0x1C,0x1E,0x1C,0x1E,0x1C,
  0x9E,0x1C,0x9C,0x1C,0x5C,0x9C,0xDC,0x1C,
  0xCB,0x01,0x0B,0x01,0x85,0x01,0x13,0x01,
  0x4B,0x01,0x9B,0x01,0x45,0x01,0x03,0x01,
  0xF7,0x80,0xDB,0x80,0xD7,0x80,0xBB,0x80,
  0x9D,0x80,0xAE,0x80,0x9B,0x80,0x8F,0x80,
  0xFF,0x43,0xF5,0x4B,0xF7,0x4B,0x4F,0xD3,
  0x79,0xC7,0x6F,0xD3,0xD7,0x4B,0x77,0xCB,
  0xEF,0xFF,0xFB,0xFF,0xF3,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xBF,0xFF,0xDA,0xFF,0xD7,0xFF,
  0xBB,0xF6,0xA1,0xFE,0xE9,0xF6,0xF1,0xFE,
  0xFF,0xFF,0x9F,0xFF,0x3F,0xDF,0x1B,0xFF,
  0xF9,0xE6,0xE2,0xFC,0xE3,0xFC,0xF1,0xFE,
  0xFF,0xFF,0xFF,0xFF,0x4F,0xF3,0xAF,0xD3,
  0x8E,0x6E,0xED,0x0E,0xBD,0x4E,0xFD,0x0F,
  0xFF,0xFF,0xFF,0xFF,0x40,0xFF,0x43,0xFC,
  0x7E,0x00,0xE0,0x00,0xEE,0x00,0x7F,0x80,
  0xFF,0xFF,0xFF,0xFF,0x39,0xFE,0xFB,0x3C,
  0xE1,0xE0,0xE0,0xE0,0xFF,0xE0,0xE7,0xF8,
  0xFF,0xFF,0xFF,0xFF,0x47,0xBF,0xFF,0x03,
  0xB9,0x18,0xBF,0x18,0xFF,0x18,0x5F,0xBF,
  0xFF,0xFF,0xE3,0x9F,0xFC,0x83,0xFF,0x80,
  0xED,0x1B,0xC9,0x3F,0x1F,0xFF,0xFF,0xFF,
  0xEF,0xFF,0xF7,0xCF,0xEB,0xD7,0xFB,0xC7,
  0xED,0xFF,0xD5,0xFF,0xAD,0xFF,0xED,0xFF,
  0xAB,0xFF,0xEA,0xFF,0xBB,0xFF,0xDD,0xFF,
  0x8C,0xFF,0xF4,0xDF,0x57,0xFC,0x75,0xDE,
  0xF9,0xDE,0xF7,0xDC,0x55,0xFE,0xF8,0xDF,
  0xBF,0xC3,0x0F,0xF3,0x5F,0xE3,0xCF,0x73,
  0x2F,0xF3,0x33,0xFB,0x37,0xDB,0x27,0xDB,
  0xDE,0xE0,0x3C,0xC0,0xFA,0x84,0x8C,0xC2,
  0x05,0xC2,0xDF,0x80,0x5E,0x81,0xFF,0x80,
  0x7B,0x3C,0x3E,0x38,0x3E,0x38,0x3C,0x38,
  0x3C,0x38,0xBC,0x38,0xB9,0x38,0xF8,0x38,
  0x97,0x03,0x07,0x03,0x6B,0x03,0x27,0x03,
  0x97,0x03,0xBB,0x03,0x07,0x03,0x23,0x03,
  0xEF,0x80,0xB7,0x80,0xEB,0x80,0xB7,0x80,
  0xBB,0x80,0xBB,0x80,0xAD,0x80,0xAF,0x80,
  0xE9,0xD7,0xFF,0xC3,0xEB,0xD7,0xFF,0xC3,
  0xEB,0xD7,0xFF,0xC3,0xEB,0xD7,0xF7,0xCB,
  0xEB,0xFF,0xEB,0xFF,0xF3,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xDF,0xFF,0xDA,0xFF,0xF7,0xFF,
  0x61,0xFF,0xB3,0xED,0xC3,0xFD,0xF5,0xFB,
  0xFF,0xFF,0x3F,0xFF,0x3D,0xFF,0x37,0xFF,
  0x93,0xEC,0xC2,0xFC,0xC7,0xF8,0xF1,0xFE,
  0xFF,0xFF,0xFF,0xFF,0x9E,0xE7,0x1E,0xE7,
  0xB6,0x5C,0x9F,0x5C,0x7F,0x9C,0xFE,0x1F,
  0xFF,0xFF,0xFF,0xFF,0xC0,0xFF,0x47,0xF8,
  0xFC,0x01,0xC5,0x01,0xCB,0x01,0x7F,0x81,
  0xFF,0xFF,0xFF,0xFF,0x72,0xFD,0xFB,0x74,
  0xC3,0xC0,0xD1,0xC0,0xFB,0xC0,0xCE,0xF1,
  0xFF,0xFF,0xFF,0xFF,0x8F,0x7F,0xFF,0x07,
  0x3B,0x18,0xFB,0x18,0x5F,0x38,0xFF,0x3F,
  0xFF,0xFF,0xE7,0x9F,0xF9,0x07,0xFF,0x01,
  0xFB,0x1D,0xD9,0x3F,0x3F,0xFF,0xFF,0xFF,
  0xEF,0xFF,0xD7,0xAF,0xEF,0x97,0xFB,0x87,
  0xAD,0xFF,0xEB,0xFF,0xAD,0xFF,0xEA,0xFF,
  0xAB,0xFF,0xFA,0xFF,0xAF,0xFF,0xB2,0xFF,
  0xAC,0xFF,0x34,0xFF,0xAA,0xFD,0xAF,0xFC,
  0xAA,0xFD,0xAA,0xFD,0xB2,0xFD,0xB1,0xFF,
  0x7F,0x87,0x9E,0xE7,0x6F,0xD7,0xDF,0xE7,
  0x0E,0xF7,0x6F,0xF7,0x4F,0xB7,0x5F,0xB7,
  0xAD,0xD0,0x7C,0x80,0x74,0x88,0x1A,0x84,
  0x4A,0x84,0xBD,0x02,0xFE,0x01,0xBF,0x00,
  0x77,0x78,0x7E,0x70,0xF0,0x78,0x70,0x78,
  0x79,0x70,0x7A,0x70,0xF9,0x70,0xF0,0x70,
  0x17,0x07,0x8F,0x07,0x97,0x07,0x4F,0x07,
  0x2F,0x07,0xB7,0x07,0x0F,0x07,0x0F,0x07,
  0xD7,0x01,0x6B,0x01,0x57,0x01,0x6B,0x01,
  0x3B,0x01,0x6D,0x01,0x3B,0x01,0x4F,0x01,
  0xEB,0x97,0xFB,0x87,0x9B,0xA7,0xEB,0x97,
  0x9B,0xA7,0x9B,0xA7,0xAB,0x97,0xAB,0x97,
  0xFF,0xFF,0xAE,0xFF,0xF7,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFA,0xFF,0xEB,0xFF,
  0x8B,0xFF,0xDF,0xEB,0x83,0xFF,0xF7,0xFB,
  0xFF,0xFF,0x7F,0xFF,0x7B,0xFF,0xFF,0xFF,
  0x07,0xF8,0x87,0xF8,0xEF,0xF0,0xA1,0xFE,
  0xFF,0xFF,0xFF,0xFF,0x1F,0xEF,0x7F,0x8F,
  0x7D,0xB8,0x7F,0xB8,0x7B,0xBC,0xFC,0x3F,
  0xFF,0xFF,0xFF,0xFF,0x80,0xFF,0x8F,0xF0,
  0xFF,0x03,0x8B,0x03,0xDB,0x03,0xFF,0x03,
  0xFF,0xFF,0xFF,0xFF,0xE5,0xFA,0xE7,0xF8,
  0xC7,0x80,0x82,0x80,0xF5,0x80,0x9D,0xE2,
  0xFF,0xFF,0xFF,0xFF,0x17,0xFE,0xF7,0x0E,
  0x33,0x30,0xF7,0x30,0xFE,0x31,0xFF,0x7F,
  0xFF,0xFF,0xCF,0xBF,0xFB,0x07,0xFF,0x01,
  0xDB,0x35,0xD9,0x37,0x3F,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xE7,0x9F,0xF3,0x8F,0xDD,0xA7,
  0xFD,0xFF,0xF5,0xFF,0xFE,0xFF,0xEB,0xFF,
  0xFA,0xFF,0xFE,0xFF,0xF5,0xFF,0xFE,0xFF,
  0x49,0xFF,0xE1,0xFF,0xEF,0xF9,0xEC,0xFB,
  0xEC,0xFB,0xEE,0xF9,0xD0,0xFF,0xE2,0xFF,
  0xBD,0x4F,0x3E,0xCF,0x1D,0xEF,0x1D,0xEF,
  0xFE,0xCF,0x7C,0xEF,0x3F,0xEE,0xEF,0x3E,
  0x3E,0xC0,0xD8,0x20,0xED,0x10,0xB4,0x08,
  0x96,0x08,0xFB,0x04,0x7F,0x00,0xDF,0x20,
  0xEF,0xF0,0xEC,0xF0,0xEB,0xF0,0xE0,0xF0,
  0xE0,0xF0,0xF2,0xE0,0xF2,0xE0,0xF0,0xE0,
  0x17,0x06,0x0E,0x06,0x97,0x06,0x8F,0x06,
  0x66,0x06,0x6E,0x06,0x16,0x06,0x1E,0x06,
  0xD7,0x01,0xAF,0x01,0x57,0x01,0x77,0x01,
  0xAF,0x01,0x6B,0x01,0x5B,0x01,0x5F,0x01,
  0xFD,0x87,0xDD,0xA7,0xFD,0x87,0xDF,0xA7,
  0xFD,0x87,0xFB,0x87,0xED,0x97,0xFF,0x87,
  0xD7,0xFF,0xF7,0xFF,0xF7,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xEF,0xFF,0xBA,0xFF,0xAA,0xFF,
  0x9E,0xFB,0x87,0xFB,0x0B,0xF7,0xFB,0xF7,
  0xFF,0xFF,0x7F,0xFF,0x75,0xFF,0x7E,0xFF,
  0x8E,0xF1,0x1E,0xF1,0xCE,0xF1,0x43,0xFC,
  0xFF,0xFF,0xFF,0xFF,0x3F,0xDF,0x7F,0x9F,
  0xF3,0x78,0xFF,0x70,0xF7,0x78,0xFD,0x7E,
  0xFF,0xFF,0xFF,0xFF,0x41,0xFF,0x1F,0xE1,
  0xFB,0x03,0x97,0x03,0x9B,0x03,0xFB,0x07,
  0xFF,0xFF,0xFF,0xFF,0xC5,0xFA,0xEF,0xD0,
  0x86,0x00,0x80,0x00,0xFF,0x00,0x3F,0xC0,
  0xFF,0xFF,0xFF,0xFF,0x2E,0xFD,0xFF,0x0C,
  0x73,0x70,0xFF,0x70,0xFE,0x71,0x7F,0xFF,
  0xFF,0xFF,0x8F,0xFF,0xF3,0x0F,0xFF,0x03,
  0xF9,0x37,0xB9,0x77,0xFF,0x7F,0xFF,0xFF,
  0xFD,0xFF,0xEF,0x1D,0xD7,0x2D,0xF7,0x0D,
  0xDF,0xFF,0xD4,0xFF,0xEF,0xFF,0xB2,0xFF,
  0xDF,0xFF,0xAA,0xFF,0xDB,0xFF,0xFA,0xFF,
  0x4B,0xFE,0x53,0xFF,0x55,0xFB,0x45,0xFB,
  0x54,0xFB,0x58,0xF7,0x50,0xFF,0x63,0xFE,
  0xBC,0x5F,0xBF,0x5E,0x3D,0xDE,0x3F,0xDE,
  0xBF,0xDE,0xDD,0xFE,0x1D,0xFE,0x0D,0xFE,
  0x3D,0xC1,0xD1,0x21,0xCF,0x31,0x29,0x11,
  0x2F,0x11,0xF7,0x09,0xFB,0x05,0xBF,0x41,
  0xCF,0xF0,0xDA,0xE0,0xF9,0xE0,0xF1,0xE0,
  0xD0,0xE0,0xC0,0xE0,0xE6,0xC0,0xE0,0xC0,
  0x3F,0x0C,0x1E,0x0C,0x2F,0x0C,0x9E,0x0C,
  0x8E,0x0C,0xFC,0x0C,0x4E,0x0C,0x3E,0x0C,
  0x5F,0x03,0xC7,0x03,0x5F,0x03,0xAB,0x03,
  0xD7,0x03,0x7F,0x03,0x97,0x03,0xB3,0x03,
  0xFF,0x05,0xBF,0x45,0x73,0x0D,0xBF,0x45,
  0x77,0x0D,0xBF,0x45,0x73,0x0D,0xFF,0x05
};

/* End of SRC/TOWER_ANIM_TILES.B9.C */
