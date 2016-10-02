// includes and prototypes
//////////////////////////
#include <stdio.h>
#include <string.h>

int strcmp(const char *string1, const char *string2);
void *malloc(size_t size);
int fscanf(FILE *stream, const char *format, ...);
void free(void *ptr);


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
		printf("%d ",current->data);
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
		int data;
		while (fscanf(filePointer, "%s %d", text, &data) != EOF)
		{
			if( strcmp(text, "i") != 0 && strcmp(text, "d") != 0  )
			{
				printf("error\n");
				return 0;
			}

			if(!strcmp(text, "i"))
			{
				insertOrd(head, data);
			}
			else if(!strcmp(text, "d"))
			{
				del(head, data);
			}
		}
	}

	// prints final LL
	//////////////////////////
	printLL(head);

	return 0;

}
