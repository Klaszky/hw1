// includes, prototypes, and def of const var
//////////////////////////
#include <stdio.h>
#include <string.h>

#define MAX 1000

void *malloc(size_t size);
void free(void *ptr);
int fscanf(FILE *stream, const char *format, ...);
int strcmp(const char *string1, const char *string2);
int isdigit(int num);
int atoi(const char *nptr);
size_t strlen(const char *str);

// struct of my hashItem and some global vars
//////////////////////////
struct hashItem
{
	int data;
};

struct hashItem *hashArr[MAX];
struct hashItem *item;


// functions that will be used in main
//////////////////////////
int hash(int data)
{
	if(data >= 0)
	{
		return data % MAX;
	}
	else
	{
		return -data % MAX;
	}
}

void search(int value)
{
	int index = hash(value);
	
	while(hashArr[index] != NULL)
	{
		if(hashArr[index]->data == value)
		{
			printf("present\n");
			return;
		}

		index++;

		if(index == MAX)
		{
			index = 0;
		}
	}

	printf("absent\n");
	return;
}

void insert(int value)
{
	struct hashItem *item = (struct hashItem*) malloc(sizeof(struct hashItem));
	item->data = value;

	int index = hash(value);
			
	while(hashArr[index] != NULL)
	{
		if(hashArr[index]->data == value)
		{
			return;
		}

		index++;

		if(index == MAX)
		{
			index = 0;
		}
	}
	hashArr[index] = item;
	printf("inserted\n");
}

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
		if(input[i] == '-' && i == 0 && strlen(input) > 1)
		{
			continue;
		}
		if(!isdigit(input[i]))
		{
			flag = 0;
			return flag;
		}
	}

	return flag;
}

// end of function definitions
//////////////////////////

int main(int argc, char *argv[])
{
	// set up and prep to read from file
	//////////////////////////
	FILE *filePointer;
	char *mode = "r";
	if(argc == 1)
	{
		printf("error\n");
		return 0;
	}
	else
	{
		filePointer = fopen(argv[1], mode);
		if(filePointer == NULL)
		{
			printf("error\n");
			return 0;
		}
	}

	// gets info from file and inserts and searches as needed
	//////////////////////////
	char text[5];
	char value[15];
	while(fscanf(filePointer, "%s %s", text, value) != EOF)
	{
		if( strcmp(text, "i") != 0 && strcmp(text, "s"))
		{
			printf("error\n");
		}
		else if(!isDig(value))
		{
			printf("error\n");
		}
		else if(!strcmp(text, "i"))
		{
			insert(atoi(value));
		}
		else if(!strcmp(text, "s"))
		{
			search(atoi(value));
		}
	}

	return 0;
}