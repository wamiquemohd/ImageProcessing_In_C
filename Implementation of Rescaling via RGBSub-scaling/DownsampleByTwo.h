/*Conditional compilation*/
#ifndef WIDTH
#define WIDTH 1280
#define HEIGHT 960
#include<stdio.h>
#include<stdint.h>
#endif

#define SIZE_OF_OUTPUT_IMAGE_2 (WIDTH/2)*(HEIGHT/2)*3

void DownsampleByTwo(uint8_t *,int ,int );
