1.Use the script to compile all the files at once:
	*Use command "sh Script.sh" at terminal in Linux system
	*This command will also provide the desired output file.

2.This folder consists of:
	*main.c :for initialization of functions and basic initiation of code.

	*Gradient_XY.c: for finding X-Y Gradient of Grey Image using Normal Kernel. Outputs X,Y gradient.

	*SeperableKernel_X_Gradient.c: for finding X Gradient of Image using seperable Kernel
	[kernel sizes: 3*3 = (3*1) and (1*3)] 

	*SeperableKernel_Y_Gradient.c: for finding Y Gradient of Image using seperable Kernel
	[kernel sizes: 3*3 = (3*1) and (1*3)] 

	*Clamp function is used to limit the valueof pixel between 0 and 255.

