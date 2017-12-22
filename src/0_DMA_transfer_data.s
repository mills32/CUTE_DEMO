;-----------------------------------------
; SET BKG DATA for a lot of fake effects
; 
;-----------------------------------------

	.globl	_DMA_TRANSFER

	.STAT	= 0x41

    .HDMA1 = 0x51    ; DMA source high byte
    .HDMA2 = 0x52    ; DMA source low byte
    .HDMA3 = 0x53    ; DMA destination high byte
    .HDMA4 = 0x54    ; DMA destination low byte
    .HDMA5 = 0x55    ; DMA length/mode/start
		
.area	_CODE
	
_DMA_TRANSFER:
	PUSH	BC
	LDA		HL,9(SP)		; 
	DEC		HL
	LD		B,(HL)			; BC = data destination address
	DEC		HL
	LD		C,(HL)
	
	LD		A,B
	LDH		(.HDMA3),A      ; Load upper byte into destination register
	LD		A,C
	LDH		(.HDMA4),A      ; Load lower byte into destination register

	DEC		HL
	LD		B,(HL)			; BC = data source address
	DEC		HL
	LD		C,(HL)
	
	LD		A,B	
    LDH		(.HDMA1),A		; Load upper byte into source register
	LD		A,C
	LDH		(.HDMA2),A    	; Load lower byte into source register
    
	DEC		HL				; Get number of tiles from parameter
    LD		A,(HL)			
    DEC		A
	LD		C,A
	
	.waitDMA:
    LDH		A,(.STAT)		 
    AND		#0x02       	 
    JR		NZ,.waitDMA    	; Wait for stat mode to access VRAM.
	
	LD		A,C				; Specify length, in terms of chunks of 16 bytes, minus 1.
	LDH		(.HDMA5),A      ; Start transfer
	
	POP		BC
    
	RET 
	