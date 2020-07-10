#include"Yuv420ToYuv444.h"
/*
This function converts the YUV420 image to Yuv444 format
Parameter:Yuv420Data->Input data of yuv420 image
	  Yuv444Data->output data as yuv444
	  width of image
	  height of image

Returns: Nothing
*/
void Yuv420ToYuv444(uint8_t Yuv420Data[],uint8_t Yuv444Data[],int width,int height){
	
	int i=0,k=0,j=0,l=0;

	/*pointer to process Y data*/
	uint8_t *Luma=Yuv420Data;

	/*pointer to process UV data*/
	uint8_t *Chroma=&Yuv420Data[width*height];

	/*Total no.of bytes in width of image (1280 pixels)*/
	int Yuv444width=width*3;

	/*In this loop we are fillng "Y" data from yuv420 Image to yuv444 Image buffer(leaving spaces for U-V)*/
	for(i=0;i<width*height*3;i=i+3)
	{
		Yuv444Data[i]=Luma[i/3];
		
	}
	/*In this loop we are fillng "U-V" data from yuv420 Image to yuv444 Image buffer
	 Here, i is used to traverse height of image , j is used to traverse width of image, 
	 l is used to traverse alternate couloumn of image
	 */
	for(i=0;i<height;i=i+2){
		for(j=1;j<width*3;j=j+6){
			for(l=i;l<(i+2);l++){
				Yuv444Data[(Yuv444width*l)+j]=Chroma[k];
				Yuv444Data[(Yuv444width*l)+j+1]=Chroma[k+1];
				Yuv444Data[(Yuv444width*l)+j+3]=Chroma[k];
				Yuv444Data[(Yuv444width*l)+j+4]=Chroma[k+1];
			}
			k=k+2;
		}


	}
}

