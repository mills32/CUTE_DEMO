#include <gb/gb.h>

extern const unsigned char Credits_Map[];
extern const unsigned char Credits_Tiles[];
extern const unsigned char Credits_TilesPAL[];
extern const unsigned char Credits_Sprites[];
extern const unsigned char Credits_SpritesPAL[];
extern const unsigned char Credits_Sprites_Anim[];

const unsigned char Clear_MAP[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

extern UINT16 TIMER; 
extern UINT8 v;
extern UINT16 Tile_Cnt; 
extern UINT8 SPR;
extern UINT8 SPRX; 
extern UINT8 SPRY; 
extern UINT8 SSPEED;
extern UINT8 SSPEED1;

extern UINT8 MAP_X;
extern UINT16 MAP_Y;    
extern UINT8 Scroll;      
extern UINT16 ScrollY;     
extern UINT16 Tile_Cnt;

extern UINT16 GFX_Offset; 
extern UINT8 Scene;

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

struct Credits_Flower{
	UINT8 sprite_number;
	int sx;
	int sy;
	UINT8 x;
	UINT8 y;
};

struct Credits_Flower flower1;
struct Credits_Flower flower2;

void Move_Flower(struct Credits_Flower* flower){
	
	if (flower->x > 168)flower->sx = -1*flower->sx;
	if (flower->y > 160)flower->sy = -1*flower->sy;
	
	SPR = flower->sprite_number;
	SPRX = flower->x;
	SPRY = flower->y;	
	//Move Flower
	move_sprite(SPR,SPRX,SPRY);			move_sprite(SPR+1,SPRX+8,SPRY);
	move_sprite(SPR+2,SPRX+16,SPRY);	move_sprite(SPR+3,SPRX+24,SPRY);
	move_sprite(SPR+4,SPRX,SPRY+16);	move_sprite(SPR+5,SPRX+8,SPRY+16);
	move_sprite(SPR+6,SPRX+16,SPRY+16);	move_sprite(SPR+7,SPRX+24,SPRY+16);

	if (flower->sx > 0)flower->x++; else flower->x--;
	if (flower->sy > 0)flower->y++; else flower->y--;
}

void Credits_Set(){
	set_sprite_palette(0, 8, Credits_SpritesPAL);
	set_bkg_palette(0, 8, Credits_TilesPAL);
	
	VBK_REG = 0;							
		set_bkg_data(0, 233, Credits_Tiles);
		set_bkg_tiles(0, 0, 20, 32, Credits_Map);
		set_sprite_data(0, 32, Credits_Sprites); 

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
	MAP_Y = 0;    
	Scroll = 0;       
	ScrollY = 0;     
	Tile_Cnt = 20*18;
	GFX_Offset = 0;
	
	flower1.sprite_number = 0;flower1.x =80;flower1.y = 70;flower1.sx = -1;flower1.sy = -1;
	flower2.sprite_number = 8;flower2.x =0;flower2.y = 120;flower2.sx = 1;flower2.sy = 1;
	
	Scene++;

}

void Credits_Run(){	

	if ((TIMER >180)&&(SSPEED == 2)){v++; SCY_REG++;}//Scroll down
	if ((TIMER > 40) && (TIMER < 86))WY_REG+=4;
	
	//Animate Flowers
	if(SSPEED1 == 2){
		if(TIMER > 50){
			DMA_TRANSFER(16, &Credits_Sprites_Anim+GFX_Offset,0x8000); //Sprite VRAM 0
			DMA_TRANSFER(16, &Credits_Sprites_Anim+GFX_Offset,0x8100); //Sprite VRAM 16
		}
		SSPEED1 = 0;GFX_Offset+=128;
	}		
	
	if (SSPEED == 2)SSPEED = 0;
	
	//SCROLL
	if (v == 8){ 
		v = 0; 
        MAP_Y = 1 + (SCY_REG+144)/8;
        if (MAP_Y == 32) MAP_Y = 0;
        if (ScrollY == 290) {ScrollY = 0; Tile_Cnt = 0;} //reset if reach X limit Working
            VBK_REG = 0;
            set_bkg_tiles(0,MAP_Y, 20, 1, (unsigned char *) &Credits_Map+Tile_Cnt);
			VBK_REG = 1;
			set_bkg_tiles(0,MAP_Y, 20, 1, Clear_MAP); //Last scenes left the map made a complete mess
			VBK_REG = 0;
        	Tile_Cnt+=20;
        ScrollY++;
	}
	
	if(GFX_Offset > 1024) GFX_Offset = 0;
	
	
	//Move Flowers
	Move_Flower(&flower1);
	Move_Flower(&flower2);
	
	SSPEED++;
	SSPEED1++;
	TIMER++;
	
	if ( (TIMER == 9999) || (joypad() & J_B) ) Scene++;
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

