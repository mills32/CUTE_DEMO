#include <gb/gb.h>

extern const unsigned char Road3DAnim[];

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); //in asm 

extern UINT16 Map3D_Frame0; 
extern UINT8 SPR;
void Road3D_DMA(){
	//SIDE road
	DMA_TRANSFER(25,Road3DAnim+Map3D_Frame0,(UINT16*)0x9000);
}
