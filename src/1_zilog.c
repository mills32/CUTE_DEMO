#include <gb/gb.h>

extern const unsigned char Zilog_Tiles[];
extern const unsigned char Zilog_Sprites[];
extern const unsigned char Zilog32PLN0[];
extern UINT16 TIMER;

extern UINT8 Scene;
extern UINT8 v;
extern UINT8 SPR;
UINT16 RPal;	
void Set_First_Palette_Col(UINT16 *rgb_data);

void CP_UpdateMusic();

extern const UWORD Zilog_SpritesPAL[];
extern const UWORD Zilog_TilesPAL[];
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


void zilog_VBL(){
	CP_UpdateMusic();
	SCX_REG++; SCY_REG++;
	
	if ((TIMER > 348) && (WY_REG > 0))WY_REG-=4;
	if (TIMER == 384){TIMER = 0; Scene++;}
	TIMER++;
}


void Zilog_Set(){
	WY_REG = 144;
    TIMER = 0; 
 
	wait_vbl_done();
	DISPLAY_OFF;
	
	VBK_REG = 0;	   
		set_bkg_tiles( 0, 0, 32, 32, Zilog32PLN0); //tiles
		set_bkg_data( 0, 159, Zilog_Tiles); //tile bank 1
		set_sprite_data(0, 26, Zilog_Sprites);
	
	set_bkg_palette(0, 1, Zilog_TilesPAL); //tile bank 1
	set_sprite_palette( 0, 1, Zilog_SpritesPAL);
	
    DISPLAY_ON;
	SHOW_BKG;
	SHOW_SPRITES;
	SHOW_WIN;
	
	for (v = 0; v<10;v++) move_sprite(v,((v+2)*8),16);
	for (v = 10; v<13;v++) move_sprite(v,((v+5)*8)-40,36);
	
	add_VBL(zilog_VBL);
	enable_interrupts();
	Scene++;
}	

void Zilog_Run(){
	RPal = LY_REG;
	Set_First_Palette_Col(&ZilogDegrade+RPal);
}