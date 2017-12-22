#include <gb/gb.h>

extern const unsigned char Parallax_MapPLN0[];
extern const unsigned char Parallax_MapPLN1[];
      
extern UINT8 Map_PosX;    
extern UINT8 Scroll;      
extern UINT8 ScrollX;     
extern UINT16 Tile_Cnt; 
extern UINT8 SPR;
extern UINT8 Scene;
extern UINT8 Part;
extern UINT16 MAP_Y;

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

void Parallax_Map_Run(){

    if (Scroll == 1){ 
    	Tile_Cnt = ScrollX+22;
    	if (Tile_Cnt == 240) {ScrollX = -22; Tile_Cnt = 0;} //reset if reach X limit Working
    	for (SPR = 0; SPR<18;SPR++){
    		VBK_REG = 0;
    		set_bkg_tiles(Map_PosX,SPR, 1, 1, (unsigned char *) &Parallax_MapPLN0+Tile_Cnt);
    		VBK_REG = 1;
    		set_bkg_tiles(Map_PosX,SPR, 1, 1, (unsigned char *) &Parallax_MapPLN1+Tile_Cnt);
    		Tile_Cnt+=240;
    	}	 
    	ScrollX++;
    	Scroll = 0;
    }
}
