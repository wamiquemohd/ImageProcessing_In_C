/****************************************************
*Code for Converting YUV420 (Planer/NV12) To Y
*Converted Image "YImage.yuv" only have Y component.

Author: Mohd Wamique Husain
Date: 1st,june,2020

*****************************************************/


#include<stdio.h>
#include<stdint.h>
#include "Yuv420ToY.h"

/*size of a Image*/
#define WIDTH 1280
#define HEIGHT 720


int main()
{
	
	/*Buffer will hold Input image*/
	uint8_t LaaYuv420[WIDTH*HEIGHT*2]={0};
	/*Buffer will hold Output Image*/
	uint8_t LaaYData[WIDTH*HEIGHT]={0};

	FILE *LpInput=fopen("YUV420image.yuv","rb+");
	if(LpInput==NULL)
	{
		fprintf(stderr,"Can't open the file\n");
		return 1;
	}

	FILE *LpOutput=fopen("YImage.yuv","wb+");
	if(LpOutput==NULL)
	{
		fprintf(stderr,"Can't open the file\n");
		return 1;
	}
  /*reading data from input given (yuv420)*/
    fread(&LaaYuv420,sizeof(uint8_t),WIDTH*HEIGHT*2,LpInput);	
    
    Yuv420ToY(LaaYuv420,LaaYData,WIDTH,HEIGHT);

	/*writing data to new file (Y)*/
	fwrite(&LaaYData,sizeof(uint8_t),WIDTH*HEIGHT,LpOutput);

	fclose(LpInput);
	fclose(LpOutput);
	return 0;
}

