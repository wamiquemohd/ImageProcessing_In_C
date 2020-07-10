/**************************************************
*Code for Sub-scaling image by "2" and "4"
*Input-Image(1280*960) is Downsampled by "2" to Output-Image(640*480)
*Input-Image(1280*960) is Downsampled by "4" to Output-Image(320*240)

Author: Wamique
Date:20, June, 2020

****************************************************/

#include"DownsampleByTwo.h"
#include"DownsampleByFour.h"

int main(){

	/*Input Buffer for reading Image of height 960px and width 1280px */
	uint8_t RGBBuff[WIDTH*HEIGHT*3]={0};
	
	FILE *Input=fopen("RGBImage1280_960.yuv","rb+");          
	
	/*Reading from Input file RGB image at once in array*/
	fread(&RGBBuff,sizeof(char),WIDTH*HEIGHT*3,Input);

	/**Processing Function**/ 
	
	/*Downsampling Image By two*/
	DownsampleByTwo(RGBBuff,WIDTH,HEIGHT);
	/*Downsampling Image By four*/
	DownsampleByFour(RGBBuff,WIDTH,HEIGHT);

	/************************/
	
	/*closing file*/
	fclose(Input);
	
	return 0;

}



 
