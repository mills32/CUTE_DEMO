; Example for setting background palettes:

	.globl		_Set_First_Palette_Col2
	.BCPS		= 0x68	; BG color palette specification
	.BCPD		= 0x69	; BG color palette data
	.STAT		= 0x41
	
_Set_First_Palette_Col2:		
	PUSH	BC
	PUSH	DE
	
	LDA	HL,7(SP)	; Skip return address and registers
	LD		B,(HL)		; BC = rgb_data
	DEC	HL
	LD		C,(HL)
	
	LD	A,#0
	LDH	(.BCPS),A
	LD	A,(BC)
	LDH	(.BCPD),A
	INC	BC		; next rgb_data
	LD	A,#1
	LDH	(.BCPS),A
	LD	A,(BC)
	LDH	(.BCPD),A


	POP	DE
	POP	BC
	RET
