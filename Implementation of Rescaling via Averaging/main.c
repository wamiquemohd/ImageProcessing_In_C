/**************************************************
*Code for rescaling image using Averaging method
Author: Wamique
Date:21st, June, 2020

****************************************************/



#include<stdio.h>
#include<stdint.h>
#include"AveragingByTwo.h"
#include"AveragingByFour.h"

 /*size of Image*/
#define WIDTH 1280  
#define HEIGHT 960

int main(){
	
	uint8_t RGBBuff[WIDTH*HEIGHT*3]={0};

	FILE *Input=fopen("RGBImage1280_960.yuv","rb+");          
	
	/*Reading from Input file YUV422 at once in array YuvData */
	fread(&RGBBuff,sizeof(char),WIDTH*HEIGHT*3,Input);

	/**Processing Function**/ 	
	AveragingByTwo(RGBBuff,WIDTH,HEIGHT);
	AveragingByFour(RGBBuff,WIDTH,HEIGHT);
	
	/*closing file*/
	fclose(Input); 
	
	return 0;

}



 
