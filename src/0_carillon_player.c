#include <gb/gb.h>
//Carillon Player Vars
UINT8 CPBank = 0; 
UINT8 CPSong = 0;
UINT8 CP_ON;

//Carillon Player functions
void CP_Init(); 
void CP_LoadSong(); 
void CP_SelectSong(int song); 
void CP_UpdateSong(); 
void CP_StopSong(); 

void CP_LoadMusic(UINT8 bank, int song){
	CP_ON = 1;
	CPBank = bank;
	CPSong = song;
	SWITCH_ROM_MBC1(CPBank);
	CP_Init();
	CP_LoadSong();
	CP_SelectSong(song);
	SWITCH_ROM_MBC1(0);
}
void CP_UpdateMusic(){
	if (CP_ON == 1){
		SWITCH_ROM_MBC1(CPBank);
		CP_UpdateSong();
		SWITCH_ROM_MBC1(0);
	}
}
void CP_StopMusic(){
	if (CP_ON == 1){
		SWITCH_ROM_MBC1(CPBank);
		CP_StopSong();
		CPBank = 0;
		CP_ON = 0;
		SWITCH_ROM_MBC1(0);
	}
}