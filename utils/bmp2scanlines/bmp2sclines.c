

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
	streamIn = fopen("bitmap_VRAM.data", "rb");
	fout = fopen("map3d_scanlines.c", "w");
	
	if (streamIn == (FILE *)0){
	printf("File opening error ocurred. Exiting program.\n");
	exit(0);
	}

	fseek(streamIn, 0, SEEK_END);
	int size = ftell(streamIn);
	rewind(streamIn);

	static int data[10000000];
	
	//CONVERT TO Y SCANLINES in output file
	int linelen = 0;
	int linenum = 0;
	int pos = 0;
	int count = 0;
	fprintf(fout,"//BITMAP to Y SCANLINES\n\n");
	fprintf(fout,"#include <gb/gb.h>\n\n\n");
	fprintf(fout,"const unsigned char map3d_scanlines");
	fprintf(fout,"[] =\n");
	fprintf(fout,"{\n\t");
	
	//GET R DATA
	for(int i = 0; i < size; i+=3) {
		pos++;
		data[pos-1] = fgetc(streamIn);
		fgetc(streamIn);
		fgetc(streamIn);
	}
	
	//CONVERT TO SCANLINES
	pos = 0;
	linelen = 0;
	int array_w = 0;
	
	
	for(int i = 0; i < size; i++) {
		pos++;
		linelen++; //position in line
		if (data[pos-1] == 0xFF){ //White quad
			fprintf(fout,"%d, ",linelen-1); 
			array_w++;
			pos = pos + (159-(linelen-1));
			linelen = 0;
			count++;
		}
		if (data[pos-1] == 0xA0){ //Up border 1
			fprintf(fout,"%d, ",(linelen-1)+32);
			array_w++;
			pos = pos + (159-(linelen-1));
			linelen = 0;
			count++;
		}
		if (data[pos-1] == 0xA1){ //Down border 1
			fprintf(fout,"%d, ",(linelen-1)+64);
			array_w++;
			pos = pos + (159-(linelen-1));
			linelen = 0;
			count++;
		}
		
		if (data[pos-1] == 0xC0){ //Grey quad
			fprintf(fout,"%d, ",(linelen-1)+96);
			array_w++;
			pos = pos + (159-(linelen-1));
			linelen = 0;
			count++;
		}
		if (data[pos-1] == 0xB0){ //Up border 2
			fprintf(fout,"%d, ",(linelen-1)+128);
			array_w++;
			pos = pos + (159-(linelen-1));
			linelen = 0;
			count++;
		}
		if (data[pos-1] == 0xB1){ //Down border 2
			fprintf(fout,"%d, ",(linelen-1)+160);
			array_w++;
			pos = pos + (159-(linelen-1));
			linelen = 0;
			count++;
		}		
		/*
		if (linelen == 160){//black
			linelen = 0;
			fprintf(fout,"%d, ",40);
			array_w++;
			count++;
		}*/
		// break after every 10th number 
		if(array_w == 10) {
			array_w = 0;
			fprintf(fout,"\n\t");
		}
		if (count == size/3/160) break;
	}
	
	
	fprintf(fout,"\n};");
	
	fclose(streamIn);
	fclose(fout);
	
	printf("filesize = %d ", size);
}