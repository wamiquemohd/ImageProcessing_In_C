/**************************************************
*Code for Converting YUV420 image to RGB24
*Converted Image will  have Red,Green,Blue component in it.

Author: Wamique
Date:31st, May, 2020

****************************************************/



#include<stdio.h>
#include<stdint.h>
#include"Yuv420ToYuv444.h"
#include"Yuv444ToRgb.h"

/*size of Image*/
#define WIDTH 1280   
#define HEIGHT 720


int main(){
	
	
	uint8_t Yuv420Data[1382400]={0};
	uint8_t RGB[WIDTH*HEIGHT*3]={0};

	FILE *Input=fopen("YUV420image.yuv","rb+");          
	FILE *Output=fopen("RGBConvertedimage.yuv","wb+");
	
	/*Reading from Input file YUV422 at once in array YuvData */
	fread(&Yuv420Data,sizeof(char),1382400,Input);

	/**Processing Function**/ 	
	Yuv420ToYuv444(Yuv420Data,RGB,WIDTH,HEIGHT);
	Yuv444ToRgb(RGB,WIDTH,HEIGHT);

	/*Writing data in new file (converted to Y)*/
	fwrite(&RGB,sizeof(char),WIDTH*HEIGHT*3,Output);

	/*closing file*/
	fclose(Input); 
	fclose(Output);
	return 0;

}



