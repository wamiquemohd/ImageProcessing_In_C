#include<stdio.h>
#include<stdint.h>
#include "Yuv420ToY.h"

/*Function name: Yuv420ToY

  Parameter: YUV420->(Input Image Data)
  			 YData->(Output Image Data)
  			 Width (Image)
  			 Heignt (Image)

  Returns: Nothing


  So,here we only want Y Data. So we only have read
  Y Plane from YUV420 image and written this Y plane in new file
*/
void Yuv420ToY(uint8_t YUV420[],uint8_t YData[],int width,int height)
{

	uint32_t LulCount=0;
	for(LulCount=0;LulCount<width*height;LulCount++)
	{
		/*Extracted only Y plane*/
		YData[LulCount]=YUV420[LulCount];       
	}


}
