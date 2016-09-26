#include<stdio.h>
#include<unistd.h>

int atoi(char*);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("error\n");
		return 0;
	}

	int input_int = atoi(argv[1]);

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
