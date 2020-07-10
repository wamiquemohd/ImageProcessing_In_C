#include<stdint.h>
#include"AveragingByFour.h"
	/*Size of Output image*/	
#define SIZE_OF_OUTPUT_IMAGE_4 (WIDTH/4)*(HEIGHT/4)*3
	/*AveragingByFour function here rescale the image by factor of four (Downsampled)*/
void AveragingByFour(uint8_t *RGBBuff,int width,int height){

	/*Size of Output image*/
	uint8_t RGBScale[SIZE_OF_OUTPUT_IMAGE_4]={0};
	int k=0;
	FILE *Output=fopen("AveragingByFour.yuv","wb+");
	
	/*here we pick 4 pixels out of 16 pixels and then calculating the average
	  Please refer attached ppt for brief description of this loop */
	for(int i=0;i<height;i=i+4){
	 for(int j=0;j<width*3;j=j+12){
		
		RGBScale[k] = (RGBBuff[width*3*i+j] 
			      + RGBBuff[width*3*(i+1)+j+3]
			      + RGBBuff[width*3*(i+2)+j+6]
			      + RGBBuff[width*3*(i+3)+j+9])/4;

		RGBScale[k+1]= (RGBBuff[width*3*i+j+1] 
			      + RGBBuff[width*3*(i+1)+j+4]
			      + RGBBuff[width*3*(i+2)+j+7]
			      + RGBBuff[width*3*(i+3)+j+10])/4;

		RGBScale[k+2]= (RGBBuff[width*3*i+j+2]
			      + RGBBuff[width*3*(i+1)+j+5]
			      + RGBBuff[width*3*(i+2)+j+8]
			      + RGBBuff[width*3*(i+3)+j+11])/4;
		k=k+3;

		}
	}
	/*writing the Buffer data in Output file*/
fwrite(&RGBScale,sizeof(char),SIZE_OF_OUTPUT_IMAGE_4,Output);
fclose(Output);
}
