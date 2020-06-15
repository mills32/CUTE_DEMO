#include <gb/gb.h>

extern const unsigned char Credits_MapPLN0[];
extern const unsigned char Credits_MapPLN1[];
extern const unsigned char Credits_Tiles[];
extern const unsigned char Credits_TilesPAL[];
extern const unsigned char Credits_Sprites[];
extern const unsigned char Credits_SpritesPAL[];
extern const unsigned char Credits_Anim_Sprites[];

extern UINT16 TIMER; 
extern UINT8 v;
extern UINT16 Tile_Cnt; 
extern UINT8 SPR;
extern UINT8 SPRX; 
extern UINT8 SPRY; 
extern UINT8 SSPEED;
extern UINT8 SSPEED1;
extern int SX;
extern int SY;
extern UINT8 MAP_X;
extern UINT16 MAP_Y;
extern UINT8 Map_PosY;  
extern UINT8 Scroll;      
extern UINT16 ScrollY;     
extern UINT16 Tile_Cnt;

extern UINT16 GFX_Offset; 
extern UINT8 Scene;
UINT16 CPal;
extern const UWORD CreditsDegrade[];

void Set_Lines_Pal2(UINT16 *rgb_data);

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

void Credits_Set(){
	set_sprite_palette(0, 8, Credits_SpritesPAL);
	set_bkg_palette(0, 8, Credits_TilesPAL);
	
	VBK_REG = 0;							
		set_bkg_data(0, 233, Credits_Tiles);
		set_bkg_tiles(0, 0, 20, 18, Credits_MapPLN0);
		//set_sprite_data(0, 16, Credits_Sprites); 
	VBK_REG = 1;							
		set_bkg_tiles(0, 0, 20, 18, Credits_MapPLN1);
	VBK_REG = 0;
	
	for (v = 0; v<8;v++) set_sprite_prop(v, 0x80);
	for (v = 8; v<16;v++) set_sprite_prop(v, 0x81);	
	
	Tile_Cnt = 0;
	
	SHOW_BKG;
	SHOW_SPRITES;

	v = 0;
	SPR = 0;
	SPRX = 0;
	SPRY = 0;
	SSPEED = 0;
	SSPEED1 = 0;
	MAP_X = 0;
	MAP_Y = 18; 
	Map_PosY = 0;
	Scroll = 0;       
	ScrollY = 0;     
	Tile_Cnt = 20*18;
	GFX_Offset = 0;
	SPRX = 80;
	SPRY = 70;
	SX = 1;
	SY = 1;
	Scene++;

}

void Credits_Run(){	
	if(GFX_Offset == 2048) GFX_Offset = 0;
	DMA_TRANSFER(16, Credits_Anim_Sprites+GFX_Offset,(UINT16*)0x8000); //Sprite VRAM 0
	GFX_Offset+=256;


	if ((TIMER > 180)&&(SSPEED == 2)){v++; SCY_REG++;}//Scroll down
	if ((TIMER > 40) && (TIMER < 86))WY_REG+=4;

	if(SSPEED == 2)SSPEED = 0;
	SSPEED++;
	
	//SCROLL
	if (v == 8){ 
		v = 0; 
		MAP_Y++;
        if (MAP_Y == 209) {Tile_Cnt = 0;MAP_Y = 17;} //reset if reach Y limit
        Map_PosY = MAP_Y&31;
		VBK_REG = 0;
            set_bkg_tiles(0,Map_PosY, 20, 1, Credits_MapPLN0+Tile_Cnt);
		VBK_REG = 1;
			set_bkg_tiles(0,Map_PosY, 20, 1, Credits_MapPLN1+Tile_Cnt);
		VBK_REG = 0;
		Tile_Cnt+=20;
	}
	
	//Move Flower
	if (SPRX == 160)SX = -1;
	if (SPRY == 130)SY = -1;
	if (SPRX == 0)SX = 1;
	if (SPRY == 16)SY = 1;
	move_sprite(0,SPRX,SPRY);		move_sprite(1,SPRX+8,SPRY);
	move_sprite(2,SPRX+16,SPRY);	move_sprite(3,SPRX+24,SPRY);
	move_sprite(4,SPRX,SPRY+16);	move_sprite(5,SPRX+8,SPRY+16);
	move_sprite(6,SPRX+16,SPRY+16);	move_sprite(7,SPRX+24,SPRY+16);
	SPRX+=SX; 
	SPRY+=SY;
	
	TIMER++;
	
	if ( (TIMER == 9999) || (joypad() & J_B) ) Scene++;
}

void Credits_Run2(){	
	Set_Lines_Pal2(CreditsDegrade);
}	


/*
#############
CREDITS MAP

#CUTE DEMO

# BY MILLS #
#    .     #
# .        #
#        . #
# ASSEMBLY #
#----------#
#          #
#  MILLS   #
#   AND    #
#GUYS FROM #
#  GBDEV   #
#    .     #
# .        #
#        . #
# GRAPHICS #
#----------#
#          #
# BY MILLS #
#          #
# .  ..   .#
# 3D GFX   #
#MADE WITH #
# BLENDER  #
#          #
# .  ..   .#
#ZILOG LOGO#
# UNKNOWN  #
#          #
# .  ..   .#
#LISA/HOMER#
# BY FOXR  #
#          #
# .  ..   .#
#BATS      #
# BY CURTO #
#          #
# .  ..   .#
#FONTS BY  #
# LYNDON   #
#   BROOKE #      
#          #
# .  ..   .#
#  ROCKET  #
#BY CLIPART#
# LIBRARY  #
#          #
# .  ..   .#
#CUTE      #
# TORTOISE #
# *UNKNOWN #	
#          #
#    .     #
# .        #
#        . #
#  MUSIC   #
#----------#
#          #
#  ATOMIC  #
#  TWIST   #
#          #
#    BY    #
#          #
#J.JACQUES #
#  PERREY  #
#          #
#   AND    #
#          #
#  DANA    #
#COUNTRYMAN#
#   . .    #
#CONVERTED #
# BY MILLS #
#          #
# .  ..   .#
# CARILLON #
#  EDITOR  #
#          #
#    BY    #
#          #
#  ALEKSI  #
#  EEBEN   #
#    .     #
# .        #
#        . #
#          #
#HOPE YOU  #
# LIKED IT #
#          #
#          #
#          #
#          #
# -MILLS-  #
#   2018   #
#          #
#          #
#          #
*/

