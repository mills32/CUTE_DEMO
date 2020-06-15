;---------------------------------------------------------------------------
; CARILLON PLAYER Header file for GBDK
; (c)2000-2001 Aleksi Eeben (email: aleksi@cncd.fi)
; Ported to GBDK by nitro2k01 (http://gbdev.gg8.se/forums/)
;---------------------------------------------------------------------------
        
		.globl	_CP_Init
		.globl	_CP_LoadSong
		.globl	_CP_SelectSong
		.globl	_CP_UpdateSong
		.globl	_CP_StopSong
		
		.globl	_w_vbl ;fix bug
		
.area	_CODE
	
.Player_Initialize		=	0x4000
.Player_MusicStart		=	0x4003
.Player_MusicStop		=	0x4006
.Player_SongSelect		=	0x400c
.Player_MusicUpdate		=	0x4100

_CP_Init:
		jp		.Player_Initialize		; Initialize
		ret
		
_CP_LoadSong:
		
		push	BC
		call	.Player_MusicStart		; Start music playing
		pop		BC
		ret		

_CP_SelectSong:	
		LDA		HL,2(SP)				; Skip return address
		LD		A,(HL)					; Call SongSelect AFTER MusicStart!
		call	.Player_SongSelect		; (Not needed if SongNumber = 0)
		ret

_CP_UpdateSong:
        jp		.Player_MusicUpdate		; Call this once a frame

		
_CP_StopSong:
        jp		.Player_MusicStop		; Stops music


_w_vbl:
    LDH     A, (#0x44)
    CP      #145
    JR      NZ, _w_vbl
	RET
	
.area	_Playervars (ABS)
		.org	0xc7c0
		.ds		0x30