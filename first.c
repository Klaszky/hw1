// includes and prototypes
//////////////////////////
#include <stdio.h>
#include <unistd.h>
#include "first.h"


int main(int argc, char *argv[])
{
	// check if there was anything entered into the cmd line
	//////////////////////////
	if(argc < 2)
	{
		printf("error\n");
		return 0;
	}

	// changes input from char to int
	//////////////////////////
	int intputInt = atoi(argv[1]);

	if(intputInt % 2 == 0)
	{
		printf("even\n");
	}
	else
	{
		printf("odd\n");
	}

        return 0;
}
