
#Script for compiling all files at once
#To compile this script run command: sh Script.sh


gcc  main.c AveragingByTwo.c AveragingByFour.c  -o output 

./output

echo "compile worked!->Image converted to RGB"

