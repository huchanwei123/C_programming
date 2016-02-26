/*ee231002 lab13.Image Processing
	102061247, chan-wei hu
	Date: 5/26
*/

#include <stdio.h>					//header for I/O library
#include <stdlib.h>

typedef struct sPIXEL{				//a single pixel
	unsigned char r, g, b;			//three color components
}PIXEL;

typedef struct sIMG{				
	char header[3];
	int W, H;						//the width and height of the image
	int level;						//intensity of each color component
	PIXEL **PX;					
} IMG;

IMG *PPMin(char *fname);			//function declaration
void PPMout(IMG *pic, char *fname);

int main(int argc, char *argv[]){
	IMG *pic, *eelogo, *nthu;		//variable declaration
	int logo_row, logo_col;
	int i, j;

	pic=PPMin(argv[1]);				//read in the picture
	eelogo=PPMin(argv[2]);			//read in the logo
	nthu=PPMin(argv[3]);			//read in the NTHU logo

	for(j=0; j<pic->H; j++){		//the loop used to convert the image to a blue-to-while image
        for(i=0; i<pic->W; i++){
			pic->PX[i][j].r=pic->PX[i][j].r*0.2126+pic->PX[i][j].g*0.7152+pic->PX[i][j].b*0.0722;
			pic->PX[i][j].g=pic->PX[i][j].r*0.2126+pic->PX[i][j].g*0.7152+pic->PX[i][j].b*0.0722;
            pic->PX[i][j].b=255;
        }
    }

    logo_col=pic->H-eelogo->H;		
    for(j=0; j<eelogo->H; j++){		//put the eelogo into the image
        logo_row=pic->W-eelogo->W;
        for(i=0; i<eelogo->W; i++){
            if (eelogo->PX[i][j].r!=255 && eelogo->PX[i][j].g!=255 && eelogo->PX[i][j].b!=255){
                pic->PX[logo_row][logo_col].r=eelogo->PX[i][j].r;
                pic->PX[logo_row][logo_col].g=eelogo->PX[i][j].g;
                pic->PX[logo_row][logo_col].b=eelogo->PX[i][j].b;
            }
            logo_row++;
        }
        logo_col++;
    }

    logo_col=pic->H/2-nthu->H/2 ;
    for(j=0; j<nthu->H; j++){		//put the NTHU logo in the middle of the image
        logo_row=pic->W/2-nthu->W/2;
        for(i=0; i<nthu->W; i++){
            if (nthu->PX[i][j].r!=255 && nthu->PX[i][j].g!=255 && nthu->PX[i][j].b!=255)
                pic->PX[logo_row][logo_col].r=255;
            logo_row++;
        }
        logo_col++;
    }
	PPMout(pic, argv[4]);			//print out the image
	return 0;
}

IMG *PPMin(char *fname){
	int i, j;						//variable declaration
	IMG *pic;
	FILE *fin;
	pic=(IMG*)malloc(sizeof(IMG));
	fin=fopen(fname, "r");			//file read
	fscanf(fin, "%s", pic->header);	//scan the header
	fscanf(fin, "%d %d\n%d\n", &pic->W, &pic->H, &pic->level);
									//scan the width, height and the intensity level of the color component
	pic->PX=(PIXEL**)malloc(pic->W*sizeof(PIXEL*));
	for(i=0; i<pic->W; i++){
		pic->PX[i]=(PIXEL*)malloc(pic->H*sizeof(PIXEL*));
	}
	for(j=0; j<pic->H; j++){
		for(i=0; i<pic->W; i++){
			pic->PX[i][j].r=fgetc(fin);
			pic->PX[i][j].g=fgetc(fin);
			pic->PX[i][j].b=fgetc(fin);
		}
	}
	fclose(fin);

	return pic;
}

void PPMout(IMG *pic, char *fname){
	int i, j;						//variable declaration
	FILE *fout;

	fout=fopen(fname, "w");			//file write
	fprintf(fout, "%s\n%d %d\n%d\n", pic->header, pic->W, pic->H, pic->level);
									//print out
	for(j=0; j<pic->H; j++){
		for(i=0; i<pic->W; i++){
			fprintf(fout, "%c%c%c", pic->PX[i][j].r, pic->PX[i][j].g, pic->PX[i][j].b);
									//print out
		}
	}
	fclose(fout);
	return;
}
