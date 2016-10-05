//	includes and prototypes
//////////////////////////
#include <stdio.h>
#include <unistd.h>
#include "second.h"

int main(int argc, char *argv[])
{
	// check to see if anything was enetered into cmd line
	//////////////////////////
	if(argc < 2)
	{
		printf("error\n");
		return 0;
	}


	int inputInt = atoi(argv[1]);

	// does some leg work getting rid of any evens off the batt
	// and numbers under 4
	//////////////////////////
	if(inputInt < 4 && inputInt > 0)
	{
		printf("yes\n");
		return 0;
	}
	else if(inputInt % 2 == 0)
	{
		printf("no\n");
		return 0;
	}

	int i;

	// tries to divie the input num by all odd ints
	// up to half of its value
	//////////////////////////
	for(i = 3; i < ( (inputInt + 1) / 2 ); i+=2)
	{
		if(inputInt % i == 0)
		{
			printf("no\n");
			return 0;
		} 
		
	}

	printf("yes\n");
	return 0;
}
