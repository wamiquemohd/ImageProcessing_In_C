#include"Gradient_XY.h"

/*clamp function is used to limit the values of pixels between 0 to 255

  Parameter: value -> takes input any value respective to size of integer

  Returns : Unsigned Integer*/
uint8_t clamp(int value){
if (value>255){
	return 255;
}
if(value<0){
	return 0;
}
return value;
}

/*Gradient is a directional change in the intensity or color in an image.
  Gradient_XY function is used to find out the X-gradient and Y-gradient
  using normal Kernel(filter).

  Parameters: GreyBuff-> It stores the information of grey Image
  			  width-> Width of Image
  			  height-> Height of Image
  Returns: Nothing*/
void Gradient_XY(uint8_t *GreyBuff,int width,int height){

    /*Filter Y is Mask(Kernel) which used to find out Y-gradient of Image
      Y-Gradient= Image conv filter_y*/
	int filter_y[9]={ 
					  1, 1, 1,
					  0, 0, 0,
   					 -1,-1,-1  };

   	/*Filter X is Mask(Kernel) which used to find out X-gradient of Image
   	  X-Gradient= Image conv filter_x*/
	int filter_x[9]={ 
					 1, 0,-1,
					 1, 0,-1,
   					 1, 0,-1  };

   	/*Files to store X gradient and Y gradient*/
	FILE *Output_y=fopen("Grad_y.yuv","wb+");
	FILE *Output_x=fopen("Grad_x.yuv","wb+");

	/*Local buffers for processing*/
	uint8_t IntermediateBuff[HEIGHT+2][WIDTH+2]= {0};
	uint8_t gradBuff_x[WIDTH*HEIGHT]={0};
	uint8_t gradBuff_y[WIDTH*HEIGHT]={0};
	int pixel=0,sum=0,data=0;

	/*Padding Input Image with Zeros at boundary in order to perform convolution 
  	(as here we have to place center of filter(3*3) at first pixel in order to 
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

	/*Here Y-gradient of Image in Calculated as Image is convloved with Y filter(Kernel)*/
#if 1
	for(int ImgHt=0;ImgHt<height;ImgHt++){
		for(int ImgWdth=0;ImgWdth<width;ImgWdth++){
		
			for(int FilterHt=ImgHt;FilterHt<ImgHt+3;FilterHt++){ 
				for(int FilterWdth=ImgWdth;FilterWdth<ImgWdth+3;FilterWdth++){

				/*Performing Convolution: As placing center of Kernel at every pixel
				 and calculating the values after series of multiplication and addition 
				 refer pdf attached for detailed Implementation*/	
				sum = sum + filter_y[data]*IntermediateBuff[FilterHt][FilterWdth];
				data++;

				}
			}
		/*After finishing calutaion on one pixel, value is stored in gradBuff_y*/
		gradBuff_y[width*ImgHt+ImgWdth]=clamp(sum);

		data=0;
		sum=0;
		}
	}

	/*values in gradBuff_y is written in File Grad_y.yuv*/
	fwrite(&gradBuff_y,sizeof(char),width*height,Output_y);

	/*Here X-gradient of Image in Calculated as Image is convloved with X filter(Kernel)*/
	for(int ImgHt=0;ImgHt<height;ImgHt++){
		for(int ImgWdth=0;ImgWdth<width;ImgWdth++){
		
			for(int FilterHt=ImgHt;FilterHt<ImgHt+3;FilterHt++){ 
				for(int FilterWdth=ImgWdth;FilterWdth<ImgWdth+3;FilterWdth++){

				/*Performing Convolution: As placing center of Kernel at every pixel
				 and calculating the values after series of multiplication and addition 
				 refer pdf attached for detailed Implementation*/	
				sum = sum + filter_x[data]*IntermediateBuff[FilterHt][FilterWdth];
				data++;
				}
			}
		
		/*After finishing calutaion on one pixel, value is stored in gradBuff_x*/
		gradBuff_x[width*ImgHt+ImgWdth]=clamp(sum);

		data=0;
		sum=0;
		}
	}

	/*After finishing calutaion on one pixel, value is stored in gradBuff_x*/
	fwrite(&gradBuff_x,sizeof(char),width*height,Output_x);
#endif

	fclose(Output_x);
	fclose(Output_y);
}
