#include"DownsampleByTwo.h"	

void DownsampleByTwo(uint8_t *RGBBuff,int width,int height){

	/*RGBScale is output buffer for storing Downsampled Image of size (640*480)*/
	uint8_t RGBScale[SIZE_OF_OUTPUT_IMAGE_2]={0};

	FILE *Output=fopen("RGBscaledByTwo_640_480.yuv","wb+");
	
	int k=0;
	for(int i=0;i<height;i=i+2){
	 for(int j=0;j<width*3;j=j+6){
		
		/*Here we are picking one pixel information out of two pixel(Both vertically and horizontally) at time
		  from the Input image and storing that information in RGBscale buffer(Output) in sequence*/

		/*Red Pixel*/
		RGBScale[k]=RGBBuff[width*3*i+j];
		/*Blue Pixel*/
		RGBScale[k+1]=RGBBuff[width*3*i+j+1];
		/*Green Pixel*/		
		RGBScale[k+2]=RGBBuff[width*3*i+j+2];
		k=k+3;

		}
	}
	/*Writing data back in output image*/
	fwrite(&RGBScale,sizeof(char),SIZE_OF_OUTPUT_IMAGE_2,Output);
	fclose(Output);
}
