#ifndef WIDTH
#define WIDTH 1280
#define HEIGHT 960
#include<stdint.h>
#include<stdio.h>
#endif


#define SIZE_OF_OUTPUT_IMAGE_4 (WIDTH/4)*(HEIGHT/4)*3

void DownsampleByFour(uint8_t *,int ,int );
