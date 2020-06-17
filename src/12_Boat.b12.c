#include <gb/gb.h>

extern const unsigned char Vector_Tiles[];
extern const unsigned char Vector_TilesPAL[];
extern const unsigned char Vector_Anim_Water[]; 
extern const unsigned char Vector_MapPLN0[];
extern const unsigned char Vector_MapPLN1[];
extern const unsigned char Vector_Map_WaterPLN0[];
extern const unsigned char Vector_Map_WaterPLN1[];
extern const unsigned char Window_MapPLN0[];
extern const unsigned char Window_MapPLN1[];
const unsigned char Delete_Sprites[] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0	
};
const extern UWORD C3DDegrade[];
 
const UWORD Boat_SPAL[] = {31507,30718,31,0};//32168

const UINT8 Wave_Y[] = {8, 9,
11, 13, 14, 15, 15, 15, 15, 14, 13, 11,
9, 7, 5, 4, 2, 1, 0, 0, 0, 0,
1, 3, 4, 6, 8, 8};

extern UINT16 TIMER;
extern UINT8 SPR;
extern UINT8 SPRX;
extern UINT8 SPRY;
extern UINT8 v;
extern UINT8 SSPEED;
extern UINT8 SSPEED1;
extern UINT8 SSPEED2;
extern UINT16 GFX_Offset;
extern UINT16 GFX_Offset2;
extern UINT16 Tile_Cnt; //Used here to revert boat frame count
extern UINT8 Scene;
UINT8 SSTATE;
UINT8 SeaLine;
UINT8 SeaTile; 

void Reset_Transition_Window();
void Set_Lines_Pal2(UINT16 *rgb_data);
void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

void Boat_Set() {
	
	VBK_REG = 0;
		set_bkg_data(0, 64, Vector_Tiles);
		set_bkg_tiles( 0, 0, 32, 18, Vector_MapPLN0); 
		set_sprite_data(46, 2, Delete_Sprites); 
	VBK_REG = 1;
		set_bkg_tiles( 0, 0, 32, 18, Vector_MapPLN1); 
		
	VBK_REG = 0;	  
	
	set_bkg_palette(0, 8, Vector_TilesPAL);
	set_sprite_palette( 0, 1, Boat_SPAL);//I didn't use the exported one, because it is in another bank and....
	
	SHOW_SPRITES;
	SHOW_BKG;

	GFX_Offset = 0;
	GFX_Offset2 = 640*6;
	Tile_Cnt = 0;
	SeaLine = 0;
	SeaTile = 0;
	SSPEED = 0;
	SSPEED1 = 144;
	SSPEED2 = 0;
	SSTATE = 0;
	SPRX = 246;
	SPRY = 6;
	Scene++;
	
}

void Boat_Run(){
	//UPDATE TILES (Water)
	if (TIMER < 730) DMA_TRANSFER(40,Vector_Anim_Water+GFX_Offset2,(UINT16*)0x9130);
	
	if ((TIMER > 20) && (TIMER < 57)) WY_REG+=4;
	if (TIMER == 730) {WY_REG = 144;SeaLine=0;SeaTile=0;}
	
	//Re set Window tiles line by line, so that the scanline palete function has time to work
	if ((TIMER > 730) && (TIMER < 767)) {
		if (SeaLine <10){
			VBK_REG = 0;
			set_win_tiles(0, SeaLine, 20, 1, Window_MapPLN0+SeaTile);
			VBK_REG = 1;
			set_win_tiles(0, SeaLine, 20, 1, Window_MapPLN1+SeaTile);
			VBK_REG = 0;
			SeaLine++;
			SeaTile+=20;
		}
		WY_REG-=4;	
	}
	
	if (TIMER == 110)for (v = 0; v<24;v++) set_sprite_prop(v, 0x80);

	if ((TIMER > 58) && (TIMER <120)){WY_REG--;SSPEED1--;SPRX+=2;}
	if ((TIMER > 120) && (TIMER <700)){
		WY_REG = SSPEED1+Wave_Y[SPRY];
		SPRX = 104+Wave_Y[SPRY];
	}
	if ((TIMER > 700) && (TIMER <730)){
		WY_REG = SSPEED1+Wave_Y[SPRY];
		SSPEED1+=2;
		SPRX+=2;
	}	
	
	
	//UPDATE SPRITES (BOAT)
	if (Tile_Cnt == 6) {
		SSTATE ++;
		VBK_REG = 1;	   
		if (SSTATE == 2) {for (v = 0; v<16;v++) set_sprite_prop(v, 0xA0);}
		if (SSTATE == 4) {for (v = 0; v<16;v++) set_sprite_prop(v, 0x80);SSTATE = 0;}
		VBK_REG = 0;
		Tile_Cnt = 0;
	}
	
	//Change window tiles line by line, so that the scanline palete function has time to work
	if ((TIMER > 58) && (TIMER < 68)){
		VBK_REG = 0;
		set_win_tiles(0, SeaLine, 20, 1, Vector_Map_WaterPLN0+SeaTile);
		VBK_REG = 1;
		set_win_tiles(0, SeaLine, 20, 1, Vector_Map_WaterPLN1+SeaTile);
		VBK_REG = 0;
		SeaLine++;
		SeaTile+=20;
	}
	
	//Draw BOAT Sprites alternate to simulate
	if ((SSTATE == 0)||(SSTATE == 1)){
		move_sprite(0,58+16,SPRX-32);move_sprite(1,58+24,SPRX-32);
		move_sprite(2,58+32,SPRX-32);move_sprite(3,58+40,SPRX-32);
		move_sprite(4,58+8,SPRX-16);move_sprite(5,58+16,SPRX-16);
		move_sprite(6,58+24,SPRX-16);move_sprite(7,58+32,SPRX-16);
		move_sprite(8,58+40,SPRX-16);move_sprite(9,58+48,SPRX-16);
		move_sprite(10,58+8,SPRX);move_sprite(11,58+16,SPRX);
		move_sprite(12,58+24,SPRX);move_sprite(13,58+32,SPRX);
		move_sprite(14,58+40,SPRX);move_sprite(15,58+48,SPRX);
	}else {
		move_sprite(3,58+16,SPRX-32);move_sprite(2,58+24,SPRX-32);
		move_sprite(1,58+32,SPRX-32);move_sprite(0,58+40,SPRX-32);
		move_sprite(9,58+8,SPRX-16);move_sprite(8,58+16,SPRX-16);
		move_sprite(7,58+24,SPRX-16);move_sprite(6,58+32,SPRX-16);
		move_sprite(5,58+40,SPRX-16);move_sprite(4,58+48,SPRX-16);
		move_sprite(15,58+8,SPRX);move_sprite(14,58+16,SPRX);
		move_sprite(13,58+24,SPRX);move_sprite(12,58+32,SPRX);
		move_sprite(11,58+40,SPRX);move_sprite(10,58+48,SPRX);
	}	
	
	if (SSPEED == 5){
		if (TIMER > 130) {
			Tile_Cnt++;
			if (SSTATE == 0) GFX_Offset+= 32*16;
			if (SSTATE == 1) GFX_Offset-= 32*16;
			if (SSTATE == 2) GFX_Offset+= 32*16;
			if (SSTATE == 3) GFX_Offset-= 32*16;
		}
		SSPEED = 0; 
		GFX_Offset2+= 640;
		SPRY++;}
	if (GFX_Offset2 == 640*16) GFX_Offset2 = 0;
	if (SPRY == 27) SPRY = 0;
	
	if (TIMER == 768){
		TIMER = 0;
		Scene++;
		for (v = 0;v<40;v++)move_sprite(v,200,200);
	}	

	SSPEED++;
	SSPEED2++;
	TIMER++;
}

void Boat_Run2(){	
	Set_Lines_Pal2(C3DDegrade);
}	