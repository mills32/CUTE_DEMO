#include <gb/gb.h>

extern const unsigned char Parallax_Tiles[];
extern const unsigned char Parallax_TilesPAL[];
extern const unsigned char Parallax_Anim[];
extern const unsigned char Parallax_Sprites[];
extern const unsigned char Parallax_SpritesPAL[];


const unsigned char Parallax_SpritesCGB1[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0x02,0x00,0x00,0x00,0x01,
  0x01,0x00,0x00,0x00,0x03,0x02,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
 
const signed char SINE[] = 
{
	0, 2, 4, 6, 8, 9,
	11, 12, 13, 14, 14, 15, 15, 15, 16, 16,
	16, 16, 15, 15, 15, 14, 14, 13, 11, 10,
	8, 6, 4, 2, -1, -3, -5, -7, -9, -10,
	-11, -11, -12, -12, -13, -13, -14, -14, -14, -15,
	-15, -15, -14, -14, -13, -13, -12, -12, -11, -10,
	-9, -7, -5, -3, -1, 2
};

extern UINT8 v;
extern UINT8 SPRX;         //Meta Sprite pos x
extern UINT8 SPRY;         //Meta Sprite pos y
extern UINT8 SPR;           //Meta Sprite number
extern UINT8 SSPEED;		   
extern UINT8 SSPEED1;	
extern UINT8 Scene;
extern UINT16 GFX_Offset;	   //GFX_Offset Frame
extern UINT16 GFX_Offset2;
extern UINT16 TIMER;
extern UINT8 Part;

extern UINT8 MAP_X;
extern UINT16 MAP_Y;    
extern UINT8 Scroll;      
extern UINT8 ScrollX;     
extern UINT16 Tile_Cnt; 


UINT8 XP;            //Move Sprites
UINT8 YP; 

extern const UWORD LisaDegrade[];
void WAIT_SCANLINE2();
void Set_Lines_Pal(UINT16 *rgb_data);

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); //in asm 

void Parallax_Set() {
	set_bkg_palette(0, 8, Parallax_TilesPAL);	
	set_sprite_palette( 0, 8, Parallax_SpritesPAL);	

	VBK_REG = 0;	// switch to Video Bank 0
		set_bkg_data(0, 81, Parallax_Tiles); // tiles0
		set_sprite_data(0, 80, Parallax_Sprites);		
	VBK_REG = 1;
		for (v = 0; v<40;v++)set_sprite_prop(v, Parallax_SpritesCGB1[v]);
	VBK_REG = 0;
	
	SHOW_BKG;
	SHOW_SPRITES;
	
    v = 0;
	SPRX = 0;         //Meta Sprite pos x
	SPRY = 0;         //Meta Sprite pos y
	SPR = 0;           //Meta Sprite number
	
	SSPEED = 0;		   //BKG Speed
	SSPEED1 = 0;		   //GFX_Offset Speed
    GFX_Offset = 0;	   //GFX_Offset Frame
	
	MAP_Y = 0;
	
	XP = 170;            //Move Sprites
	YP = 40; 
	Scene++;
	ScrollX = 22;
	SCY_REG = 0;
	Tile_Cnt = 0;
}

void Parallax_Run() {	
	if ((SCX_REG < 172)&&(TIMER < 40)){SCX_REG+=8; MAP_X+=8;}
	if (TIMER > 40){SCX_REG+=2; MAP_X+=2;}
	
	if ((TIMER > 40) && (TIMER < 81))WX_REG+=4;
	if ((TIMER > 1490) && (TIMER < 1531))WX_REG-=4;

	//GFX_Offset
    if (GFX_Offset == 20) GFX_Offset = 0; 
	if (SSPEED1 == 2){
		GFX_Offset2 = GFX_Offset*544;
		VBK_REG = 0;
		DMA_TRANSFER(34, Parallax_Anim+GFX_Offset2,(UINT16*)0x92D0); 
		SSPEED1 = 0; 
		GFX_Offset++;
	}
    SSPEED1++;
	//SHIP SINE
    if (v == 60) v = 0;
    YP = 50 + SINE[v];
	v++;
	
	//SHIP X
	if ((TIMER > 200)&&(TIMER < 440)){
		if (XP == 40) XP = 40;
		else XP++;
	}
	if ((TIMER > 1420) && (XP < 160)) XP+=2;
    
	//SHIP
	move_sprite(0, XP, YP);move_sprite(1, XP+8, YP);
	move_sprite(2, XP+16, YP);move_sprite(3, XP+24, YP);
	move_sprite(4, XP+32, YP);move_sprite(5, XP+40, YP);
	move_sprite(6, XP+48, YP);move_sprite(7, XP+56, YP);
	move_sprite(8, XP+64, YP);
	
	move_sprite(10, XP, YP+16);move_sprite(11, XP+8, YP+16);
	move_sprite(12, XP+16, YP+16);move_sprite(13, XP+24, YP+16);
	move_sprite(14, XP+32, YP+16);move_sprite(15, XP+40, YP+16);
	move_sprite(16, XP+48, YP+16);move_sprite(17, XP+56, YP+16);
	move_sprite(18, XP+64, YP+16);move_sprite(19, XP+72, YP+16);
	
	move_sprite(20, XP, YP+32);move_sprite(21, XP+8, YP+32);
	move_sprite(22, XP+16, YP+32);move_sprite(23, XP+24, YP+32);
	move_sprite(24, XP+32, YP+32);move_sprite(25, XP+40, YP+32);
	move_sprite(26, XP+48, YP+32);move_sprite(27, XP+56, YP+32);
	move_sprite(28, XP+64, YP+32);move_sprite(29, XP+72, YP+32);
	
	move_sprite(30, XP, YP+48);move_sprite(31, XP+8, YP+48);
	move_sprite(32, XP+16, YP+48);move_sprite(33, XP+24, YP+48);
	move_sprite(34, XP+32, YP+48);move_sprite(35, XP+40, YP+48);
	move_sprite(36, XP+48, YP+48);move_sprite(37, XP+56, YP+48);
	move_sprite(38, XP+64, YP+48);
	
	//SCROLL
	SPR = 0;
	if (MAP_X == 8){ MAP_X = 0; Scroll = 1;}
	if (TIMER == 1536){
		TIMER = 0;
		WY_REG = 0;
		Scene++;
		for (v = 0;v<40;v++)move_sprite(v,200,200);	
	}

	TIMER++;

}	

UINT8 Pl;
void Parallax_Deg(){
	Set_Lines_Pal(LisaDegrade);
}