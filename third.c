// includes and prototypes
//////////////////////////
#include <stdio.h>
#include <string.h>
void *malloc(size_t size);
void free(void *ptr);
int fscanf(FILE *stream, const char *format, ...);
int strcmp(const char *string1, const char *string2);
int isdigit(int num);
int atoi(const char *nptr);
size_t strlen(const char *str);


// my linked list struct
//////////////////////////
struct node
{
	int data;
	struct node *next;
};

// functions that will be used in main
//////////////////////////

void printLL(struct node *head)
{
	if(head->next == NULL)
	{
		printf("\n");
		return;
	}
	struct node *current = head->next;
	while(current->next != NULL)
	{
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("%d",current->data);
	printf("\n");
}

void insertOrd(struct node *head, int value)
{
	struct node *current = head;
	struct node *temp = malloc(sizeof(struct node));
	temp->data = value;
	temp->next = NULL;
	while(current->next != NULL)
	{
		if(current->next->data == value)
		{
			free(temp);
			return;
		}
		else if(current->next->data > value)
		{
			temp->next = current->next;
			current->next = temp;
			return;
		}
		else
		{
			current = current->next;
		}

	}

	current->next = temp;
	temp->next = NULL;
}

void del(struct node *head, int value)
{
	struct node *current = head;
	struct node *temp = malloc(sizeof(struct node));
	while(current->next != NULL && current->next->data != value)
	{
		current = current->next;
	}

	if(current->next == NULL)
	{
		free(temp);
		return;
	}
	else
	{
		temp = current->next;
		current->next = current->next->next;
		free(temp);
	}

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

	// some set up of my linked list and prep to read
	// from the input i'll need from a file 
	//////////////////////////
	struct node *head = NULL;
	head = malloc(sizeof(struct node));


	FILE *filePointer;
	char *mode = "r";

	if(argc == 1)
	{
		printf("error\n");
		return 0;
	}
	else
	{
		// opens file, pulls out data, reports errors,
		// inserts or deletes as needed 
		//////////////////////////
		filePointer = fopen(argv[1], mode);
		if(filePointer == NULL)
		{
			printf("error\n");
			return 0;
		}

		char text[5];
		char data[20];
		while (fscanf(filePointer, "%s %s", text, data) != EOF)
		{
			if( strcmp(text, "i") != 0 && strcmp(text, "d") != 0  )
			{
				printf("error\n");
				return 0;
			}

			if(!isDig(data))
			{
				printf("error\n");
				return 0;
			}

			if(!strcmp(text, "i"))
			{
				insertOrd(head, atoi(data));
			}
			else if(!strcmp(text, "d"))
			{
				del(head, atoi(data));
			}
		}
	}

	// prints final LL
	//////////////////////////
	printLL(head);

	return 0;

}
