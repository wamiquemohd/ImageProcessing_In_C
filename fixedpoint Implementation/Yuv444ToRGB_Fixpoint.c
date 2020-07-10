#include"Yuv444ToRGB_Fixpoint.h"
#include<stdio.h>
#include <math.h>
/*This function is used to convert Yuv444 to RGB888
 *Parameters: RGBBuff-> Containing Y,U,V values to process
 	      Width of Image
 	      Height of Image	  

 *Returns: Nothing
*/
#define FACTOR   10
#define FIXED(X) X*(1<<FACTOR)

void Yuv444ToRGB_Fixpoint(uint8_t RGBBuff[],int width,int height){

 	int32_t c=0,d=0,e=0,R=0,G=0,B=0;
 	int i=0;
 	int32_t j,k,l,m;
	int32_t a1,b1,c1,d1;

 	a1=round(FIXED(1.402));
 	b1=round(FIXED(0.344));
 	c1=round(FIXED(0.714));
 	d1=round(FIXED(1.772));	

 	for(i=0;i<(width*height*3);i=i+3){
 		c=RGBBuff[i];
 		d=RGBBuff[i+1];
 		e=RGBBuff[i+2];

/*********************************************************/
 		/*formal Used for the conversion of YUV To RGB*/
 		// RGBBuff[i]=clamp(c+(1.402*(e-128)));
 		// RGBBuff[i+1]=clamp(c-0.344*(d-128)-0.714*(e-128));
 		// RGBBuff[i+2]=clamp(c+1.772*(d-128));

		RGBBuff[i]=clamp(c+((a1*(e-128))>>FACTOR));
 		RGBBuff[i+1]=clamp(c-( ((b1*(d-128))-(c1*(e-128)))>>FACTOR ));
 		RGBBuff[i+2]=clamp(c+((d1*(d-128))>>FACTOR));	
 	}

 }

/*Clamp funtion is used to limit values of RGB between (0,255)
 *Parameter: Values of R/G/B

 *Returns:clampled values of R/G/B

*/

uint8_t clamp(int32_t ch){
//  printf("ch=%d\n",ch);

if(ch>255)
	return 255;
if(ch<0)
	return 1;

return ch;

}
