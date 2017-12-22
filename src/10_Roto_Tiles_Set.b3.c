#include <gb/gb.h>

extern const unsigned char Roto_Tiles[];
extern const unsigned char Roto_TilesPAL[];

void Roto_Tiles_Set(){
	VBK_REG = 0;
	set_bkg_data(0, 64, Roto_Tiles);
	set_bkg_palette(0, 8, Roto_TilesPAL);
}
