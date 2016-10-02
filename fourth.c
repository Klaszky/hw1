// includes, prototypes, and def of const var
//////////////////////////
#include <stdio.h>
#include <string.h>

#define MAX 1000

void *malloc(size_t size);
void free(void *ptr);
int fscanf(FILE *stream, const char *format, ...);
int strcmp(const char *string1, const char *string2);

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
	return data % MAX;
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

// end of function definitions
//////////////////////////

int main(int argc, char *argv[])
{
	// set up and prep to read from file
	//////////////////////////
	FILE *file_pointer;
	char *mode = "r";
	if(argc == 1)
	{
		printf("error\n");
		return 0;
	}
	else
	{
		file_pointer = fopen(argv[1], mode);
		if(file_pointer == NULL)
		{
			printf("error\n");
			return 0;
		}
	}

	// gets info from file and inserts and searches as needed
	//////////////////////////
	char text[5];
	int value;
	while(fscanf(file_pointer, "%s %d", text, &value) != EOF)
	{
		if( strcmp(text, "i") != 0 && strcmp(text, "s"))
		{
			printf("error\n");
		}
		else if(!strcmp(text, "i"))
		{
			insert(value);
		}
		else if(!strcmp(text, "s"))
		{
			search(value);
		}
	}

	return 0;
}

