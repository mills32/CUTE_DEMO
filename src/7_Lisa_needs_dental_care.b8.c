#include <gb/gb.h>

extern unsigned char Lisa_MapPLN0[];
extern unsigned char Lisa_MapPLN1[];
extern unsigned char Lisa_Tiles[];
extern unsigned char Lisa_TilesPAL[];
extern unsigned char Lisa_SpritesPAL[];
extern unsigned char Lisa_Sprites[];

extern UINT8 v;
extern UINT8 SPR;
extern UINT8 SPRX;
extern UINT8 SPRY;
extern UINT8 SSPEED;
extern UINT8 Scene;
extern UINT16 TIMER;

const UINT8 Lisa_Text_Pos[] = 
{
80, 81, 82, 84, 85, 86, 88, 89, 90,
91, 92, 93, 94, 95, 96, 97, 97, 98, 99,
99, 99, 99, 99, 99, 99, 99, 99, 99, 98,
97, 97, 96, 95, 94, 93, 92, 91, 90, 89,
88, 86, 85, 84, 82, 81, 79, 78, 77, 75,
74, 73, 71, 70, 69, 68, 67, 66, 65, 64,
63, 62, 62, 61, 60, 60, 60, 60, 60, 60,
60, 60, 60, 60, 61, 62, 62, 63, 64, 65,
66, 67, 68, 69, 70, 71, 73, 74, 75, 77,
78,
80, 81, 82, 84, 85, 86, 88, 89, 90,
91, 92, 93, 94, 95, 96, 97, 97, 98, 99,
99, 99, 99, 99, 99, 99, 99, 99, 99, 98,
97, 97, 96, 95, 94, 93, 92, 91, 90, 89,
88, 86, 85, 84, 82, 81, 79, 78, 77, 75,
74, 73, 71, 70, 69, 68, 67, 66, 65, 64,
63, 62, 62, 61, 60, 60, 60, 60, 60, 60,
60, 60, 60, 60, 61, 62, 62, 63, 64, 65,
66, 67, 68, 69, 70, 71, 73, 74, 75, 77,
78
};

void Lisa_Set(){

	VBK_REG = 0;	   
		set_bkg_tiles( 0, 0, 20, 18, Lisa_MapPLN0); //maptiles
		set_bkg_data(0, 175, Lisa_Tiles); //tile bank 1
		set_sprite_data(0, 110, Lisa_Sprites); ///Sprites	
	VBK_REG = 1;	   
		set_bkg_tiles( 0, 0, 20, 18, Lisa_MapPLN1); //map colours 
		for (v = 0; v<40;v++) set_sprite_prop(v, 0x00);

	VBK_REG = 0;
	SHOW_SPRITES;
	SHOW_BKG;

	set_bkg_palette(0, 8, Lisa_TilesPAL);
	set_sprite_palette(0, 8, Lisa_SpritesPAL);
	

	Scene++;
	SSPEED = 0;
	SPRX = 0;

}

void Lisa_Run(){
	
	
	if ((TIMER > 12) && (TIMER < 52))WX_REG+=4;
	if ((TIMER > 726) && (TIMER < 766))WX_REG-=4;

	
	if (SSPEED > 90) SSPEED = 0;
	SPR = 20;
	SPRY = 0;
	//LISA
	for(v = 0; v < 8;v+=2){
		if (SPRY > 180) SPRY = 0;
		move_sprite(v,SPRX+SPR,Lisa_Text_Pos[SPRY+SSPEED]-68);
		move_sprite(v+1,SPRX+SPR+8,Lisa_Text_Pos[SPRY+SSPEED]-68);
		SPR+= 14;
		SPRY+=3;
	}
	//NEEDS
	for(v = 8; v < 18;v+=2){
		if (SPRY > 180) SPRY = 0;
		move_sprite(v,SPRX+SPR,Lisa_Text_Pos[SPRY+SSPEED]-35);
		move_sprite(v+1,SPRX+SPR+8,Lisa_Text_Pos[SPRY+SSPEED]-35);
		SPR+= 14;
		SPRY+=2;
	}
	//DENTAL
	for(v = 18; v < 30;v+=2){
		if (SPRY > 180) SPRY = 0;
		move_sprite(v,SPRX+SPR,Lisa_Text_Pos[SPRY+SSPEED]+18);
		move_sprite(v+1,SPRX+SPR+8,Lisa_Text_Pos[SPRY+SSPEED]+18);
		SPR+= 10;
		SPRY+=7;
	}
	//PLAN
	for(v = 30; v < 37;v+=2){
		if (SPRY > 180) SPRY = 0;
		move_sprite(v,SPRX+SPR,Lisa_Text_Pos[SPRY+SSPEED]+70);
		move_sprite(v+1,SPRX+SPR+8,Lisa_Text_Pos[SPRY+SSPEED]+70);
		SPR+= 12;
		SPRY+=3;
	}
	
	SPRX--;
	SSPEED++;
	
	TIMER++;
	
	if (TIMER == 768){TIMER = 0; Scene++;}
}

