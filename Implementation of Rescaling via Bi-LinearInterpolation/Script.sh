
#Script for compiling all files at once
#Command for running this script : sh Script.sh

gcc  main.c B_ScaleByTwo.c B_ScaleByFour.c -o output 

./output

echo "compile worked!->Image converted to RGB"

