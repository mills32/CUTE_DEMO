#include <gb/gb.h>

extern const unsigned char Vector_Sprites[];

extern UINT16 GFX_Offset;
extern UINT16 TIMER;

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); //in asm 

void Vectors_Run_Sprites(){
	//UPDATE SPRITES (BOAT)
	if (TIMER < 45) DMA_TRANSFER(48,&Vector_Sprites+GFX_Offset,0x8000);
	else DMA_TRANSFER(47,&Vector_Sprites+GFX_Offset,0x8000);
}
