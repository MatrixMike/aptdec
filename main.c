/*
 *  Atpdec
 *  Copyright (c) 2004-2005 by Thierry Leconte (F4DWV)
 *
 *      $Id$
 *
 *   This library is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Library General Public License for more details.
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#ifdef WIN32
#include "w32util.h"
#else
#include <libgen.h>
#endif

#include <sndfile.h>
#include <png.h>

#include "version.h"
#include "offsets.h"

#include "temppalette.h"
#include "gvipalette.h"

extern int getpixelrow(float *pixelv);
extern int init_dsp(void);;



static png_text text_ptr[] = {
    {PNG_TEXT_COMPRESSION_NONE, "Software", version, sizeof(version)}
    ,
    {PNG_TEXT_COMPRESSION_NONE, "Channel", NULL, 0}
    ,
    {PNG_TEXT_COMPRESSION_NONE, "Description", "NOAA POES satellite Image",
     25}
};

static int
ImageOut(char *filename, char *chid, float **prow, int nrow, 
	 int width, int offset, png_color *palette)
{
    FILE *pngfile;
    png_infop info_ptr;
    png_structp png_ptr;
    int n;

/* init png lib */
    png_ptr =
	png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
	fprintf(stderr, "could not open create png_ptr\n");
	return (1);
    }

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
	png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
	fprintf(stderr, "could not open create info_ptr\n");
	return (1);
    }

    if(palette==NULL)  {
	/* grey image */
    	png_set_IHDR(png_ptr, info_ptr, width, nrow,
		 8, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
		 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    } else {
	/* palette color mage */
    	png_set_IHDR(png_ptr, info_ptr, width, nrow,
		 8, PNG_COLOR_TYPE_PALETTE, PNG_INTERLACE_NONE,
		 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_set_PLTE(png_ptr, info_ptr, palette, 256);
    }

    text_ptr[1].text = chid;
    text_ptr[1].text_length = strlen(chid);
    png_set_text(png_ptr, info_ptr, text_ptr, 3);
    png_set_pHYs(png_ptr, info_ptr, 4000, 4000, PNG_RESOLUTION_METER);

    printf("Writing %s ... ", filename);
    fflush(stdout);
    pngfile = fopen(filename, "wb");
    if (pngfile == NULL) {
	fprintf(stderr, "could not open %s\n", filename);
	return (1);
    }
    png_init_io(png_ptr, pngfile);
    png_write_info(png_ptr, info_ptr);

    for (n = 0; n < nrow; n++) {
	float *pixelv;
	png_byte pixel[2*IMG_WIDTH];
	int i;

	pixelv = prow[n];
	for (i = 0; i < width; i++) {
	    pixel[i] = pixelv[i + offset];
	}
	png_write_row(png_ptr, pixel);
    }
    png_write_end(png_ptr, info_ptr);
    fclose(pngfile);
    printf("Done\n");
    png_destroy_write_struct(&png_ptr, &info_ptr);
    return (0);
}

static int ImageRGBOut(char *filename, float **prow, int nrow)
{
    FILE *pngfile;
    png_infop info_ptr;
    png_structp png_ptr;
    int n;

    extern void falsecolor(double v, double t, float *r, float *g,
			    float *b);

/* init png lib */
    png_ptr =
	png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
	fprintf(stderr, "could not open create png_ptr\n");
	return (1);
    }

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
	png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
	fprintf(stderr, "could not open create info_ptr\n");
	return (1);
    }

    png_set_IHDR(png_ptr, info_ptr, CH_WIDTH , nrow ,
		 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
		 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_set_pHYs(png_ptr, info_ptr, 4000, 4000, PNG_RESOLUTION_METER);

    text_ptr[1].text = "False Colors";
    text_ptr[1].text_length = strlen(text_ptr[1].text);
    png_set_text(png_ptr, info_ptr, text_ptr, 3);

    printf("Computing False colors & writing : %s ...", filename);
    fflush(stdout);
    pngfile = fopen(filename, "wb");
    if (pngfile == NULL) {
	fprintf(stderr, "could not open %s\n", filename);
	return (1);
    }
    png_init_io(png_ptr, pngfile);
    png_write_info(png_ptr, info_ptr);

    for (n = 0; n < nrow ; n++) {
	png_color pix[CH_WIDTH];
    	float *pixelc;
	int i;

	pixelc = prow[n];

	for (i = 0; i < CH_WIDTH - 1; i++) {
	    float v, t;
  	    float r, g, b;

	    v = pixelc[i+CHA_OFFSET];
	    t = pixelc[i+CHB_OFFSET];

	    falsecolor(v, t, &r, &g, &b);

	    pix[i].red = 255.0 * r; 
	    pix[i].green = 255.0 * g;
	    pix[i].blue = 255.0 * b;
	}
	png_write_row(png_ptr, (png_bytep) pix);
    }
    png_write_end(png_ptr, info_ptr);
    fclose(pngfile);
    printf("Done\n");
    png_destroy_write_struct(&png_ptr, &info_ptr);
    return (0);
}


static void Distrib(char *filename,float **prow,int nrow)
{
unsigned int distrib[256][256];
int n;
int x,y;
int max=0;
FILE *df;

for(y=0;y<256;y++)
	for(x=0;x<256;x++)
                distrib[y][x]=0;

for(n=0;n<nrow;n++) {
        float *pixelv;
        int     i;

        pixelv=prow[n];
        for(i=0;i<CH_WIDTH;i++) {

                y=(int)(pixelv[i+CHA_OFFSET]);
                x=(int)(pixelv[i+CHB_OFFSET]);
                distrib[y][x]+=1;
		if(distrib[y][x]> max) max=distrib[y][x];
        }
}
df=fopen(filename,"w");

printf("Writing %s\n",filename);

fprintf(df,"P2\n#max %d\n",max);
fprintf(df,"256 256\n255\n");
for(y=0;y<256;y++)
	for(x=0;x<256;x++)
		fprintf(df,"%d\n",(int)((255.0*(double)(distrib[y][x]))/(double)max));
fclose(df);
}


extern int Calibrate(float **prow, int nrow, int offset);
extern void Temperature(float **prow, int nrow, int ch, int offset);
extern int Ngvi(float **prow, int nrow);
extern void readfconf(char *file);
extern int optind, opterr;
extern char *optarg;
int satnum = 4;
int nch=0;

static void usage(void)
{
    fprintf(stderr, version);
    fprintf(stderr, "atpdec [options]\n");
    fprintf(stderr,
	    "options:\n-d <dir>\tDestination directory\n-i [r|a|b|c|t]\tOutput image type\n\t\t\tr: Raw\n\t\t\ta: A chan.\n\t\t\tb: B chan.\n\t\t\tc: False color\n\t\t\tt: Temperature\n-c <file>\tFalse color config file\n-s [15|16|17|18|19]\tSatellite number (for temperature and false color generation)\n");
   exit(1);
}

int main(int argc, char **argv)
{
    char pngfilename[1024];
    char name[1024];
    char pngdirname[1024] = "";

    char imgopt[20] = "ac";
    float *prow[3000];
    char *chid[] = { "?", "1", "2", "3A", "4", "5", "3B" };
    int nrow;
    int chA,chB;
    int c;

    opterr = 0;
    while ((c = getopt(argc, argv, "a:f:c:d:i:s:LR")) != EOF) {
	switch (c) {
	case 'd':
	    strcpy(pngdirname, optarg);
	    break;
	case 'c':
	    readfconf(optarg);
	    break;
	case 'i':
	    strcpy(imgopt, optarg);
	    break;
	case 's':
	    satnum = atoi(optarg)-15;
	    if (satnum < 0 || satnum > 4) {
		fprintf(stderr, "invalid satellite number  : must be in [15-19]\n");
		exit(1);
	    }
	    break;
	case 'f':
		strcpy(name, basename(optarg));
		strtok(name, ".");
		if(initsnd(optarg))
		  exit(1);
	    break;
	case 'a':
		strcpy(name,"audioin");
		if(initalsa(optarg))
		  exit(1);
	    break;
	case 'L':
		nch=0;
	    break;
	case 'R':
		nch=0;
	    break;
	default:
	    usage();
	}
    }

        for (nrow = 0; nrow < 3000; nrow++)
	prow[nrow] = NULL;

	chA=chB=0;

	if (pngdirname[0] == '\0') {
		strcpy(pngdirname,".");
	}


/* init dsp */
    if(init_dsp())
	exit(2);

/* main loop */
	printf("Decoding: %s \n", name);
	for (nrow = 0; nrow < 3000; nrow++) {
	    if (prow[nrow] == NULL)
		prow[nrow] = (float *) malloc(sizeof(float) * 2150);
	    if (getpixelrow(prow[nrow]) == 0)
		break;
	    printf("%d\r", nrow);
	    fflush(stdout);
	}
	printf("\nDone\n");
	endsample();


/* raw image */
	if (strchr(imgopt, (int) 'r') != NULL) {
	    sprintf(pngfilename, "%s/%s-r.png", pngdirname, name);
	    ImageOut(pngfilename, "raw", prow, nrow, IMG_WIDTH, 0,NULL);
	}

/* Channel A */
	if (((strchr(imgopt, (int) 'a') != NULL)
	     || (strchr(imgopt, (int) 'c') != NULL)
	     || (strchr(imgopt, (int) 'd') != NULL))) {
	    chA = Calibrate(prow, nrow, CHA_OFFSET);
	    if (chA >= 0) {
		if (strchr(imgopt, (int) 'a') != NULL) {
		    sprintf(pngfilename, "%s/%s-%s.png", pngdirname, name, chid[chA]);
		    ImageOut(pngfilename, chid[chA], prow, nrow, CH_WIDTH , CHA_OFFSET,NULL);
		}
	    }
	}

/* Channel B */
	if ((strchr(imgopt, (int) 'b') != NULL)
	    || (strchr(imgopt, (int) 'c') != NULL)
	    || (strchr(imgopt, (int) 't') != NULL)
	    || (strchr(imgopt, (int) 'd') != NULL)) {
	    chB = Calibrate(prow, nrow, CHB_OFFSET);
	    if (chB >= 0) {
		if (strchr(imgopt, (int) 'b') != NULL) {
		    sprintf(pngfilename, "%s/%s-%s.png", pngdirname, name, chid[chB]);
		    ImageOut(pngfilename, chid[chB], prow, nrow, CH_WIDTH , CHB_OFFSET ,NULL);
		}
	    }
	    if (chB > 3) {
		Temperature(prow, nrow, chB, CHB_OFFSET);
		if (strchr(imgopt, (int) 't') != NULL) {
		    sprintf(pngfilename, "%s/%s-t.png", pngdirname, name);
		    ImageOut(pngfilename, "Temperature", prow, nrow, CH_WIDTH, CHB_OFFSET, (png_color*)TempPalette);
		}
	    }
	}

/* distribution */
	if (chA && chB && strchr(imgopt, (int) 'd') != NULL) {
	    sprintf(pngfilename, "%s/%s-d.pnm", pngdirname, name);
	    Distrib(pngfilename, prow, nrow);
	}

/* color image */
	if (chA==2 && chB==4 && strchr(imgopt, (int) 'c') != NULL) {
	    sprintf(pngfilename, "%s/%s-c.png", pngdirname, name);
	    ImageRGBOut(pngfilename, prow, nrow);
	}

/* GVI image */
	if (chA==1 && chB==2 && strchr(imgopt, (int) 'c') != NULL) {
	    Ngvi(prow, nrow);
	    sprintf(pngfilename, "%s/%s-c.png", pngdirname, name);
	   ImageOut(pngfilename, "GVI", prow, nrow, CH_WIDTH, CHB_OFFSET, (png_color*)GviPalette);
	}


    exit(0);
}
