#include <gb/gb.h>

extern const unsigned char Parallax_MapPLN0[];
extern const unsigned char Parallax_MapPLN1[];
   
extern UINT8 Map_PosX;    
extern UINT8 Scroll;      
extern UINT8 ScrollX;     
extern UINT16 Tile_Cnt; 
extern UINT8 SPR;
extern UINT8 Scene;
extern UINT8 Part;
extern UINT16 MAP_Y;

void DMA_TRANSFER(UINT8 tiles, UINT16 *source,UINT16 *destination); 

void CPU_TRANSFER_COLUMN(unsigned char column,UINT16 *source){
	__asm
	PUSH	BC

	LDA	HL,6(SP)		
	LD	D,(HL)	
	DEC	HL
	LD	E,(HL)		// DE = data source address
	DEC	HL
	LD	C,(HL)
	LD	B,#0
	LD	HL,#0x9800	
	
	ADD		HL,BC	// HL = data destination address
	
	LD		B,#0
	LD		C,#32
	
	LD		A,(DE)		//  Load source value into A
    LD		(HL),A		//  Store at destination
	INC		DE			//  Go to next value in map array
	ADD		HL,BC		//  HL+=32, go to next tile in a column
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A		
	INC		DE
	ADD		HL,BC
	
	LD		A,(DE)		
	LD		(HL),A

	POP	BC
	__endasm;
	source;column;
}

void Parallax_Map_Run(){

    if (Scroll == 1){ 
    	if (Tile_Cnt == 224*18) {Tile_Cnt = 0;} //
		
		//set_bkg_tiles
    	/*VBK_REG = 0;
    	CPU_TRANSFER_COLUMN(ScrollX&31,Parallax_MapPLN0+Tile_Cnt);
		VBK_REG = 1;
		CPU_TRANSFER_COLUMN(ScrollX&31,Parallax_MapPLN1+Tile_Cnt);
		*/
		VBK_REG = 0;
    	CPU_TRANSFER_COLUMN(ScrollX&31,Parallax_MapPLN0+Tile_Cnt);
		VBK_REG = 1;
		CPU_TRANSFER_COLUMN(ScrollX&31,Parallax_MapPLN1+Tile_Cnt);
		
    	Scroll = 0;
		ScrollX++;
		Tile_Cnt+=18;
    }
}
