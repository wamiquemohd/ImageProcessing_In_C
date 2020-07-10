
#Script for compiling all files at once


gcc main.c Yuv420ToYuv444.c Yuv444ToRgb.c -o output 

./output

echo "compile worked!->Image converted to RGB"

