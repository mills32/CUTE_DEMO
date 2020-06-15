#include <gb/gb.h>

extern const unsigned char Tower_Tiles[];
extern const unsigned char Tower_TilesPAL[];
extern const unsigned char tower_anim_tiles[];
extern const unsigned char tower_anim_bkg[];

extern const unsigned char tower_sprite[];
extern const unsigned char tower_sprite_ghost[];
extern const unsigned char tower_spritePAL[];
extern const unsigned char Tower_MapPLN0[];
extern const unsigned char Tower_MapPLN1[];
extern UINT16 TIMER;

extern UINT8 Scene;
extern UINT8 v;
extern UINT8 SPR;
extern UINT8 SPRX;
extern UINT8 SPRY;
extern UINT8 SSPEED;
extern UINT8 SSPEED1;
int TowerOffset;
UINT16 TowerOffset2;
UINT8 Tower_Align;
UINT16 BKGOffset;
UINT8 Fix[8] = {1,1,1,1,0,1,1,1};


void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

const UINT8 sprite_tower_rot[96] =
{
	72,72,72,72,72,72,72,72,72,72,
	72,72,72,72,72,71,71,71,70,70,
	69,68,68,67,66,65,64,63,62,61,
	59,58,57,55,54,53,51,50,48,47,
	45,44,42,41,39,37,36,34,33,31,
	29,27,25,23,22,20,18,17,15,14,
	12,11, 9, 8, 7, 6, 5, 4, 3, 3,
	 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	 0, 0, 0, 0, 0, 0 
};

const UINT8 bats_move[] =
{
	80, 84, 88, 92, 96,
100, 104, 108, 111, 115, 118, 121, 124, 127, 129,
131, 133, 135, 137, 138, 139, 139, 139, 139, 139,
139, 138, 137, 135, 133, 131, 129, 127, 124, 121,
118, 115, 111, 108, 104, 100, 96, 92, 88, 84,
79, 75, 71, 67, 63, 59, 55, 51, 48, 44,
41, 38, 35, 32, 30, 28, 26, 24, 22, 21,
20, 20, 20, 20, 20, 20, 21, 22, 24, 26,
28, 30, 32, 35, 38, 41, 44, 48, 51, 55,
59, 63, 67, 71, 75, 80
};

struct Rotating_Block{
	UINT8 sprite_number;
	UINT16 offset;
	UINT16 dat_offset;
	UINT8 rot_offset;
	UINT8 fix;
};

void Rot_Tower_Sprite(struct Rotating_Block* block, UINT8 posy){
  if(block->fix == 2){
	//VBK_REG = 0;
	set_sprite_data(block->sprite_number, 4, tower_sprite+block->dat_offset);
	move_sprite(block->sprite_number/2,48+sprite_tower_rot[block->rot_offset],posy);
	move_sprite((block->sprite_number/2) + 1,56+sprite_tower_rot[block->rot_offset],posy);
	
	if (Tower_Align == 0){
		if (block->rot_offset < 95) block->rot_offset++;
		if (block->dat_offset < 95*64) block->dat_offset+=64;
	}
	if (Tower_Align == 1){
		if (block->rot_offset == 95) block->rot_offset = 0;
		if (block->dat_offset == 95*64) block->dat_offset = 0;
	}
	block->fix = 0;
  }
  block->fix++;
}

struct Rotating_Block block1;
struct Rotating_Block block2;
struct Rotating_Block block3;
struct Rotating_Block block4;

void Tower_Set(){
	
	VBK_REG = 0;	  
		set_bkg_tiles( 0, 0, 20, 18, Tower_MapPLN0); //tiles
		DMA_TRANSFER(34, (UINT16*)Tower_Tiles,(UINT16*)0x9000);
		for (v = 0; v<34;v+=16)set_sprite_data( v, 16, tower_sprite_ghost);//in 8x8 mode!!!
	VBK_REG = 1;	   
		set_bkg_tiles( 0, 0, 20, 18, Tower_MapPLN1); //tiles
		for (v = 0; v<24;v++) set_sprite_prop(v, 0x01);
		for (v = 24; v<36;v++) set_sprite_prop(v, 0x00);

	VBK_REG = 0;	  
	
	set_bkg_palette(0, 8, Tower_TilesPAL); //tile bank 1
	set_sprite_palette( 0, 8, tower_spritePAL);
	
	SHOW_BKG;
	SHOW_SPRITES;

	BKGOffset = 0;
	TowerOffset = 0;
	TowerOffset2 = 1792;
	Tower_Align = 1;
	
	SSPEED = 0;
	SSPEED1 = 0;

	block1.sprite_number = 48; block1.offset = 0x8300; block1.rot_offset = 0; block1.dat_offset = 0;  block1.fix = 0;
	block2.sprite_number = 52; block2.offset = 0x8380; block2.rot_offset = 8; block2.dat_offset = 8*64; block2.fix = 0;
	block3.sprite_number = 56; block3.offset = 0x8400; block3.rot_offset = 32; block3.dat_offset = 32*64; block3.fix = 0;
	block4.sprite_number = 60; block4.offset = 0x8480; block4.rot_offset = 40; block4.dat_offset = 40*64; block4.fix = 0;
	
	Scene++;
	for(v = 28; v<37;v++)move_sprite(v,200,200);
}	


void Tower_Run(){
	int X;
	
	if ((TIMER > 12) && (TIMER < 49))WY_REG+=4;
	if ((TIMER > 720) && (TIMER <757))WY_REG-=4;
	
	
	if (Fix[SSPEED] == 1){
		VBK_REG = 0;
		DMA_TRANSFER(4,(UINT16*)(tower_anim_bkg+BKGOffset),(UINT16*)0x9000);//(change bkg tiles)
		DMA_TRANSFER(16,tower_anim_tiles+TowerOffset,(UINT16*)(0x9000+4*16));//(change bkg tiles)
		DMA_TRANSFER(16,tower_anim_tiles+TowerOffset2,(UINT16*)(0x9000+20*16));//(change bkg tiles)
	
		TowerOffset+=256;
		TowerOffset2+=256;
		BKGOffset+=64;
	}
	
	Rot_Tower_Sprite(&block1,32);
	Rot_Tower_Sprite(&block2,64);
	Rot_Tower_Sprite(&block3,96);	
	Rot_Tower_Sprite(&block4,128);	

	///END OF DMA TRANSFERS
	
	SSPEED++;
	if (SSPEED == 8) SSPEED = 0;
	
	if (TowerOffset == 3840) {TowerOffset = 0; Tower_Align = 1;}
	else Tower_Align = 0;
	
	if (TowerOffset2 == 3840) TowerOffset2 = 0;
	if (BKGOffset == 2048) BKGOffset = 0;
	
	if(SPRX == 90) SPRX = 0;
	
	X = bats_move[SPRX]/3;
	//BATS
	move_sprite(4,bats_move[SPRX]-16,SPRY+7);move_sprite(5,bats_move[SPRX]-8,SPRY+7);
	move_sprite(0,bats_move[SPRX],SPRY);move_sprite(1,bats_move[SPRX]+8,SPRY);
	move_sprite(2,bats_move[SPRX],SPRY+16);move_sprite(3,bats_move[SPRX]+8,SPRY+16);
	move_sprite(6,bats_move[SPRX]+16,SPRY+7);move_sprite(7,bats_move[SPRX]+24,SPRY+7);
	
	move_sprite(12,X-6,SPRY+87);move_sprite(13,X+2,SPRY+87);
	move_sprite(8,X+10,SPRY+80);move_sprite(9,X+18,SPRY+80);
	move_sprite(10,X+10,SPRY+96);move_sprite(11,X+18,SPRY+96);
	move_sprite(14,X+26,SPRY+87);move_sprite(15,X+34,SPRY+87);
	
	move_sprite(20,-bats_move[SPRX]+164,SPRY-113);move_sprite(21,-bats_move[SPRX]+172,SPRY-113);
	move_sprite(16,-bats_move[SPRX]+180,SPRY-120);move_sprite(17,-bats_move[SPRX]+188,SPRY-120);
	move_sprite(18,-bats_move[SPRX]+180,SPRY-104);move_sprite(19,-bats_move[SPRX]+188,SPRY-104);
	move_sprite(22,-bats_move[SPRX]+196,SPRY-113);move_sprite(23,-bats_move[SPRX]+204,SPRY-113);

	if (SSPEED1 == 2){SSPEED1 = 0;SPRY--;}
	
	SSPEED1++;
	SPRX++;

	TIMER++;
	
	if (TIMER == 768) {Scene++;TIMER = 0;}
}