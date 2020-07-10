
#include"B_ScaleByFour.h"

	/*size of output Image*/
#define SIZE_OF_OUTPUT_IMAGE_4 (WIDTH*4)*(HEIGHT*4)*3

/*Output Buffer in created data section as local varible of this size is not possible*/
uint8_t RGBScaleF[SIZE_OF_OUTPUT_IMAGE_4]={0};

/* The B_ScaleByfour function scales up the Input image by factor of four
   Parameter: RGBBuff-Buffer containg data of Input Image
   			  width- width of images
   			  height-height of images

   Returns: Nothing
*/
void B_ScaleByFour(uint8_t *RGBBuff,int width,int height){

	int k=0,i=0,j=0,l=0;
	/*weight used in Bilinear Interpolation for elements as per there distance*/
	float wt[3]={0.25,0.50,0.75};

	int InpImgWidthpx=width*3;
	int OutImgWidthpx=width*3*4;
	
	int InpImgHeight=height;
	int OutImgHeight=height*4; 

	FILE *Output=fopen("B_ScaleByFour.yuv","wb+");
	
	/*Filling RGB Data alternatively in Output Buffer from Input Image buffer*/
	for(i=0;i<height;i=i+1){
		k=0;
	 for(j=0;j<InpImgWidthpx;j=j+3){
		
	 	RGBScaleF[OutImgWidthpx*(i<<2)+k]=RGBBuff[InpImgWidthpx*(i) + j];
	 	RGBScaleF[OutImgWidthpx*(i<<2)+k+1]=RGBBuff[InpImgWidthpx*(i) + j+1];
	 	RGBScaleF[OutImgWidthpx*(i<<2)+k+2]=RGBBuff[InpImgWidthpx*(i) + j+2];
	 	k=k+12;

		}
	}

	/*Interpolating vacant position in Rows of Output Buffer*/
	
	for(i=0;i<OutImgHeight;i=i+4){
		k=3;
	 for(j=0;j<OutImgWidthpx;j=j+12){
	 	for(l=0;l<3;l++){
	 	/*Interpolated Red Pixel*/	
	 	RGBScaleF[OutImgWidthpx*i+k]= (int)(RGBScaleF[OutImgWidthpx*i + j]*(1-wt[l]))
	 					+ (int)(RGBScaleF[OutImgWidthpx*i + j+12]*wt[l]);
	 	/*Interpolated Green Pixel*/	
	 	RGBScaleF[OutImgWidthpx*i+k+1]= (int)(RGBScaleF[OutImgWidthpx*i + j+1]*(1-wt[l]))
	 					 + (int)(RGBScaleF[OutImgWidthpx*i + j+1+12]*wt[l]);
	 	/*Interpolated Blue Pixel*/							 		
	 	RGBScaleF[OutImgWidthpx*i+k+2]= (int)(RGBScaleF[OutImgWidthpx*i + j]*(1-wt[l]))
	 					 + (int)(RGBScaleF[OutImgWidthpx*i + j+2+12]*wt[l]);
	 	k=k+3;						 
	 	}
		k=k+3;
	}
}

/*Interpolating vacant position in Column of Output Buffer*/
for(i=0;i<OutImgHeight-4;i=i+4){
	
	for(j=0;j<OutImgWidthpx;j=j+1){

		/*Interpolated Red Pixel*/
		RGBScaleF[OutImgWidthpx*(i+1)+j]=(int)(RGBScaleF[OutImgWidthpx*i+j]*(1-wt[l])) 
						  + (int)(RGBScaleF[OutImgWidthpx*(i+4)+j]*wt[l]);

		/*Interpolated Green Pixel*/
		RGBScaleF[OutImgWidthpx*(i+2)+j]=(int)(RGBScaleF[OutImgWidthpx*i+j]*(1-wt[l+1])) 
	 					 + (int)(RGBScaleF[OutImgWidthpx*(i+4)+j]*wt[l+1]);
	 	/*Interpolated Blue Pixel*/
		RGBScaleF[OutImgWidthpx*(i+3)+j]=(int)(RGBScaleF[OutImgWidthpx*i+j]*(1-wt[l+2])) 
						  + (int)(RGBScaleF[OutImgWidthpx*(i+4)+j]*wt[l+2]);
	}
}

 
fwrite(&RGBScaleF,sizeof(char),SIZE_OF_OUTPUT_IMAGE_4,Output);
fclose(Output);
}
