/**************************************************
 *Code For finding gradient in X,Y direction using Normal Kernel
 *Code For finding gradient in X,Y direction using Seperable Kernel


 Author: Wamique
 Date:4th, July, 2020

****************************************************/



#include<stdio.h>
#include<stdint.h>
/*size of Image*/
#define WIDTH 1280   
#define HEIGHT 960

#include "Gradient_XY.h"
#include "SeperableKernel_X_Gradient.h"
#include "SeperableKernel_Y_Gradient.h"


int main(){
	
	/*Size of Input image*/
	uint8_t GreyBuff[WIDTH*HEIGHT]={0};
	
	FILE *Input=fopen("Grey.yuv","rb+");          

	/*Reading from Input file Grey Image at once in array GreyBuff */
	fread(&GreyBuff,sizeof(char),WIDTH*HEIGHT,Input);

	/**Processing Function**/ 	

	/*Gradient_XY function finds out X-gradient and Y-gradient
	  using Normal Kernel of size 3*3 */
	Gradient_XY(GreyBuff,WIDTH,HEIGHT);

	/*SeperableKernel_X_Gradient finds out the X-gradient using seperable kernel
	i.e two kernel of size 3*1 and 1*3 respectively.*/
	SeperableKernel_X_Gradient(GreyBuff,WIDTH,HEIGHT);

	/*SeperableKernel_Y_Gradient finds out the Y-gradient using seperable kernel
	i.e two kernel of size 3*1 and 1*3 respectively.*/
    	SeperableKernel_Y_Gradient(GreyBuff,WIDTH,HEIGHT);


	/*closing file*/
	fclose(Input); 
	return 0;

}



 
