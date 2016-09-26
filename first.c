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
