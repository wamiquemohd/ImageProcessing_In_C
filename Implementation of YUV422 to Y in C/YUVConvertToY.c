/**************************************************
*Code for Converting YUV422 image to Y
*Converted Image will only have Y(LUMA) component in it.

Author: Wamique
Date:31st, May, 2020

****************************************************/



#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define WIDTH 1280   /*size of Image*/
#define HEIGHT 960

void YuvConvertToY(uint8_t *,uint8_t *,int width,int height); /*func for processing*/



int main(){
	
	uint8_t YuvData[WIDTH*HEIGHT*2]={0};
	uint8_t YData[WIDTH*HEIGHT]={0};     /*as Y image will not have chroma.So,size is halved*/

	FILE *Input=fopen("YUV422image.yuv","rb+");  
	if(Input == NULL){
		fprintf(stderr,"Can't open the file\n");
		exit(1);
	}    

	FILE *Output=fopen("YConvertedimage.yuv","wb+");
	if(Output == NULL){
		fprintf(stderr,"Can't open the file\n");

	}

	/*Reading from Input file YUV422 at once in array YuvData */
	fread(&YuvData,sizeof(uint8_t),WIDTH*HEIGHT*2,Input);

	/**Processing Function**/ 	
	YuvConvertToY(YuvData,YData,WIDTH,HEIGHT);

	/*Writing data in new file (converted to Y)*/
	fwrite(&YData,sizeof(uint8_t),WIDTH*HEIGHT,Output);

	fclose(Input); /*closing file*/
	fclose(Output);
	return 0;

}

/***Actual processing***/
/*
Function: YuvConverterToY
	 	  Used for converting YUV image to Y
	
YuvData:pointer to array containing YUV422 data
YData: 	pointer to array in which Y data is to be stored

Returns: nothing	

*/
void YuvConvertToY(uint8_t YuvData[],uint8_t YData[],int width,int height){
	
	int i=0;
	for(i=0;i<(width*height*2);i=i+2){
		YData[i>>1]=YuvData[i];     /*Y data is stored in every alternate block of array of YUV422*/	
	}

}
