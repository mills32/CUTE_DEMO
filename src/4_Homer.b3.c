#include <gb/gb.h>

extern const unsigned char Homer_MapPLN0[];
extern const unsigned char Homer_MapPLN1[];
extern const unsigned char Homer_TilesBLK0[];
extern const unsigned char Homer_TilesBLK1[];

extern const unsigned char Homer_Sprites[];
extern const unsigned char Homer_TilesPAL[];
extern const unsigned char Homer_SpritesPAL[];

const unsigned char Homer_SpritesCGB1[] =
{
  0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x02
};

extern UINT8 v;
extern UINT8 SPR;
extern UINT8 Scene;
extern UINT16 TIMER;
int HSX = 0;
int HSX1 = 0;
int HSX2 = 0;
int CSPEED = 0;
int HSPEED = 0;
int YC = -10;
int Wave[] = 
{0,-1,-2,-2,-3,-3,-3,-2,-2,-1,0,1,2,2,3,3,3,2,2,1,
0,-1,-2,-2,-3,-3,-3,-2,-2,-1,0,1,2,2,3,3,3,2,2,1
};
int Frame = 0;

void Homer_Set(){
	HIDE_SPRITES;
	VBK_REG = 0;	   
		set_bkg_tiles( 0, 0, 20, 20, Homer_MapPLN0); //maptiles
		set_bkg_data(0, 256, Homer_TilesBLK0); //tile bank 1
		set_sprite_data(0, 80, Homer_Sprites); ///Sprites
	VBK_REG = 1;	   
	   set_bkg_tiles( 0, 0, 20, 20, Homer_MapPLN1); //map colours 
	   set_bkg_data(0x0, 102, Homer_TilesBLK1); // tile bank 2	 +256
	   for (v = 0; v<40;v++) set_sprite_prop(v, Homer_SpritesCGB1[v] | 0x80 ); 
	    
	VBK_REG = 0;
	
	set_bkg_palette(0, 8, Homer_TilesPAL);
	set_sprite_palette(0, 3, Homer_SpritesPAL);
	
	SHOW_SPRITES;
	SHOW_BKG;
	
	Scene++;
}

void Homer_Run(){
	
	HSX++;
	if (CSPEED == 4) {CSPEED=0;HSX1++;}
	CSPEED++;
		
	if (Frame == 18) Frame = 0;
	SCY_REG = 7+Wave[Frame];
	if (HSPEED == 2){HSPEED = 0; Frame++;}
	HSPEED++;	

	TIMER++;
	
	if ((TIMER > 16) && (TIMER < 56)) WX_REG+=4;
	if ((TIMER > 910) && (TIMER < 950)) WX_REG-=4;
	
	
	//Bush1
	move_sprite(3,HSX,128); move_sprite(4,8+HSX,128);
	move_sprite(5,-8+HSX,144); move_sprite(6,HSX,144);move_sprite(7,8+HSX,144); move_sprite(8,16+HSX,144);
    //Bush2
	move_sprite(9,124+HSX,112); move_sprite(10,132+HSX,112);
	move_sprite(11,116+HSX,128); move_sprite(12,124+HSX,128);move_sprite(13,132+HSX,128); 
	move_sprite(14,108+HSX,144); move_sprite(15,116+HSX,144);move_sprite(16,124+HSX,144);move_sprite(17,132+HSX,144); move_sprite(18,140+HSX,144);
    //Cloud 1
    move_sprite(19,24+HSX1,24);move_sprite(20,32+HSX1,24);move_sprite(21,40+HSX1,24);
    move_sprite(22,16+HSX1,40);move_sprite(23,24+HSX1,40);move_sprite(24,32+HSX1,40);move_sprite(25,40+HSX1,40);move_sprite(26,48+HSX1,40);
	//Cloud 2
    move_sprite(27,152+HSX1,40); move_sprite(28,160+HSX1,40);
	move_sprite(29,144+HSX1,56);move_sprite(30,152+HSX1,56);move_sprite(31,160+HSX1,56);move_sprite(32,168+HSX1,56);
    move_sprite(33,136+HSX1,72);move_sprite(34,144+HSX1,72);move_sprite(35,152+HSX1,72);move_sprite(36,160+HSX1,72);move_sprite(37,168+HSX1,72); move_sprite(38,176+HSX1,72);
    //Minicloud
	move_sprite(39,-20+HSX1,60); 	
	
	
	if (TIMER == 960){
		TIMER = 0;
		Scene++;
		for (v = 0;v<40;v++)move_sprite(v,200,200);
	}
}



