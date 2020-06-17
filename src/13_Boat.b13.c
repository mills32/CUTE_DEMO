#include <gb/gb.h>

extern const unsigned char Vector_Sprites[];

extern UINT16 GFX_Offset;
extern UINT16 TIMER;

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); //in asm 

void Boat_Run_Sprites(){
	//UPDATE SPRITES (BOAT)
	DMA_TRANSFER(32,Vector_Sprites+GFX_Offset,(UINT16*)0x8000);
}
