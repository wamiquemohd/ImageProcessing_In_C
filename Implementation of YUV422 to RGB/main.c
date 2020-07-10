/**************************************************
*Code for Converting YUV422 image to Y
*Converted Image will only have Y component in it.

Author: Wamique
Date:31st, May, 2020

****************************************************/



#include<stdio.h>
#include<stdint.h>
#include "Yuv444ToRGB.h"
#include "Yuv422ConverterToYUV444.h"

#define WIDTH 1280   /*size of Image*/
#define HEIGHT 960

int main(){
	
	uint8_t YuvData[WIDTH*HEIGHT*2]={0};
	uint8_t RGBBuff[WIDTH*HEIGHT*3]={0};

	FILE *Input=fopen("YUV422image.yuv","rb+");          
	FILE *Output=fopen("RGBConvertedimage.yuv","wb+");

	/*Reading from Input file YUV422 at once in array YuvData */
	fread(&YuvData,sizeof(char),WIDTH*HEIGHT*2,Input);

	/**Processing Function**/ 	
	Yuv422ConverterToYUV444(YuvData,RGBBuff,WIDTH,HEIGHT);
	Yuv444ToRGB(RGBBuff,WIDTH,HEIGHT);

	/*Writing data in new file (converted to RGB)*/
	fwrite(&RGBBuff,sizeof(char),WIDTH*HEIGHT*3,Output);

	fclose(Input); /*closing file*/
	fclose(Output);
	return 0;

}



 
