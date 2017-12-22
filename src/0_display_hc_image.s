;-----------------------------------------------------------------------------
; *** 160 x 144 hicolor library ***
; Compiled with GBDK v2.1.5

		.LCDC		= 0x40	; LCD control
        .STAT		= 0x41	; LCD status
		.LY		    = 0x44	; LCDC Y-coordinate
		.BCPD		= 0x69	; BG color palette data
		.BCPS		= 0x68	; BG color palette specification
		.VBK		= 0x4F	; VRAM bank
		.SCX		= 0x43	;
        .globl  .display_off
        .globl  .int_0x40
        .globl  .int_0x48

        .area   _BSS

.HDTimer:
		.ds		0x02
.StackStorage:
        .ds		0x60

.area   _CODE
;----------------------------------------------------------------------------;
; void DisplayHiClr (char BANK, char KEYMASK);

_LoadHiclr::
	PUSH 	BC
	PUSH 	DE
	PUSH 	HL
	LDA  	HL,8(sp)
	LD   	A,(HL+)
	LD   	B,(HL)
	call 	_LDHiclr
	POP  	HL
	POP  	DE
	POP  	BC
	RET

_LDHiclr:  

	LD    	(0x2000),A   	;Bank   

	call  	.display_off
  
	LDH   	A,(.LCDC)
	PUSH  	AF              ; Save LCDC settings

	PUSH  	BC              ; save KEYMASK

	XOR		A					; Switch to character bank 0
	LDH   	(.VBK),A

	LD    	DE,#0x8800      ; Address for BG characters
	LD    	BC,#16 * 256    ; Transfer 256 characters

	LD    	A,(0x4000)     ; Get address of where characters stored
	LD		l,A
	LD    	A,(0x4001)

	LD		H,A

	call  	_TransferCharData  ; Transfer characters

	LD    	A,#1         ; Switch to alternate character bank
	LDH   	(.VBK),A

	LD    	DE,#0x8800
	LD    	BC,#16 * 104    ; Transfer 104 characters

	call  	_TransferCharData
	
	LD    	HL,#0x9800      ; Screen Address (attributes)
	LD    	A,(0x4002)
	LD		C,A
	LD    	A,(0x4003)
	LD		B,A					; BC = Attribute memory

	call  	_WriteScreen     ; Transfer character attributesWriteScreen:
	
	XOR		A
	LDH   	(.VBK),A

	LD    	HL,#0x9800
	LD    	A,(0x4004)
	LD		C,A
	LD    	A,(0x4005)
	LD		B,A					; BC = Map memory

	call  	_WriteScreen

; *** Set all palettes black ***
	LD    	A,#0x80       ;
	LD    	(0xff00+.BCPS),A      ;setup palette write.

	LD    	B,#32*2
	XOR   	A
	
	_ClrPals:
	LDH   	(.BCPD),A
	DEC   	B
	JR    	NZ,_ClrPals

; *** Turn on screen ***
	LD    	A,#0x83     ; LCDCF_ON | LCDCF_OBJON | LCDCF_BGON | LCDCF_WIN9800
	LDH   	(.LCDC),A

	POP BC
	
; *** Display hicolor photo ***
	_draw_hcimage::
	DI
	LD    	(.StackStorage),sp      ;store SP.

	LD    	A,#1
	LDH   	(.VBK),A

	LD    	HL,#0x4006
	LD    	A,(HL+)
	LD    	h,(HL)
	LD    	L,A     			; HL = palette data addr
	LD    	SP,HL      			;

	LD    	A,#0x80       		;
	LD    	HL,#0xff00+.BCPS	;setup palette write.
	LD    	(HL),A        		;

	LD    	HL,#0xff00+.LY
	XOR		A
  
	_wait:
	CP    	(HL)
	JR		NZ,_wait

	_palloop:
	POP		DE            		;get 2 palette values.
	LD    	L,#.STAT           	;point HL to STAT.

	_waitstat2:
	BIT   	1,(HL)        ;wait for HBlank.
	JR		NZ,_waitstat2 		;

	LD    	L,#.BCPD

	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE
	LD    	(HL),E        ;
	LD    	(HL),D

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE            		
	LD    	(HL),E            
	LD    	(HL),D            

	POP		DE            	;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE
	LD    	(HL),E        ;
	LD    	(HL),D

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE
	LD    	(HL),E        ;
	LD    	(HL),D

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE
	LD    	(HL),E        ;
	LD    	(HL),D

	POP		DE            		;get 2 palette values.
	LD    	(HL),E            ;
	LD    	(HL),D            ;write 2 palette values.

	POP		DE
	LD    	(HL),E        ;
	LD    	(HL),D


	LDH   	A,(.LY)           ;
	CP    	#142         ;test for bottom of image.
	JR		NZ,_palloop			;
  
	LD    	HL,#.StackStorage
	LD   	 A,(HL+)           ;
	LD    	h,(HL)        ;restore SP.
	LD		l,A					;
	LD		sp,HL

	ei

  	LD		A,(#.HDTimer)
	INC		A
	CP    	#255
	LD		(#.HDTimer),A
	JR		NZ,_draw_hcimage ;IF A > 0 DRAW AGAIN
  
	;LOOP EXIT
	POP		AF
	LDH   	(.LCDC),A     ; Restore LCDC settings
	RET

; ********************************************************
; Transfers CharData to VRAM
; Load DE with the VRAM address
; Load HL with address of the char data
; Load BC with the bytes to transfer
; ********************************************************


_TransferCharData:
	PUSH	AF


_CharLoop:

	LD    	A,(HL+)            ; Load char data
	LD    	(DE), A
	INC		DE                 ; increment memory location
	DEC		BC                 ; DEcrement counter
	LD		A, B               ; transfer upper byte of counter to a
	OR		C                  ; or with c. Check to see if both are zero
	JR    	NZ,_CharLoop       ; If not zero repeat

	POP  	AF
	
	RET


_WriteScreen:
	LD    	A,#18
  

_yloop:
	LD    	E,#20
	PUSH	AF

_xloop:
	LD    	A,(BC)
	INC		BC
	LD    	(HL+),A
	DEC		E
	JR    	NZ,_xloop

	LD    	DE,#12
	ADD		HL,DE
	POP		AF
	DEC		A
	JR    	NZ,_yloop
  
	RET
