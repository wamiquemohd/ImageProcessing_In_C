/**************************************************
*Code for rescaling Image using Bilinear Interpolation
*Here Upsampling is done using Bilinear Interpolation

Author: Wamique
Date:25th, June, 2020

****************************************************/



#include<stdio.h>
#include<stdint.h>

#include"B_ScaleByTwo.h"
#include"B_ScaleByFour.h"

/*size of Image*/
#define WIDTH 1280   
#define HEIGHT 960

int main(){
	
	/*Size of Input image*/
	uint8_t RGBBuff[WIDTH*HEIGHT*3]={0};
	
	FILE *Input=fopen("RGB_1280_960.yuv","rb+");          

	/*Reading from Input file YUV422 at once in array YuvData */
	fread(&RGBBuff,sizeof(char),WIDTH*HEIGHT*3,Input);

	/**Processing Function**/ 	
	
	/*Bilinear Interpolation done By factor 2 (Upsampled)*/
	B_ScaleByTwo(RGBBuff,WIDTH,HEIGHT);

	/*Bilinear Interpolation done By factor 4 (Upsampled)*/
	B_ScaleByFour(RGBBuff,WIDTH,HEIGHT);

	/*closing file*/
	fclose(Input); 
	return 0;

}



 
