#include <gb/gb.h>

extern const unsigned char Zilog_Tiles[];
extern const unsigned char Zilog_Sprites[];
extern const unsigned char Zilog32PLN0[];
extern UINT16 TIMER;

extern UINT8 Scene;
extern UINT8 v;
extern UINT8 SPR;
UINT16 RPal;
	
void Set_Lines_Pal(UINT16 *rgb_data);

void CP_UpdateMusic();

extern const UWORD Zilog_SpritesPAL[];
extern const UWORD Zilog_TilesPAL[];
extern const UWORD ZilogDegrade[];

void Zilog_VBL();

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
	
	add_VBL(Zilog_VBL);
	enable_interrupts();
	Scene++;
}	

void Zilog_Run(){
	Set_Lines_Pal(ZilogDegrade);
}
