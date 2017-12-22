// BitMap to Y scanlines for GameBoy 3d Fake effects


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//COLORS FF CB 95 00
int main(int argc, char **argv) {
	int i;
	
	FILE *streamIn;
	FILE *fout;
	streamIn = fopen("bitmap.data", "rb");
	fout = fopen("palettes.c", "w");
	
	if (streamIn == (FILE *)0){
	printf("File opening error ocurred. Exiting program.\n");
	exit(0);
	}

	fseek(streamIn, 0, SEEK_END);
	int size = ftell(streamIn);
	rewind(streamIn);

	static int dataR[144];
	static int dataG[144];
	static int dataB[144];
	
	//CONVERT TO Y SCANLINES in output file
	int linelen = 0;
	int linenum = 0;
	int pos = 0;
	int count = 0;
	fprintf(fout,"//BITMAP to CGB Palette\n\n");
	fprintf(fout,"#include <gb/gb.h>\n\n\n");
	fprintf(fout,"const unsigned char palettes");
	fprintf(fout,"[] =\n");
	fprintf(fout,"{\n\t");
	
	//GET RGBDATA
	for(int i = 0; i < 144*3; i+=3) {
		pos++;
		dataR[pos-1] = fgetc(streamIn);
		dataG[pos-1] = fgetc(streamIn);
		dataB[pos-1] = fgetc(streamIn);
	}
	
	//CONVERT TO Palettes
	pos = 0;
	linelen = 0;
	int array_w = 0;

	int cgb_color;
	for(int i = 0; i < 144; i++) {
		cgb_color = (((dataR[i] >> 3) & 31) | (((dataG[i] >> 3) & 31) << 5) | (((dataB[i] >> 3) & 31) << 10));
		fprintf(fout,"%d, ",cgb_color);
		array_w++;
		if (array_w == 8){
			fprintf(fout,"\n\t");
			array_w = 0;
		}
	}
	
	fprintf(fout,"\n};");
	
	fclose(streamIn);
	fclose(fout);
	
	printf("filesize = %d ", size);
}

