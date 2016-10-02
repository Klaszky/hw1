//	includes and prototypes
//////////////////////////
#include <stdio.h>
#include <unistd.h>

int atoi(char*);


int main(int argc, char *argv[])
{
	// check to see if anything was enetered into cmd line
	//////////////////////////
	if(argc < 2)
	{
		printf("error\n");
		return 0;
	}


	int input_int = atoi(argv[1]);

	// does some leg work getting rid of any evens off the batt
	// and numbers under 4
	//////////////////////////
	if(input_int < 4 && input_int > 0)
	{
		printf("yes\n");
		return 0;
	}
	else if(input_int % 2 == 0)
	{
		printf("no\n");
		return 0;
	}

	int i;

	// tries to divie the input num by all odd ints
	// up to half of its value
	//////////////////////////
	for(i = 3; i < ( (input_int + 1) / 2 ); i+=2)
	{
		if(input_int % i == 0)
		{
			printf("no\n");
			return 0;
		} 
		
	}

	printf("yes\n");
	return 0;
}
