#include <gb/gb.h>

extern const unsigned char Road3DAnim[];

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); //in asm 

extern UINT16 Map3D_Frame; 

void Road3D_DMA(){
	DMA_TRANSFER(30,&Road3DAnim+Map3D_Frame,0x9000);
}
