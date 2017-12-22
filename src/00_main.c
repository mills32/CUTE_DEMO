/***********************
    CUTE DEMO
		BY MILLS
************************	
Paste readme here
	
*/
#include <gb/gb.h>


//VARIABLES
UINT8 Scene; //The scene in which the demo is
UINT8 Part; //If the scene has parts
UINT16 TIMER; //A timer.. I should use the included one
UINT8 v; //whatever
UINT8 SPR; //Sprite numbers
UINT8 SPRX; //Sprite positions
UINT8 SPRY;
UINT8 SSPEED; //SPEED of.. whatever
UINT8 SSPEED1; //Another speed
UINT16 GFX_Offset; //Position in big data arrays for map and tile animations
UINT16 GFX_Offset2; //Position in big data arrays for map and tile animations
UINT8 MAP_X; //SCROLLING MAPS
UINT16 MAP_Y;  
UINT8 Map_PosX; 
UINT8 Map_PosY;   
UINT8 Scroll;      
UINT8 ScrollX;
UINT16 ScrollY;     
UINT16 Tile_Cnt; 

int SX;
int SY;
int Random;
int Random1;
UINT8 FontN; //I don't know


const unsigned char NULLT[] = {0x00,0x00,0x00,0x00};
const unsigned char Black_PAL[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
extern const unsigned char Window_MapPLN0[];
extern const unsigned char Window_MapPLN1[];
extern const unsigned char Win_Tiles[];
extern const unsigned char Win_TilesPAL[];


//Global functions

//Carillon Player Functions
void CP_LoadMusic(UINT8 bank,int song);
void CP_UpdateMusic();
void CP_StopMusic();

//MUSIC SPEED = TMC = 96 frames / Block

void Reset_LCD(){ 
	//WHY 39 - 51? I DON'T KNOW... 
	//THE RANGE IN WHIH THE ADDED VBL FUNCTIONS ARE, IS ALLWAYS 12 UNITS LONG
	//BUT THE START DEPENS ON HOW MANY DATA I STORE AT BANK 1
	UINT8 i;
	disable_interrupts();
	for (i=39;i!=51;++i)remove_VBL(i); 
	enable_interrupts();
	SCX_REG = 0; SCY_REG = 0;
}

void Reset_Palettes(){
	UINT8 X = 0; UINT8 Y = 0;
	VBK_REG = 1;
	for  (Y = 0; Y < 32; Y++){
		for  (X = 0; X < 32; X++) set_bkg_tiles( X, Y, 1, 1, NULLT); //tiles
	}
}

void Set_Transition_Window(){
	//SET WINDOW TILES PRIOPRITY TO 0x8 MANUALY
	VBK_REG = 0;
	set_win_tiles(0, 0, 20, 18, Window_MapPLN0); //tiles
	VBK_REG = 1;
	set_win_tiles(0, 0, 20, 18, Window_MapPLN1); //tiles
	set_bkg_data(0xF0, 32, Win_Tiles);
	set_bkg_palette(7, 1, Win_TilesPAL);
	WX_REG = 7;WY_REG = 0;
}
void Reset_Transition_Window(){
	VBK_REG = 0;
	set_win_tiles(0, 0, 20, 18, Window_MapPLN0); //tiles
	VBK_REG = 1;
	set_win_tiles(0, 0, 20, 18, Window_MapPLN1); //tiles
	WX_REG = 7;WY_REG = 0;
}

//SCENE FUNCTIONS

//Intro
void Intro_Set();
void Intro_Run();

//Cute Demo HColor Logo
void LoadHiClr (UINT8 bank, UINT8 time);

//Zilog Inside
void Zilog_Set();
void Zilog_Run();

//Perspective 3D
void Persp3D_Set();
void Persp3D_update();
void Perspective3D_Scanlines();
void Control0() {
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(5);
	Persp3D_update();
}

//3D Road
void Road3D_Set();
void Road3D_Run();
void Road3D_DMA();
void Control1() {
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(6);
	if (TIMER < 888)Road3D_DMA();
	if (TIMER == 910){Reset_Transition_Window();WY_REG = 144;}
	SWITCH_ROM_MBC1(3);
	Road3D_Run();
}

//Driving Homer
void Homer_Set();
void Homer_Run();
void Control2(){
	CP_UpdateMusic();	
	SWITCH_ROM_MBC1(3);
	Homer_Run();
}

//Cog
void Cog_Set();
void Cog_Run();
void Cog_Update();
void Control3() {
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(7);
	Cog_Update();
}

//Cog3D
void Cog3D_Set();
void Cog3D_Run();
void Cog3D_Update();
void Control4() {
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(8);
	Cog3D_Update();
}

//Lisa
void Lisa_Set();
void Lisa_Run();
void Control5() {
	CP_UpdateMusic();	
	SWITCH_ROM_MBC1(8);
	Lisa_Run();
}

//Sea
void Sea_Set();
void Sea_Run();
void Sea_Update();
void Control6() {
	CP_UpdateMusic();	
	SWITCH_ROM_MBC1(2);
	Sea_Update();
}


//3D Tower
void Tower_Set();
void Tower_Run();
void Control7(){
	CP_UpdateMusic();	
	SWITCH_ROM_MBC1(9);
	Tower_Run();
}

//Roto
void Roto_Set();
void Roto_Tiles_Set();
void Roto_Run();
void Control8A(){CP_UpdateMusic();SWITCH_ROM_MBC1(3);}
void Control8(){
	CP_UpdateMusic();	
	SWITCH_ROM_MBC1(10);
	Roto_Run();
}

//Plasma
void Plasma_Set();
void Plasma_Run();
void Control9(){
	CP_UpdateMusic();	
	SWITCH_ROM_MBC1(14);
	Plasma_Run();
}

//Vectors
void Vectors_Set();
void Vectors_Run();
void Vectors_Run_Sprites();
void Control10(){
	if (TIMER > 22)SCX_REG++;
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(13);
	if (TIMER > 40)Vectors_Run_Sprites();
	SWITCH_ROM_MBC1(12);
	Vectors_Run();
	if (TIMER == 730){Reset_Transition_Window();WY_REG = 144;}
}

//Parallax
void Parallax_Set();
void Parallax_Run();
void Parallax_Map_Run();
void Control11A(){CP_UpdateMusic();SWITCH_ROM_MBC1(11);}
void Control11(){
	if (TIMER == 1330) CP_LoadMusic(4,1);
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(11);
	Parallax_Run();
	SWITCH_ROM_MBC1(14);
	Parallax_Map_Run();
}

//Credits
void Credits_Set();
void Credits_Run();
void Control12(){
	SWITCH_ROM_MBC1(0);
	CP_UpdateMusic();	
	SWITCH_ROM_MBC1(15);
	Credits_Run();
}


///////////////////////////////////////////


//MAIN

void main(void){

	cpu_fast();
	
	Scene = 0; //Only for testing... some scenes won't work if loaded from start
	Part = 0;
	
	SPRITES_8x16; 
	SPR = 0; 
	for (v = 0; v<40;v++){set_sprite_tile(v, SPR);SPR+=2;}  
	SPR = 0;
	
	Set_Transition_Window();
	SHOW_WIN; //Manually change plane 1 properties to 0x8_ to be on top of sprites!!!
	
	TIMER = 0; 

	while(1){
		
		//the answer to life, the universe and everything.
		while (Scene == 42) {wait_vbl_done(); SWITCH_ROM_MBC1(6);}//to test things
		
		//Intro
		if  (Scene == 0) {Intro_Set();}	
		while  (Scene == 1) {Intro_Run();}
		//Cute Tortoise
		if  (Scene == 2) {LoadHiClr(2,10);Scene = 3;Set_Transition_Window();}
		//Zilog Inside
		if (Scene == 3) {CP_LoadMusic(4,0);Reset_Palettes();Zilog_Set();}
		while (Scene == 4) Zilog_Run();
		//3D Perspective
		if (Scene == 5) {Reset_LCD();add_VBL(Control0);SWITCH_ROM_MBC1(5);Persp3D_Set();}
		while (Scene == 6) {Perspective3D_Scanlines();}
		//3D ROAD
		if (Scene == 7) {Reset_LCD();add_VBL(Control1);wait_vbl_done();SWITCH_ROM_MBC1(3);Road3D_Set();}
		while (Scene == 8) wait_vbl_done();
		//HOMER
		if (Scene == 9) {Reset_LCD();add_VBL(Control2);SWITCH_ROM_MBC1(3);Homer_Set();}
		while (Scene == 10) wait_vbl_done();
		//Rotating 2D 
		if (Scene == 11) {Reset_LCD();add_VBL(Control3);SWITCH_ROM_MBC1(7);Cog_Set();}
		while (Scene == 12) Cog_Run();
		//3D 
		if (Scene == 13) {Reset_LCD();add_VBL(Control4);SWITCH_ROM_MBC1(8);Cog3D_Set();}
		while (Scene == 14) Cog3D_Run();
		//Lisa
		if (Scene == 15) {Reset_LCD();add_VBL(Control5);SWITCH_ROM_MBC1(8);Lisa_Set();}
		while (Scene == 16) wait_vbl_done();
		//Wavy Sea 
		if (Scene == 17) {Reset_LCD();add_VBL(Control6);SWITCH_ROM_MBC1(2);Sea_Set();}
		while (Scene == 18) Sea_Run();
		//3D Tower
		if (Scene == 19) {Reset_LCD();add_VBL(Control7);wait_vbl_done();SWITCH_ROM_MBC1(9);Tower_Set();}
		while (Scene == 20) wait_vbl_done();
		//Roto
		if (Scene == 21) {Reset_LCD();add_VBL(Control8A);SWITCH_ROM_MBC1(3);Roto_Tiles_Set();Reset_LCD();add_VBL(Control8);SWITCH_ROM_MBC1(10);Roto_Set();}
		while (Scene == 22) wait_vbl_done();	
		//Was going to be a Plasma, But I didn't like it
		if (Scene == 23) {Reset_LCD();add_VBL(Control9);SWITCH_ROM_MBC1(14);Plasma_Set();}
		while (Scene == 24) wait_vbl_done();		
		//Vectors: still a minor bug
		if (Scene == 25) {Reset_LCD();add_VBL(Control10);SWITCH_ROM_MBC1(12);Vectors_Set();}
		while (Scene == 26) wait_vbl_done();
		//Parallax
		if (Scene == 27) {Reset_LCD();add_VBL(Control11A);SWITCH_ROM_MBC1(11);Parallax_Set();delay(100);Reset_LCD();add_VBL(Control11);}
		while (Scene == 28) wait_vbl_done();
		//Credits
		if (Scene == 29) {Reset_LCD();add_VBL(Control12);wait_vbl_done();SWITCH_ROM_MBC1(15);Credits_Set();}
		while (Scene == 30) wait_vbl_done();

		//See you
		if (Scene == 31){
			CP_StopMusic();
			Reset_LCD();
			Scene = 2;
			TIMER = 0;
			delay(500);
			for (v = 0;v<40;v++){
				move_sprite(v,200,200);
				set_sprite_prop(v, 0x00);	
			}
			HIDE_SPRITES;
		}
	}
}
