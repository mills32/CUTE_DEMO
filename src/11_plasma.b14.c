#include <gb/gb.h>

extern const unsigned char Plasma_Tiles[];
extern const unsigned char Plasma_TilesPAL[];
extern const unsigned char Plasma_MapPLN0[];
extern const unsigned char Plasma_MapPLN1[];
extern const unsigned char Plasma_Sprites[];
extern const unsigned char Plasma_SpritesPAL[];


extern UINT16 TIMER;
extern UINT8 Scene;
extern UINT8 v;



void Plasma_Set(){
    TIMER = 0; 
	
	VBK_REG = 0;	   
		set_bkg_tiles( 0, 0, 32, 18, Plasma_MapPLN0); //tiles
		set_bkg_data( 0, 32, Plasma_Tiles); //tile bank 1
		for (v = 0; v<20;v++)set_sprite_data(v, 1, Plasma_Sprites); ///Sprites
		for (v = 20; v<40;v++)set_sprite_data(v, 1, &Plasma_Sprites+16); ///Sprites
		for (v = 40; v<60;v++)set_sprite_data(v, 1, &Plasma_Sprites+32); ///Sprites
	VBK_REG = 1;	   
		set_bkg_tiles( 0, 0, 32, 18, Plasma_MapPLN1); //tiles
	VBK_REG = 0;	
	for (v = 0; v<10;v++) set_sprite_prop(v, 0x80);
	for (v = 10; v<20;v++) set_sprite_prop(v, 0x81);
	for (v = 20; v<30;v++) set_sprite_prop(v, 0x82);

	set_sprite_palette(0, 8, Plasma_SpritesPAL);
	set_bkg_palette(0, 8, Plasma_TilesPAL); //tile bank 1
	
	SHOW_SPRITES;
	SHOW_BKG;

	move_sprite(0,90,16);move_sprite(10,82,16);move_sprite(20,74,16);
	move_sprite(1,90,32);move_sprite(11,82,32);move_sprite(21,74,32);
	move_sprite(2,90,40);move_sprite(12,82,40);move_sprite(22,74,40);
	
	move_sprite(3,60,56);move_sprite(13,52,56);move_sprite(23,44,56);
	move_sprite(4,60,72);move_sprite(14,52,72);move_sprite(24,44,72);
	move_sprite(5,60,80);move_sprite(15,52,80);move_sprite(25,44,80);
	
	move_sprite(6,120,96); move_sprite(16,112,96); move_sprite(26,104,96);
	move_sprite(7,120,112);move_sprite(17,112,112);move_sprite(27,104,112);
	move_sprite(8,120,128);move_sprite(18,112,128);move_sprite(28,104,128);
	move_sprite(9,120,144);move_sprite(19,112,144);move_sprite(29,104,144);
	
	Scene++;
}	


void Plasma_Run(){
	if ((TIMER > 20) && (TIMER < 56))WY_REG+=4;
	if (TIMER == 630) WY_REG = 144;
	if ((TIMER > 630) && (TIMER < 666))WY_REG-=4;

	SCX_REG+=2;

	if (TIMER == 670) for (v = 0; v<24;v++) set_sprite_prop(v, 0x00);
	if (TIMER == 672){TIMER = 0; Scene++;for (v = 0;v<40;v++)move_sprite(v,200,200);}
	
	TIMER++;
}





