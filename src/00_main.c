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
UINT8 SSPEED2; //Another speed
UINT8 SSPEED3; //Another speed
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
	SWITCH_ROM_MBC1(1);
	set_bkg_data(0xB0, 72, Win_Tiles);//B0 Tile position in 2º bank = 432-256 = B0
	set_bkg_palette(7, 1, Win_TilesPAL);
	WX_REG = 7;WY_REG = 0;
}
void Reset_Transition_Window(){
	VBK_REG = 0;
	set_win_tiles(0, 0, 20, 18, Window_MapPLN0); //tiles
	VBK_REG = 1;
	set_win_tiles(0, 0, 20, 18, Window_MapPLN1);

	//WX_REG = 7;WY_REG = 0;
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
void Zilog_VBL(){
	CP_UpdateMusic();
	SCX_REG++; SCY_REG++;
	
	if ((TIMER > 348) && (WY_REG > 0))WY_REG-=4;
	if (TIMER == 384){TIMER = 0; Scene++;}
	TIMER++;
}

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
	if (TIMER < 910)Road3D_DMA();
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

//Boat
void Boat_Set();
void Boat_Run();
void Boat_Run2();
void Boat_Run_Sprites();
void Control10(){
	if (TIMER > 22)SCX_REG++;
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(13);
	if (TIMER > 40)Boat_Run_Sprites();
	SWITCH_ROM_MBC1(12);
	Boat_Run();
	//if (TIMER == 730){Reset_Transition_Window();WY_REG = 144;}
}

//Parallax
void Parallax_Set();
void Parallax_Run();
void Parallax_Deg();
void Parallax_Map_Run();
void Control11A(){CP_UpdateMusic();SWITCH_ROM_MBC1(11);}
void Control11(){
	if (TIMER == 1330) CP_LoadMusic(4,1);
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(14);
	Parallax_Map_Run();
	SWITCH_ROM_MBC1(11);
	Parallax_Run();
}

//Credits
void Credits_Set();
void Credits_Run();
void Credits_Run2();
void Control12(){
	CP_UpdateMusic();
	SWITCH_ROM_MBC1(15);
	Credits_Run();
}

//So, remove VBL was fixed in GBDK 3.0!
void Reset_LCD(){ 
	disable_interrupts();
	switch (Scene){
		case 5: remove_VBL(Zilog_VBL);break;
		case 7: remove_VBL(Control0); break;
		case 9: remove_VBL(Control1); break;
		case 11: remove_VBL(Control2); break; 		
		case 13: remove_VBL(Control3); break; 
		case 15: remove_VBL(Control4); break; 
		case 17: remove_VBL(Control5); break; 
		case 19: remove_VBL(Control6); break; 
		case 21: remove_VBL(Control7); break; 
		case 23: remove_VBL(Control8); break; 
		case 25: remove_VBL(Control9); break; 
		case 27: remove_VBL(Control10); break; 
		case 29: remove_VBL(Control11); break; 
		case 31: remove_VBL(Control12); break; 
	}
	enable_interrupts();
	SCX_REG = 0; SCY_REG = 0;
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
	
	//Set_Transition_Window();
	//Set Window plane 1 properties to | 0x80 to be on top of sprites!!!
	SHOW_WIN; 
	
	TIMER = 0; 
	//CP_LoadMusic(4,0);
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
		if (Scene == 21) {Reset_LCD();add_VBL(Control8A);SWITCH_ROM_MBC1(3);Roto_Tiles_Set();Reset_LCD();remove_VBL(Control8A);add_VBL(Control8);SWITCH_ROM_MBC1(10);Roto_Set();}
		while (Scene == 22) wait_vbl_done();	
		//Board
		if (Scene == 23) {Reset_LCD();add_VBL(Control9);SWITCH_ROM_MBC1(14);Plasma_Set();}
		while (Scene == 24) wait_vbl_done();		
		//Boat:
		if (Scene == 25) {Reset_LCD();add_VBL(Control10);SWITCH_ROM_MBC1(12);Boat_Set();}
		while (Scene == 26) Boat_Run2();
		//Parallax
		if (Scene == 27) {Reset_LCD();add_VBL(Control11A);SWITCH_ROM_MBC1(11);Parallax_Set();delay(100);Reset_LCD();remove_VBL(Control11A);add_VBL(Control11);}
		while (Scene == 28) Parallax_Deg();
		//Credits
		if (Scene == 29) {Reset_LCD();add_VBL(Control12);wait_vbl_done();SWITCH_ROM_MBC1(15);Credits_Set();}
		while (Scene == 30) Credits_Run2();

		//See you
		if (Scene == 31){
			HIDE_BKG;
			HIDE_WIN;
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


UINT16 *pal_addr;

void Set_Lines_Pal(UINT16 *rgb_data){//Change first color of palette 0
	__asm
	PUSH	BC
	PUSH	DE

	LDA	HL,7(SP)		// Skip return address and registers
	LD	A,(HL-)
	LD	(#_pal_addr),A
	LD	A,(HL)
	LD	(#_pal_addr+1),A

	.waitSCANL:
    LDH	A,(0x41)		//STAT REG 
	AND	#0x02       	 
    JR	NZ,.waitSCANL	//Wait for stat
	
	LD    	A,#0x80
	LDH    	(0x68),A	//setup palette 0 write.
	
	LD		A,(#_LY_REG)	//Get Line
	LD		D,#0
	LD		E,A				//Store line in DE
	LD		A,(#_pal_addr)	//Get Palettes address
	LD		H,A
	LD		A,(#_pal_addr+1)		
	LD		L,A				//HL = palettes address
	ADD		HL,DE
	ADD		HL,DE			//Add line to palettes address
	LD		A,(HL+)
	LDH   	(0x69),A		//Write values to palette register
	LD		A,(HL)
	LDH   	(0x69),A

	POP	DE
	POP	BC
	__endasm;
	rgb_data;
}

void Set_Lines_Pal2(UINT16 *rgb_data){//Change first color of palettes 0 and 1
	__asm
	PUSH	BC
	PUSH	DE

	LDA	HL,7(SP)		// Skip return address and registers
	LD	A,(HL-)
	LD	(#_pal_addr),A
	LD	A,(HL)
	LD	(#_pal_addr+1),A

	.waitSCANL3:
    LDH	A,(0x41)		//STAT REG 
	AND	#0x02       	 
    JR	NZ,.waitSCANL3	//Wait for stat
	
	LD		A,(#_LY_REG)	//Get Line
	LD		D,#0
	LD		E,A				//Store line in DE
	LD		A,(#_pal_addr)		//Get Palettes address
	LD		H,A
	LD		A,(#_pal_addr+1)		
	LD		L,A				//HL = palettes address
	ADD		HL,DE
	ADD		HL,DE			//Add line to palettes address
	
	LD    	A,#0x80
	LDH    	(0x68),A		//setup palette 0 write.
	
	LD		A,(HL+)
	LDH   	(0x69),A		//Write values to palette register
	LD		A,(HL-)
	LDH   	(0x69),A
	
	LD    	A,#0x88
	LDH    	(0x68),A		//setup palette 1 write.
	
	LD		A,(HL+)
	LDH   	(0x69),A		//Write values to palette register
	LD		A,(HL)
	LDH   	(0x69),A

	POP	DE
	POP	BC
	__endasm;
	rgb_data;
}

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination){
	__asm
	PUSH	BC
	
	LDA		HL,9(SP)		; parameters 
	DEC		HL
	LD		D,(HL)			; DE = data destination address
	DEC		HL
	LD		E,(HL)
	
	LD		A,D
	LDH		(0x53),A      	; Load upper byte into destination register
	LD		A,E
	LDH		(0x54),A      	; Load lower byte into destination register

	DEC		HL
	LD		B,(HL)			; BC = data source address
	DEC		HL
	LD		C,(HL)
	
	LD		A,B	
    LDH		(0x51),A		; Load upper byte into source register
	LD		A,C
	LDH		(0x52),A    	; Load lower byte into source register
    
	DEC		HL				; Get number of tiles from parameter
    LD		A,(HL)			
    DEC		A				; Number of tiles -1 (4*4)
	LDH		(0x55),A      	; Start transfer
	
	POP		BC
	__endasm;
	tiles;source;destination;
}

const UWORD ZilogDegrade[] =
{
	25696, 25696, 25696, 25696, 25696, 25696, 25696, 25696, 
	25696, 25696, 25696, 25696, 25696, 25696, 25696, 25696, 
	25696, 25696, 25696, 25696, 25696, 25696, 25696, 25696, 
	25696, 25696, 25696, 25696, 25696, 25696, 25696, 25696, 
	25696, 25696, 25696, 25696, 25696, 25696, 25696, 26752, 
	26752, 26784, 26784, 26784, 26816, 26816, 26848, 26848, 
	26880, 26880, 26880, 26912, 27936, 27936, 27968, 27968, 
	28000, 28000, 28032, 28032, 28032, 28064, 28064, 28064, 
	29120, 29120, 29152, 29152, 29153, 29185, 29185, 29217, 
	29217, 29217, 29249, 30273, 30305, 30305, 30306, 30338, 
	30338, 30370, 30402, 30435, 31491, 31523, 31555, 31588, 
	31620, 32676, 32709, 32709, 32741, 32741, 32742, 32742, 
	32742, 32742, 32743, 32745, 32747, 32750, 32752, 32754, 
	32757, 32759, 32762, 32766, 32767, 32767, 32767, 32767, 
	32767, 32767, 30719, 28671, 27646, 25597, 24571, 22522, 
	21496, 20471, 19445, 18420, 17363, 16305, 14256, 13199, 
	12142, 11117, 10059, 9034, 9001, 7944, 6919, 5862, 
	4805, 3780, 2723, 1698, 1665, 640, 608, 608
};

const UWORD C3DDegrade[] =
{
	24358, 24358, 24358, 24358, 24358, 23301, 23204, 22051, 
	20931, 20898, 20834, 20802, 19777, 19745, 19713, 19681, 
	19680, 19648, 18592, 18560, 18560, 18592, 19648, 19680, 
	19681, 19713, 19745, 19777, 20802, 20834, 20866, 20898, 
	20930, 20931, 22019, 22084, 22116, 23237, 23269, 24358, 
	24390, 24391, 24391, 24424, 24425, 24425, 24426, 24426, 
	25451, 25451, 25452, 25453, 25485, 25486, 25486, 25487, 
	25487, 25488, 26512, 26513, 26513, 26546, 26547, 26547, 
	26548, 26550, 27575, 27608, 27609, 27610, 27611, 27612, 
	28669, 28670, 28671, 25532, 23450, 21368, 20310, 19252, 
	17171, 16146, 15089, 14031, 12974, 11949, 10892, 9867, 
	9834, 8809, 7752, 6727, 5670, 4613, 4612, 3555, 
	2531, 1474, 1473, 448, 448, 1473, 1474, 2531, 
	3555, 4612, 4613, 5670, 6727, 7752, 8809, 8810, 
	9867, 10892, 11949, 13006, 14031, 15088, 15120, 14095, 
	14094, 15118, 15150, 15150, 16173, 16173, 16172, 17195, 
	18219, 19242, 20265, 21289, 22312, 23368, 24360, 24358, 
	24358, 24358, 24358, 24358, 24358, 24358, 24358, 24358,
	24358, 24358, 24358
};

const UWORD SeaDegrade[] =
{
	31680, 31680, 31680, 31680, 31680, 31680, 31680, 31680, 
	31680, 31680, 31680, 31680, 31680, 31680, 31680, 31680, 
	31680, 31680, 31680, 31680, 31680, 31680, 31680, 31680, 
	31680, 31680, 31680, 31680, 31680, 31680, 31680, 31680, 
	30624, 30592, 30561, 29537, 29505, 28449, 28417, 27394, 
	27362, 26306, 26306, 26275, 25219, 25219, 25187, 24131, 
	24132, 23076, 23044, 23044, 21988, 21957, 20933, 20901, 
	20869, 19845, 19813, 19813, 19813, 19781, 19781, 19781, 
	18725, 18724, 18692, 18692, 18692, 18660, 18660, 18660, 
	17604, 17604, 17603, 17604, 17603, 17603, 17603, 17603, 
	17571, 17571, 17571, 17571, 17571, 17571, 17571, 17571, 
	17539, 17539, 17539, 17539, 17539, 17539, 17539, 17539, 
	16483, 16483, 16483, 16483, 16483, 16483, 16482, 16482, 
	16482, 16482, 16482, 16546, 16579, 17667, 18757, 19845, 
	20901, 20901, 21957, 21988, 23044, 24100, 24131, 25187, 
	25219, 26274, 27330, 27394, 28449, 29505, 29537, 30592, 
	31648, 31680, 31680, 31680, 31680, 31680, 31680, 31680, 
	31680, 31680, 31680, 31680, 31680, 31680, 31680, 31680
};



const UWORD LisaDegrade[] = {
	32359, 32359, 32359, 32359, 32359, 32359, 32359, 32359, 
	32359, 32359, 32359, 32359, 32359, 32359, 32359, 32359, 
	32359, 32359, 32359, 32359, 32359, 32359, 32359, 32359, 
	32360, 32359, 31303, 30246, 29190, 28133, 27077, 26020, 
	24932, 23875, 22819, 21762, 20705, 19649, 18592, 17536, 
	16448, 17504, 18560, 19616, 20672, 22752, 23808, 24864, 
	25920, 28000, 29088, 29088, 29088, 29088, 29088, 30144, 
	30176, 30208, 30208, 30240, 30272, 30304, 31360, 31392, 
	31424, 31456, 31456, 31488, 31520, 32577, 32609, 32641, 
	32673, 32705, 32705, 32737, 32737, 32737, 32737, 32737, 
	32737, 32737, 32737, 32737, 32737, 32737, 32737, 32737, 
	32737, 32737, 32737, 32737, 32737, 32672, 32608, 32544, 
	31424, 30304, 30240, 29152, 28064, 28000, 26912, 25856, 
	25792, 24704, 23616, 23584, 23552, 23552, 23552, 22560, 
	23584, 23584, 23616, 24640, 24672, 24672, 24737, 23745, 
	23778, 22787, 22852, 21861, 20870, 20903, 20968, 19977, 
	18986, 19019, 18028, 17036, 16045, 15053, 14062, 14095, 
	13104, 13104, 13104, 22286, 28331, 32359, 32359, 32359
};

const UWORD CreditsDegrade[] =
{
	31, 31, 31, 31, 31, 31, 31, 31, 
	1055, 3103, 4127, 6175, 7199, 9247, 10271, 11295, 
	13343, 14367, 16415, 17439, 19487, 20511, 21535, 23583, 
	24607, 26655, 27679, 29727, 30751, 31775, 31774, 31773, 
	31771, 31770, 31768, 31767, 31765, 31764, 31762, 31761, 
	31760, 31758, 31757, 31755, 31754, 31752, 31751, 31750, 
	31748, 31747, 31745, 31744, 31776, 31808, 31872, 31904, 
	31968, 32000, 32064, 32096, 32128, 32192, 32224, 32288, 
	32320, 32384, 32416, 32448, 32512, 32544, 32608, 32640, 
	32704, 32736, 32736, 30688, 29664, 27616, 26592, 24544, 
	23520, 21472, 20448, 19424, 17376, 16352, 14304, 13280, 
	11232, 10208, 8160, 7136, 6112, 4064, 3040, 992, 
	992, 994, 995, 997, 998, 1000, 1001, 1002, 
	1004, 1005, 1007, 1008, 1010, 1011, 1012, 1014, 
	1015, 1017, 1018, 1020, 1021, 1023, 1023, 991, 
	927, 895, 831, 799, 735, 703, 671, 607, 
	575, 511, 479, 415, 383, 319, 287, 255, 
	191, 159, 95, 63, 31, 31, 31, 31
};