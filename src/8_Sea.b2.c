#include <gb/gb.h>
#include <rand.h>

extern const unsigned char Sea_MapPLN0[];
extern const unsigned char Sea_MapPLN1[];
extern const unsigned char Sea_Tiles[];
extern const unsigned char Sea_TilesPAL[];
extern const unsigned char Sea_Sprites[];
extern const unsigned char Sea_SpritesPAL[];
const unsigned char Sea_SpritesCGB1[] =
{
  0x00,0x00,0x00,0x00,0x82,0x82,0x82,0x82,
  0x82,0x82,0x82,0x82,0x01,0x01,01,0x01,
  0x01,0x01,0x80,0x80,0x00
};

extern const UINT8 Sea_Wave[];

extern UINT16 GFX_Offset; 
extern UINT8 SSPEED;
extern UINT8 SSPEED1;
extern UINT8 v;
extern UINT16 TIMER;
extern UINT8 Scene;
extern UINT8 SPR;
extern UINT8 SPRY;
extern int SX;
extern int SY;
extern int Random;
extern int Random1;

void WAIT_SCANLINE1();
void WAIT_SCANLINE2();
void Set_Lines_Pal(UINT16 *rgb_data);
extern const UWORD SeaDegrade[];
void Sea_Set(){
	
	for (v = 0;v<40;v++)move_sprite(v,0,0);
	
    TIMER = 0; 
	GFX_Offset = 0;
	SSPEED = 0;
	
	VBK_REG = 0;	   
	   set_bkg_tiles( 0, 0, 32, 18, Sea_MapPLN0); 
	   set_bkg_data(0, 228, Sea_Tiles);
	   set_sprite_data(0, 36, Sea_Sprites); 
	VBK_REG = 1;	   
	   set_bkg_tiles( 0, 0, 32, 18, Sea_MapPLN1); 	
	VBK_REG = 0;

	for (v = 0; v<18;v++)set_sprite_prop(v, Sea_SpritesCGB1[v]);
	
	set_sprite_palette(0, 8, Sea_SpritesPAL);
	set_bkg_palette(0, 8, Sea_TilesPAL);
	
	SHOW_SPRITES;
	SHOW_BKG;
	
	SX = 70;
	SY = 90;
	SPRY = 0;
	Scene++;
	Random = ((int)rand()) % (int)4;
	Random1 = ((int)rand()) % (int)4;
	Random = ((int)rand()) % (int)4;
	Random1 = ((int)rand()) % (int)4;
	Random = ((int)rand()) % (int)4;
	Random1 = ((int)rand()) % (int)4;
	Random = ((int)rand()) % (int)4;
	Random1 = ((int)rand()) % (int)4;
	Random = ((int)rand()) % (int)4;
	Random1 = ((int)rand()) % (int)4;
	Random = ((int)rand()) % (int)4;
	Random1 = ((int)rand()) % (int)4;
}	

void Sea_Update() {	 //
	if ((TIMER > 12) && (TIMER < 49))WY_REG+=4;
	if ((TIMER > 520) && (TIMER < 557)) WY_REG-=4;
	
    if (GFX_Offset == 180) {GFX_Offset = 0;} 
	if (SSPEED1 == 20) Random = ((int)rand()) % (int)4;
	if (SSPEED1 == 30){SSPEED1 = 0;Random1 = ((int)rand()) % (int)4;}

	//DORI
	SPR = 4;
	if(Random > -1){
		for (v = 4; v<12;v++)set_sprite_prop(v, Sea_SpritesCGB1[v] | 0x00);
		for (v = 0; v<32;v+=8){
			move_sprite(SPR,20+SX+v, 60);
			move_sprite(SPR+4,20+SX+v, 76);
			SPR++;
		}
	}
	SPR = 4;
	if(Random < 0){
		for (v = 4; v<12;v++)set_sprite_prop(v, Sea_SpritesCGB1[v] | 0x20);
		for (v = 32; v>0;v-=8){
			move_sprite(SPR,SX+v, 60);
			move_sprite(SPR+4,SX+v, 76);
			SPR++;
		}
	}	
	//MARLIN
	SPR = 12;
	if(Random1 < 0){
		for (v = 12; v<18;v++)set_sprite_prop(v, Sea_SpritesCGB1[v] | 0x00);
		for (v = 0; v<24;v+=8){
			move_sprite(SPR,SY+v, 90);
			move_sprite(SPR+3,SY+v, 106);
			SPR++;
		}
	}
	SPR = 12;
	if(Random1 > -1){
		for (v = 12; v<18;v++)set_sprite_prop(v, Sea_SpritesCGB1[v] | 0x20);
		for (v = 24; v>0;v-=8){
			move_sprite(SPR,SY+v, 90);
			move_sprite(SPR+3,SY+v, 106);
			SPR++;
		}
	}
	
	//Bubles
	move_sprite(0,20, SPRY);move_sprite(1,28, SPRY);
	move_sprite(2,120, SPRY+100);move_sprite(3,128, SPRY+100);
	
	SX+=Random;
	SY+=Random1;
	
	GFX_Offset++; 
	SSPEED++; 	
	SSPEED1++; 
	TIMER++;
	SPRY--;

	if (TIMER == 576) {TIMER = 0; Scene++;}
}

int SLYC;
void Sea_Run(){
	SLYC = LY_REG;
	//WAIT_SCANLINE1();
	SPR = Sea_Wave[LY_REG+GFX_Offset]+SSPEED;
	//WAIT_SCANLINE2();
	Set_Lines_Pal(SeaDegrade);
	SCX_REG = SPR;
}


const UINT8 Sea_Wave[] = {
10, 10, 11, 12, 12, 13, 14, 14, 15,
15, 16, 16, 17, 17, 18, 18, 18, 19, 19,
19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
18, 18, 18, 17, 17, 16, 16, 15, 15, 14,
14, 13, 12, 12, 11, 10, 9, 9, 8, 7,
7, 6, 5, 5, 4, 4, 3, 3, 2, 2,
1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 2, 2,
3, 3, 4, 4, 5, 5, 6, 7, 7, 8,
9,
10, 10, 11, 12, 12, 13, 14, 14, 15,
15, 16, 16, 17, 17, 18, 18, 18, 19, 19,
19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
18, 18, 18, 17, 17, 16, 16, 15, 15, 14,
14, 13, 12, 12, 11, 10, 9, 9, 8, 7,
7, 6, 5, 5, 4, 4, 3, 3, 2, 2,
1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 2, 2,
3, 3, 4, 4, 5, 5, 6, 7, 7, 8,
9,
10, 10, 11, 12, 12, 13, 14, 14, 15,
15, 16, 16, 17, 17, 18, 18, 18, 19, 19,
19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
18, 18, 18, 17, 17, 16, 16, 15, 15, 14,
14, 13, 12, 12, 11, 10, 9, 9, 8, 7,
7, 6, 5, 5, 4, 4, 3, 3, 2, 2,
1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 2, 2,
3, 3, 4, 4, 5, 5, 6, 7, 7, 8,
9,
10, 10, 11, 12, 12, 13, 14, 14, 15,
15, 16, 16, 17, 17, 18, 18, 18, 19, 19,
19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
18, 18, 18, 17, 17, 16, 16, 15, 15, 14,
14, 13, 12, 12, 11, 10, 9, 9, 8, 7,
7, 6, 5, 5, 4, 4, 3, 3, 2, 2,
1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 2, 2,
3, 3, 4, 4, 5, 5, 6, 7, 7, 8,
9
}; 