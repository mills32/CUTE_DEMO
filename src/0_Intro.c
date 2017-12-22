#include <gb/gb.h>

extern UINT16 TIMER;
extern UINT8 Part;
extern UINT8 Scene;
extern const UWORD Intro_TilesPAL[]; //BLACK, RED, GREEN, WHITE
extern const unsigned char Intro_Tiles[];
extern const unsigned char Intro_MapPLN0[];
extern const unsigned char Intro_MapPLN1[];

UINT8 Loading;
extern UINT8 v;
#define PAL_DEF(C3, C2, C1, C0) ((C0 << 6) | (C1 << 4) | (C2 << 2) | C3)
void Intro_Set(){
	WY_REG = 144;
	VBK_REG = 0;
	   set_bkg_data(0, 64, Intro_Tiles); 
	DISPLAY_ON;
	SHOW_BKG;

	if(_cpu == 0x01) { 
		BGP_REG = PAL_DEF(0, 0, 1, 3);
		VBK_REG = 0;
		set_bkg_tiles( 0, 0, 20, 18, Intro_MapPLN0);
		Scene++;
		Part = 20;
	}
	if(_cpu == 0x11) {// if CGB
		set_bkg_palette(0, 8, Intro_TilesPAL); 	
		VBK_REG = 0;	   
		set_bkg_tiles( 0, 0, 20, 82, &Intro_MapPLN0+180);
		VBK_REG = 1;	   
		set_bkg_tiles( 0, 0, 20, 82, &Intro_MapPLN1+180); 
		waitpad(J_A);
		delay(1000);
		VBK_REG = 0;	   
		set_bkg_tiles( 0, 0, 20, 18, &Intro_MapPLN0+360);
		VBK_REG = 1;	   
		set_bkg_tiles( 0, 0, 20, 18, &Intro_MapPLN1+360); 
		waitpad(J_A);
		Loading = 0;
		Part = 0;
		Scene++;
	}
	
}

void Intro_Run(){
	

	if (Part == 0){
		VBK_REG = 0;	   
		set_bkg_tiles( 0, 0, 20, 18, &Intro_MapPLN0+540);
		VBK_REG = 1;	   
		set_bkg_tiles( 0, 0, 20, 18, &Intro_MapPLN1+540); 
		Loading = 59;
		v = 5;
		Part = 1;
	}
	
	if (Part == 1){	
		VBK_REG = 0;
		set_bkg_tiles( v, 9, 1, 1, &Loading);
		if (v == 5)set_bkg_tiles( 5, 13, 10, 1, &Intro_MapPLN0+((73*20)/2));
		if (v == 7)set_bkg_tiles( 5, 13, 10, 1, &Intro_MapPLN0+((72*20)/2));
		if (v == 9)set_bkg_tiles( 5, 13, 10, 1, &Intro_MapPLN0+((74*20)/2));
		Loading++;
		if (Loading == 63) {Loading = 59;v++;}
		if (v > 10) Part = 2;
		delay(300);
	}	
	
	if (Part == 2) {
		set_bkg_tiles( 0, 13, 20, 2, &Intro_MapPLN0+((75*20)/2));
		delay(3000); 
		set_bkg_tiles( 0, 13, 20, 3, &Intro_MapPLN0+((77*20)/2));
		delay(3000); 
		Part = 3;
		TIMER = 0;
	}
	if (Part == 3){
		SCX_REG++;
		if (LY_REG == 0)TIMER++;
		if (TIMER == 300) {TIMER = 0; Scene++; Part = 0; cpu_fast();SCX_REG = 0;} //Go to next program
		
	}
	
	if (Part == 20) wait_vbl_done();
	
}
