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
  0x00,0x03,0x03,0x00,0x02,0x02,0x02,0x02,
  0x01,0x02,0x02,0x01,0x02,0x02,0x02,0x01,
  0x02,0x02,0x02,0x01,0x01,0x02,0x01,0x01
};
extern const UWORD Road3DTilesPAL[];
extern const unsigned char map3d_scanlines[]; 

const unsigned char VanMovement[] = {0,0,1,1,1,2,2,2,1,1,1,0};

UINT16 Map3D_Frame; 

extern UINT8 Scene;
extern UINT8 v;
extern UINT8 SSPEED;
extern UINT8 SSPEED1;
extern UINT8 SPR;
extern UINT8 SPRX;
extern UINT8 SPRY;
extern UINT16 TIMER;

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

void Road3D_Set(){

	VBK_REG = 0;
		//DMA_TRANSFER(80, Road3DTiles,0x9000);
		set_bkg_data(0, 80, Road3DTiles);
		set_bkg_tiles( 0, 0, 32, 18, RoadBKGMap3DPLN0);
		set_sprite_data( 0, 46, Road3Dsprites);//in 8x8 mode!!!
	VBK_REG = 1;	   
	   set_bkg_tiles( 0, 0, 32, 18, RoadBKGMap3DPLN1); 
	   
	   for (v = 0; v<28;v++) set_sprite_prop(v, Road3DspritesCGB1[v]);
	VBK_REG = 0;

	set_bkg_palette(0, 8, Road3DTilesPAL);
	set_sprite_palette( 0, 8, Road3DspritesPAL);
		
	SSPEED = 0;
	SSPEED1 = 0;
	SPRX = 0;
	SPRY = 170;
	
	Map3D_Frame = 0;
	TIMER = 0;
	
	Scene++;
	
	SHOW_SPRITES;
	SHOW_BKG;
}	


void Road3D_Run(){
	if ((TIMER > 838) && (TIMER < 886)){SCY_REG--;WY_REG++;}
	if ((TIMER > 910) && (TIMER < 946))WY_REG-=4;
	if (TIMER == 946) WY_REG = 0;

	if(SSPEED == 5){SSPEED = 0;SCX_REG++;}
	SSPEED++;
	
	if(SSPEED1 == 2){SSPEED1 = 0;Map3D_Frame+=30*16;}
	SSPEED1++;
	
	if (Map3D_Frame == 30*16*15) Map3D_Frame = 0; 
	
	//VAN
	SPR = 0;//112 128 140
	for (v = 0;v<4;v++){
		move_sprite(v,56+SPR,SPRY+VanMovement[SPRX]);
		move_sprite(v+4,56+SPR,16+SPRY+VanMovement[SPRX]);
		move_sprite(v+8,56+SPR,32+SPRY);
		SPR+=8;
	}
	
	if(SPRX == 11) SPRX = 0;
	SPRX++;
	
	TIMER++;
	
	if ((TIMER > 12) && (TIMER < 52))WY_REG+=4;
	if (TIMER == 53) WY_REG = 144;
	if ((TIMER > 53) && (TIMER < 101)){SCY_REG++;WY_REG--;}
	
	if (TIMER == 54){
		VBK_REG = 0;
		set_win_tiles( 0, 0, 20, 6, RoadFMap3DPLN0);
		VBK_REG = 1;
		set_win_tiles( 0, 0, 20, 6, RoadFMap3DPLN1);
		VBK_REG = 0;
	}	
	if ((TIMER > 100) && (TIMER < 160)) SPRY--;
	if ((TIMER > 818) && (TIMER < 878)) SPRY++;

	if(TIMER == 960) {
		TIMER = 0; Scene++; 
		for (v = 0;v=!40;v++)move_sprite(v,180,180);
	}
	
}

/**/