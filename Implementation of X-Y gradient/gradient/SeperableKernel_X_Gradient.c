#include "SeperableKernel_X_Gradient.h"

/*Global variable (stored in data segment) for storing Image Data */
int IntermediateBuff_x[HEIGHT+2][WIDTH+2]={0};
int Sep_X_int[HEIGHT*WIDTH]={0};

/*clamp1 function is used to limit the values of pixels between 0 to 255

  Parameter: value -> takes input any value respective to size of integer

  Returns : Unsigned Integer*/
uint8_t clamp1(int value){
if (value>255){
	return 255;
}
if(value<0){
	return 0;
}
return value;
}

/*SeperableKernel_X_Gradient function is used to find X-gradient of Image using seperable kernel.
  Here two filters are used of size (3*1) and (1*3) instead of one kernel of size(3*3)

  Parameters: GreyBuff-> It stores the information of Grey Image
  			  width-> Width of Image
  			  height-> Height of Image
  Returns: Nothing*/
void SeperableKernel_X_Gradient(uint8_t *GreyBuff,int width,int height){

/*Here 3*3 kernel is broken down into 3*1 and 1*3 kernel. Thus this seperable kernel is used to find out
  X-gradient by convolving both seperable kernel one by one with Input Image
  [X-gradient Image= (Image conv Filter_x1) conv Filter_x2]*/ 
/*Note: conv = convolution*/
int Filter_x1[3]={ 1,
		   1,
		   1 };

int Filter_x2[3]={1, 0, -1 };

/*Local Buffer for storing X-gradient data*/
uint8_t Sep_X_GradBuff[HEIGHT*WIDTH]={0};
int pixel=0,sum=0,count=0,no=0;

/*Files to store X gradient*/
FILE *sep_X=fopen("Sep_X_Grad.yuv","wb+");

/*Padding Input Image with Zeros at boundary in order to perform convolution 
  (as here we have to place center of filter(3*1)/(1*3) at first pixel in order to 
  find out convolute value)*/
#if 1
for(int i=1;i<(height+2)-1;i++){

	for(int j=1;j<(width+2)-1;j++){
		
		/*Intermediate Buffer holds the Input Image with zeros at boundary*/
		IntermediateBuff_x[i][j] = GreyBuff[pixel];
		pixel++;
	}
}
#endif
pixel=0;
/*Here part of X-gradient of Image is Calculated as Image is convloved with X1 filter(Kernel)*/
#if 1
for(int NewImgHt=0;NewImgHt<height;NewImgHt++){
	for(int NewImgWt=1;NewImgWt<=width;NewImgWt++){
			
		for(int FilterWt=NewImgWt;FilterWt<NewImgWt+1;FilterWt++){
			for(int FilterHt=NewImgHt;FilterHt<NewImgHt+3;FilterHt++){

				/*Performing Convolution: As placing center of Kernel at every pixel
			 	and calculating the values after series of multiplication and addition 
			 	refer pdf attached for detailed Implementation*/	
				sum = sum + Filter_x1[pixel]*IntermediateBuff_x[FilterHt][FilterWt];
			
				pixel++;
			}
		}
		
		/*After finishing calutaion on one pixel, value is stored in Sep_X_int
		 Sep_X_int => InputImage conv Filter_x1*/
		Sep_X_int[count]=(sum);

		count++;
		sum=0;
		pixel=0;
		

	}
}

/*Intermediate Buffer holds the [Input image conv filter_x1] with zeros at boundary for 
 further calculation*/
for(int i=1;i<(height+2)-1;i++){

	for(int j=1;j<(width+2)-1;j++){

		IntermediateBuff_x[i][j] = Sep_X_int[pixel];
		pixel++;
	}
}
#endif
count=0;
pixel=0;

/*Here X-gradient of Image in Calculated as Intermediate Image is convloved with filter_x2(Kernel)*/
for(int NewImgHt=1;NewImgHt<=height;NewImgHt++){
	for(int NewImgWt=0;NewImgWt<width;NewImgWt++){

		for(int FilterHt=NewImgHt;FilterHt<NewImgHt+1;FilterHt++){
			for(int FilterWt=NewImgWt;FilterWt<NewImgWt+3;FilterWt++){

				/*Performing Convolution: As placing center of Kernel at every pixel
			 	and calculating the values after series of multiplication and addition 
			 	refer pdf attached for detailed Implementation*/
				sum = sum + Filter_x2[pixel]*IntermediateBuff_x[FilterHt][FilterWt];
				pixel++;
			}
		}
		/*After finishing calutaion on one pixel, value is stored in Sep_X_int
		 Sep_X_GradBuff => (InputImage conv Filter_x1) conv Filter_x2*/
		Sep_X_GradBuff[count]=clamp1(sum);
		
		count++;
		sum=0;
		pixel=0;
		

	}
}

/*values in Sep_X_GradBuff is written in File Sep_X_Grad.yuv*/
fwrite(&Sep_X_GradBuff,sizeof(char),width*height,sep_X);
fclose(sep_X);



}
