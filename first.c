// includes and prototypes
//////////////////////////
#include <stdio.h>
#include <unistd.h>

int atoi(char*);


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
	int intput_int = atoi(argv[1]);

	if(intput_int % 2 == 0)
	{
		printf("even\n");
	}
	else
	{
		printf("odd\n");
	}

        return 0;
}
