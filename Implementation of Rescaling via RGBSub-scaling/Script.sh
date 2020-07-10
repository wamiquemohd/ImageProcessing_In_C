
#Script for compiling all files at once


gcc main.c DownsampleByTwo.c DownsampleByFour.c -o output 

./output

echo "compile worked!->Image converted to RGB"

