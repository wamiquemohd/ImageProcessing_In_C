
#include "SeperableKernel_Y_Gradient.h"

/*Global variable (stored in data segment) for storing Image Data */
int IntermediateBuff[HEIGHT+2][WIDTH+2]={0};
int Sep_Y_int[HEIGHT*WIDTH]={0};

/*clamp2 function is used to limit the values of pixels between 0 to 255

  Parameter: value -> takes input any value respective to size of integer

  Returns : Unsigned Integer*/
uint8_t clamp2(int value){
if (value>255){
	return 255;
}
if(value<0){
	return 0;
}
return value;
}

/*SeperableKernel_Y_Gradient function is used to find Y-gradient of Image using seperable kernel.
  Here two filters are used of size (3*1) and (1*3) instead of one kernel of size(3*3)

  Parameters: GreyBuff-> It stores the information of Grey Image
  			  width-> Width of Image
  			  height-> Height of Image
  Returns: Nothing*/
void SeperableKernel_Y_Gradient(uint8_t *GreyBuff,int width,int height){

/*Here 3*3 kernel is broken down into 3*1 and 1*3 kernel. Thus this seperable kernel is used to find out
  Y-gradient by convolving both seperable kernel one by one with Input Image
  [Y-gradient Image= (Image conv Filter_y1) conv Filter_y2]*/ 
/*Note: conv = convolution*/
 
int Filter_y1[3]={ 1,
		   0,
		  -1 };

int Filter_y2[3]={1, 1, 1 };

/*Local Buffer for storing X-gradient data*/
uint8_t Sep_Y_GradBuff[HEIGHT*WIDTH]={0};
int pixel=0,sum=0,count=0,no=0;

/*Files to store Y gradient*/
FILE *sep_Y=fopen("Sep_Y_Grad.yuv","wb+");

/*Padding Input Image with Zeros at boundary in order to perform convolution 
  (as here we have to place center of filter(3*1)/(1*3) at first pixel in order to 
  find out convolute value)*/
#if 1
for(int i=1;i<(height+2)-1;i++){

	for(int j=1;j<(width+2)-1;j++){

		/*Intermediate Buffer holds the Input Image with zeros at boundary*/
		IntermediateBuff[i][j] = GreyBuff[pixel];
		pixel++;
	}
}
#endif
pixel=0;

/*Here part of Y-gradient of Image is Calculated as Image is convloved with Y1 filter(Kernel)*/
#if 1
for(int NewImgHt=0;NewImgHt<height;NewImgHt++){
	for(int NewImgWt=1;NewImgWt<=width;NewImgWt++){
		
		for(int FilterWt=NewImgWt;FilterWt<NewImgWt+1;FilterWt++){
			for(int FilterHt=NewImgHt;FilterHt<NewImgHt+3;FilterHt++){

				/*Performing Convolution: As placing center of Kernel at every pixel
			 	and calculating the values after series of multiplication and addition 
			 	refer pdf attached for detailed Implementation*/
				sum = sum + Filter_y1[pixel]*IntermediateBuff[FilterHt][FilterWt];
				
				pixel++;
			}
		}
		/*After finishing calutaion on one pixel, value is stored in Sep_Y_int
		 Sep_Y_int => InputImage conv Filter_y1*/
		Sep_Y_int[count]=sum;

		count++;
		sum=0;
		pixel=0;
	}
}

/*Intermediate Buffer holds the [Input image conv filter_y1] with zeros at boundary for 
 further calculation*/
for(int i=1;i<(height+2)-1;i++){

	for(int j=1;j<(width+2)-1;j++){

		IntermediateBuff[i][j] = Sep_Y_int[pixel];
		pixel++;
	}
}
#endif
count=0;
pixel=0;

/*Here Y-gradient of Image in Calculated as Intermediate Image is convloved with filter_y2(Kernel)*/
for(int NewImgHt=1;NewImgHt<=height;NewImgHt++){
	for(int NewImgWt=0;NewImgWt<width;NewImgWt++){

		for(int FilterHt=NewImgHt;FilterHt<NewImgHt+1;FilterHt++){
			for(int FilterWt=NewImgWt;FilterWt<NewImgWt+3;FilterWt++){

				/*Performing Convolution: As placing center of Kernel at every pixel
			 	and calculating the values after series of multiplication and addition 
			 	refer pdf attached for detailed Implementation*/
				sum = sum + Filter_y2[pixel]*IntermediateBuff[FilterHt][FilterWt];
				pixel++;
			}
		}
		/*After finishing calutaion on one pixel, value is stored in Sep_X_int
		 Sep_Y_GradBuff => (InputImage conv Filter_y1) conv Filter_y2*/
		Sep_Y_GradBuff[count]=clamp2(sum);

		count++;
		sum=0;
		pixel=0;
		

	}
}
/*values in Sep_Y_GradBuff is written in File Sep_Y_Grad.yuv*/

fwrite(&Sep_Y_GradBuff,sizeof(char),width*height,sep_Y);
fclose(sep_Y);

}
