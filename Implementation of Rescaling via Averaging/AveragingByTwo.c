#include<stdint.h>
#include"AveragingByTwo.h"
	/*Size of Output image*/	
#define SIZE_OF_OUTPUT_IMAGE_2 (WIDTH/2)*(HEIGHT/2)*3

	/*AveragingByTwo function here rescale the image by factor of two (Downsampled)*/
void AveragingByTwo(uint8_t *RGBBuff,int width,int height){

	/*Size of Output image*/
	uint8_t RGBScale[SIZE_OF_OUTPUT_IMAGE_2]={0};
	int k=0;
	FILE *Output=fopen("AveragingByTwo.yuv","wb+");
	
	
	/*here we pick 2 pixels out of 4 pixels and then calculating the average
	  Please refer attached ppt for brief description of this loop */

	for(int i=0;i<height;i=i+2){
	 for(int j=0;j<width*3;j=j+6){
		
		RGBScale[k]  =(RGBBuff[width*3*i+j] 
			      + RGBBuff[width*3*(i+1)+j+3])/2;

		RGBScale[k+1]=(RGBBuff[width*3*i+j+1] 
			      + RGBBuff[width*3*(i+1)+j+4])/2;

		RGBScale[k+2]=(RGBBuff[width*3*i+j+2]
			      +RGBBuff[width*3*(i+1)+j+5])/2;
		k=k+3;

		}
	}
	
	/*writing the Buffer data in Output file*/
fwrite(&RGBScale,sizeof(char),SIZE_OF_OUTPUT_IMAGE_2,Output);
fclose(Output);
}
