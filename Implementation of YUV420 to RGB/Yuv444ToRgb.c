#include"Yuv444ToRgb.h"
#include<math.h>
/*
This function is used to convert the Yuv444 image to RGB
Parameter: RGB->contains the yuv444 data and after processing it will store RGB data
	   width of image
	   height of image

Returns: Nothing

*/
void Yuv444ToRgb(uint8_t RGB[],int width,int height){
	
 	uint8_t c=0,d=0,e=0;
 	int i=0;
 	for(i=0;i<(width*height*3);i=i+3){
 		c=RGB[i];
 		d=RGB[i+1];
 		e=RGB[i+2];

 		RGB[i]=clamp(c +round((((0b101100111<<3)*(e-128))>>3)));
 		RGB[i+1]=clamp(c-0.344*(d-128)-0.714*(e-128));
 	        RGB[i+2]=clamp(c +1.772*(d-128));

 	}
 }

/*
This function is used to limit the values of RGB between 0 and 255
Parameter: ch->raw values for RGB

Returns: values in limit of 0 to 255
*/

uint8_t clamp(int16_t ch){
if(ch>255)
	return 255;
if(ch<0)
	return 0;

return ch;

}
