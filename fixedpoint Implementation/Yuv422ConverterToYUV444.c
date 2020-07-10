#include"Yuv422ConverterToYUV444.h"

/*Function converts Yuv422 To Yuv444
*Parameters :Yuv422Data->contains input Image data
			 Yuv444Data-> To be filled with Yuv444 data
			 width of image
			 height of image
*Returns : Nothing	

*Basic functionality
 ___________________________________
|Y0|U0|Y1|V0 ---->|Y0|U0|V0|Y1|U0|V0|
 -----------------------------------
*/

void Yuv422ConverterToYUV444(uint8_t Yuv422Data[],uint8_t Yuv444Data[],int width,int height){
	
	int i=0,k=0,j=0;
	for(i=0;i<((width*height)/2);i++)
	{
		Yuv444Data[k+0]=Yuv422Data[j+0];
		Yuv444Data[k+1]=Yuv422Data[j+1];
		Yuv444Data[k+2]=Yuv422Data[j+3];
		Yuv444Data[k+3]=Yuv422Data[j+2];
		Yuv444Data[k+4]=Yuv422Data[j+1];
		Yuv444Data[k+5]=Yuv422Data[j+3];
		
		k=k+6;
		j=j+4;	

	}

}

