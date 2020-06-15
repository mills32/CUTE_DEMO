#include <gb/gb.h>

extern const unsigned char Roto_Map[];
extern const unsigned char Roto_Sprites[];
extern const unsigned char Roto_SpritesPAL[];
extern const unsigned char Roto_Map_Anim[];

extern UINT8 Scene;
extern UINT8 v;
extern UINT8 SSPEED;
extern UINT16 GFX_Offset;
extern UINT8 SPR;
extern UINT8 SPRX;
extern UINT8 SPRY;
extern UINT16 TIMER;

UINT8 RotoFrame;

const unsigned char RotoSpritesCGB[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,
	0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,
	0x81,0x81,0x81,0x81,0x81,0x81
};

void Roto_Set() {
	VBK_REG = 0;	
		set_bkg_tiles(0, 0, 20, 18, Roto_Map_Anim);
		set_sprite_data( 0, 72, Roto_Sprites);//in 8x8 blocks!!!
	VBK_REG = 1; //palette plane
		set_bkg_tiles(0, 0, 20, 18, Roto_Map);
	VBK_REG = 0; 
	
	set_sprite_palette( 0, 3, Roto_SpritesPAL);
	SHOW_SPRITES;
	SHOW_BKG;
	SSPEED = 0;
	GFX_Offset = 0;
	RotoFrame = 0;
	Scene++;
}

void Roto_Run(){
	if(TIMER == 12)for (v = 0; v<36;v++) set_sprite_prop(v,RotoSpritesCGB[v]);
	if ((TIMER > 12) && (TIMER < 53))WX_REG+=4;
	if ((TIMER > 630) && (TIMER < 671))WX_REG-=4;
	
	if(SSPEED == 3){
		if (RotoFrame == 38) {RotoFrame = 0; GFX_Offset = 0;}

		//Change map frame
		VBK_REG = 0;
		set_bkg_tiles(0, 0, 20, 18, Roto_Map_Anim+GFX_Offset);	
		
		GFX_Offset+= 360;
		RotoFrame++;
		SSPEED = 0;
	}
	
	SSPEED++;
	TIMER++;
	
	SPR = 0;
	for (v = 0;v<8;v++){
		move_sprite(v,30+SPR+SPRX,28);
		SPR+=7;
	}
	SPR = 0;
	for (v = 8;v<12;v++){
		move_sprite(v,80+SPR+SPRX,52);
		SPR+=7;
	}
	SPR = 0;
	for (v = 12;v<22;v++){
		move_sprite(v,120+SPR+SPRX,72);
		SPR+=7;
	}
	move_sprite(20,170+SPRX,92);move_sprite(21,178+SPRX,92);
	SPR = 0;
	for (v = 22;v<30;v++){
		move_sprite(v,180+SPR+SPRX,116);
		SPR+=7;
	}
	SPR = 0;
	for (v = 30;v<36;v++){
		move_sprite(v,240+SPR+SPRX,132);
		SPR+=7;
	}
	SPRX--;
	
	
	if (TIMER == 672){TIMER = 0; Scene++;for (v = 0;v<40;v++)move_sprite(v,200,200);}
}
