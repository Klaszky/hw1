#include <stdio.h>
#include <string.h>

int isdigit(int num);
size_t strlen(const char *str);
int atoi(const char *nprt);
int isDig(char *input)
{
	int flag = 1;
	int i;

	if(strlen(input) == 0)
	{
		flag = 0;
		return flag;
	}

	for(i = 0; i < strlen(input); i++)
	{
		if(!isdigit(input[i]))
		{
			flag = 0;
			return flag;
		}
	}

	return flag;
}

int main(int argc, char *argv[])
{
	int data;
	char *test = "42";
	char *test2 = "2038903847";
	char *test3 = "309842098";
	char *test4 = "3203";
	char *test5;
	char *test6 = "";
	printf("%d\n", isDig(test));
	printf("%d\n", isDig(test2));	
	printf("%d\n", isDig(test3));	
	printf("%d\n", isDig(test4));	
	printf("%d\n", isDig(test5));
	printf("%d\n", isDig(test6));
	printf("%d\n", strlen(test6));
	data = atoi(test);
	printf("%d\n", data);
	return 0;
}
