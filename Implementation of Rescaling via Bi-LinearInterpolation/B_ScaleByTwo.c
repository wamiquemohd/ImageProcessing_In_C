#include"B_ScaleByTwo.h"
	/*size of output Image*/	
#define SIZE_OF_OUTPUT_IMAGE_2 (WIDTH*2)*(HEIGHT*2)*3
	/*Output Buffer in created data section as local varible of this size is not possible*/
uint8_t RGBScale[SIZE_OF_OUTPUT_IMAGE_2]={0};

/* The B_ScaleByTwo function scales up the Input image by factor of two
   Parameter: RGBBuff-Buffer containg data of Input Image
   			  width- width of images
   			  height-height of images

   Returns: Nothing
*/

void B_ScaleByTwo(uint8_t *RGBBuff,int width,int height){

	int k=0,i=0,j=0;
	/*weight used in Bilinear Interpolation for middle element*/
	float wt=0.5;

	int InpImgWidthpx=width*3;
	int OutImgWidthpx=width*3*2;
	
	int InpImgHeight=height;
	int OutImgHeight=height*2; 

	FILE *Output=fopen("B_ScaleByTwo.yuv","wb+");
	
	/*Filling RGB Data alternatively in Output Buffer from Input Image buffer*/
	for(i=0;i<height;i=i+1){
		k=0;
	 for(j=0;j<InpImgWidthpx;j=j+3){
		
	 	RGBScale[OutImgWidthpx*(i<<1)+k]=RGBBuff[InpImgWidthpx*(i) + j];
	 	RGBScale[OutImgWidthpx*(i<<1)+k+1]=RGBBuff[InpImgWidthpx*(i) + j+1];
	 	RGBScale[OutImgWidthpx*(i<<1)+k+2]=RGBBuff[InpImgWidthpx*(i) + j+2];
	 	k=k+6;

		}
	}

	/*Interpolating vacant position in Rows of Output Buffer*/
	for(i=0;i<OutImgHeight;i=i+2){
		k=3;
	 for(j=0;j<OutImgWidthpx;j=j+6){

	 	/*Interpolated Red Pixel*/
	 	RGBScale[OutImgWidthpx*i+k]= (int)(RGBScale[OutImgWidthpx*i + j]*wt)
	 								 + (int)(RGBScale[OutImgWidthpx*i + j+6]*wt);

	 	/*Interpolated Green Pixel*/
	 	RGBScale[OutImgWidthpx*i+k+1]= (int)(RGBScale[OutImgWidthpx*i + j+1]*wt)
	 								 + (int)(RGBScale[OutImgWidthpx*i + j+1+6]*wt);

	 	/*Interpolated Blue Pixel*/
	 	RGBScale[OutImgWidthpx*i+k+2]= (int)(RGBScale[OutImgWidthpx*i + j]*wt)
	 								 + (int)(RGBScale[OutImgWidthpx*i + j+2+6]*wt);

	 	k=k+6;
	}
}

	/*Interpolating vacant position in Column of Output Buffer*/
	for(i=0;i<OutImgHeight-2;i=i+2){
		for(j=0;j<OutImgWidthpx;j=j+3){

		/*Interpolated Red Pixel*/
		RGBScale[OutImgWidthpx*(i+1)+j]=(int)(RGBScale[OutImgWidthpx*i+j]*wt) 
										+ (int)(RGBScale[OutImgWidthpx*(i+2)+j]*wt);

		/*Interpolated Green Pixel*/
		RGBScale[OutImgWidthpx*(i+1)+j+1]=(int)(RGBScale[OutImgWidthpx*i+j+1]*wt) 
	 									+ (int)(RGBScale[OutImgWidthpx*(i+2)+j+1]*wt);
	 	/*Interpolated Blue Pixel*/
		RGBScale[OutImgWidthpx*(i+1)+j+2]=(int)(RGBScale[OutImgWidthpx*i+j+2]*wt) 
										+ (int)(RGBScale[OutImgWidthpx*(i+2)+j+2]*wt);
	}
}

fwrite(&RGBScale,sizeof(char),SIZE_OF_OUTPUT_IMAGE_2,Output);
fclose(Output);
}
