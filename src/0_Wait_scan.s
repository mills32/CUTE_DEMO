;--------------------------------------
; SET BKG DATA for fake 3D
; 
;--------------------------------------

	.globl	_WAIT_SCANLINE1
	.globl	_WAIT_SCANLINE2

	.STAT	= 0x41

.area	_CODE
	
_WAIT_SCANLINE1:

	.waitSCAN1:
    LDH		A,(.STAT)		 
    AND		#0x01       	 
    JR		NZ,.waitSCAN1   	; Wait for stat to be drawing a line to make calculations
    
	RET	
	
_WAIT_SCANLINE2:

	.waitSCAN2:
    LDH		A,(.STAT)		 
    AND		#0x02       	 
    JR		NZ,.waitSCAN2   	; Wait for stat mode to finish drawing a line and access VRAM.
    
	RET 
	
