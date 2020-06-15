#include <gb/gb.h>

extern const unsigned char RoadBKGMap3DPLN0[];
extern const unsigned char RoadBKGMap3DPLN1[];
extern const unsigned char RoadFMap3DPLN0[];
extern const unsigned char RoadFMap3DPLN1[];
extern const unsigned char Road3DTiles[];
extern const unsigned char Road3DAnim[];
extern const unsigned char Road3Dsprites[];
extern const unsigned char Road3DspritesPAL[];
const unsigned char Road3DspritesCGB1[] =
{
  0x01,0x01,0x00,0x02,0x03,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x05,0x05,0x05,0x05,0x06,0x06
};
const unsigned char SideRoad_SpritesPos1[] = {//208
	120,95,119,96,119,96,119,96,119,96,119,96,119,96,119,97,
	119,97,119,97,119,97,119,98,119,98,119,98,119,98,119,98,
	119,98,118,99,118,99,118,99,118,99,118,99,118,99,118,99,
	118,99,118,100,118,100,118,100,118,100,118,101,118,101,118,101,
	118,101,118,101,118,101,118,101,118,101,117,102,117,102,117,102,
	117,102,117,102,117,103,117,103,117,103,117,103,117,104,117,104,
	117,104,117,104,117,104,117,105,117,105,117,105,117,105,117,106,
	117,106,117,106,117,106,116,107,116,107,116,107,116,108,116,108,
	116,109,116,109,116,110,116,110,116,111,116,111,116,111,117,112,
	117,112,117,113,117,113,117,114,117,115,118,116,118,116,118,117,
	119,118,120,119,121,120,122,121,123,122,124,123,126,124,128,125,
	130,127,132,129,134,130,138,133,140,135,142,137,144,140,150,143,
	152,148,155,152,158,156,161,160,164,164,167,168,170,172,173,176,
};

const unsigned char SideRoad_SpritesPos2[] = {//208
	64,95,63,96,63,96,63,96,63,96,63,96,62,96,61,97,
	61,97,60,97,59,97,58,98,58,98,57,98,57,98,56,98,
	56,98,55,99,55,99,55,99,54,99,54,99,54,99,53,99,
	53,99,52,100,52,100,51,100,51,100,50,101,50,101,50,101,
	50,101,50,101,49,101,49,101,49,101,48,102,48,102,48,102,
	48,102,48,102,47,103,47,103,46,103,46,103,45,104,45,104,
	45,104,44,104,44,104,43,105,43,105,43,105,43,105,42,106,
	42,106,41,106,41,106,40,107,40,107,40,107,39,108,38,108,
	37,109,36,109,35,110,35,110,34,111,34,111,33,111,32,112,
	32,112,31,113,30,113,29,114,28,115,27,116,26,116,25,117,
	24,118,23,119,22,120,21,121,20,122,19,123,18,124,17,125,
	16,127,15,129,14,130,13,133,12,135,11,137,10,140,9,143,
	8,148,7,152,6,156,5,160,4,164,3,168,2,172,1,176,
};

extern const UWORD Road3DTilesPAL[];
extern const unsigned char map3d_scanlines[]; 

const unsigned char VanMovement[] = {0,0,1,1,1,2,2,2,1,1,1,0};

UINT16 Map3D_Frame0; 

extern UINT8 Scene;
extern UINT8 v;
extern UINT8 SSPEED;
extern UINT8 SSPEED1;
extern UINT8 SSPEED2;
extern UINT8 SSPEED3;
extern UINT8 SPR;
extern UINT8 SPRX;
extern UINT8 SPRY;
extern UINT16 TIMER;

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

void Road3D_Set(){

	VBK_REG = 0;
		//DMA_TRANSFER(80, Road3DTiles,0x9000);
		set_bkg_data(0, 108, Road3DTiles);
		set_bkg_tiles( 0, 0, 32, 19, RoadBKGMap3DPLN0);
		set_sprite_data( 0, 46, Road3Dsprites);//in 8x8 mode!!!
	VBK_REG = 1;	   
	   set_bkg_tiles( 0, 0, 32, 19, RoadBKGMap3DPLN1); 
	   
	   for (v = 0; v<32;v++) set_sprite_prop(v, Road3DspritesCGB1[v]);
	VBK_REG = 0;

	set_bkg_palette(0, 8, Road3DTilesPAL);
	set_sprite_palette( 0, 8, Road3DspritesPAL);
		
		
	move_sprite(12,180,180);move_sprite(13,180,180);
	SSPEED = 0;
	SSPEED1 = 0;
	SSPEED2 = 50;
	SSPEED3 = 0;
	SPRX = 0;
	SPRY = 170;
	SPR = 0;
	
	Map3D_Frame0 = 0;
	TIMER = 0;
	
	Scene++;
	
	SHOW_SPRITES;
	SHOW_BKG;
}	


void Road3D_Run(){
	if ((TIMER > 838) && (TIMER < 880)){SCY_REG--;WY_REG++;}
	if ((TIMER > 910) && (TIMER < 946))WY_REG-=4;
	if (TIMER == 946) WY_REG = 0;

	if ((TIMER > 12) && (TIMER < 52))WY_REG+=4;
	if (TIMER == 53) WY_REG = 144;
	if ((TIMER > 53) && (TIMER < 101))SCY_REG++;
	if ((TIMER > 53) && (TIMER < 93))WY_REG--;

	if(SSPEED == 5){SSPEED = 0;SCX_REG++;}
	SSPEED++;
	
	Map3D_Frame0+=25*16;
	
	if (Map3D_Frame0 == (25*16*30) - (25*16)) Map3D_Frame0 = 0; 
	
	//VAN
	move_sprite(0,56,SPRY+VanMovement[SPRX]);
	move_sprite(1,56+8,SPRY+VanMovement[SPRX]);
	move_sprite(2,56+16,SPRY+VanMovement[SPRX]);
	move_sprite(3,56+24,SPRY+VanMovement[SPRX]);
	move_sprite(4,56,SPRY+16+VanMovement[SPRX]);
	move_sprite(5,56+8,SPRY+16+VanMovement[SPRX]);
	move_sprite(6,56+16,SPRY+16+VanMovement[SPRX]);
	move_sprite(7,56+24,SPRY+16+VanMovement[SPRX]);
	//VAN SHADOW
	if (SPR == 1){
		move_sprite(8,180,180);move_sprite(9,180,180);
		move_sprite(10,180,180);move_sprite(11,180,180);
	}
	if (SPR == 2){
		move_sprite(8,44,32+SPRY);move_sprite(9,44+8,32+SPRY);
		move_sprite(10,44+16,32+SPRY);move_sprite(11,44+24,32+SPRY);
		SPR = 0;
	}
	SPR++;
	
	if ((TIMER > 53) && (TIMER < 838)){
		//BUSH
		if (SSPEED2 == 208) SSPEED2 = 0;
		move_sprite(12,SideRoad_SpritesPos1[SSPEED2],(WY_REG-96)+SideRoad_SpritesPos1[SSPEED2+1]);
		move_sprite(13,SideRoad_SpritesPos1[SSPEED2]+8,(WY_REG-96)+SideRoad_SpritesPos1[SSPEED2+1]);
		SSPEED2+=2;	
		//THREES
		if (SSPEED3 == 208) SSPEED3 = 0;
		move_sprite(14,SideRoad_SpritesPos2[SSPEED3],(WY_REG-114)+SideRoad_SpritesPos2[SSPEED3+1]);
		move_sprite(15,SideRoad_SpritesPos2[SSPEED3]+8,(WY_REG-114)+SideRoad_SpritesPos2[SSPEED3+1]);
		move_sprite(16,SideRoad_SpritesPos2[SSPEED3],(WY_REG-98)+SideRoad_SpritesPos2[SSPEED3+1]);
		move_sprite(17,SideRoad_SpritesPos2[SSPEED3]+8,(WY_REG-98)+SideRoad_SpritesPos2[SSPEED3+1]);
		SSPEED3+=2;
	} 
	else {
		move_sprite(12,180,180);move_sprite(13,180,180);
		move_sprite(14,180,180);move_sprite(15,180,180);
		move_sprite(16,180,180);move_sprite(17,180,180);
	}
	
	if(SPRX == 11) SPRX = 0;
	SPRX++;
	
	TIMER++;
	
	if (TIMER == 54){
		VBK_REG = 0;
		set_win_tiles( 0, 0, 20, 6, RoadFMap3DPLN0);
		VBK_REG = 1;
		set_win_tiles( 0, 0, 20, 6, RoadFMap3DPLN1);
		VBK_REG = 0;
	}	
	if ((TIMER > 100) && (TIMER < 152)) SPRY--;
	if ((TIMER > 818) && (TIMER < 870)) SPRY++;

	if(TIMER == 960) {
		for (v = 0;v<40;v++)move_sprite(v,180,180);
		TIMER = 0; Scene++; 
	}
	
}

/**/