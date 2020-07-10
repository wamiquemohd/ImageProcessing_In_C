#ifndef WIDTH
#define WIDTH 1280   /*size of Image*/
#define HEIGHT 960
#endif
#include<stdint.h>

void Yuv444ToRGB(uint8_t *,int,int);
uint8_t clamp(int32_t);
