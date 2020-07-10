
#Script for compiling all files at once


gcc main.c Yuv444ToRGB_Fixpoint.c Yuv422ConverterToYUV444.c -o output 

./output

echo "compile worked!->Image converted to RGB"

