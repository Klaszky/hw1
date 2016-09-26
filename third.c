#include<stdio.h>
#include<string.h>


int strcmp(const char *string1, const char *string2);
void *malloc(size_t size);
int fscanf(FILE *stream, const char *format, ...);
void free(void *ptr);

struct node
{
	int data;
	struct node *next;
};

void insert_end(struct node *head, int value)
{
	struct node *current = head;
	while(current->next != NULL)
	{
		current = current->next;
	}

	current->next = malloc(sizeof(struct node));
	current->next->next = NULL;
	current->next->data = value;
}

void print_ll(struct node *head)
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

void insert_in_ord(struct node *head, int value)
{
	struct node *current = head;
	struct node *temp = malloc(sizeof(struct node));
	temp->data = value;
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
int main(int argc, char *argv[])
{
	struct node *head = NULL;
	head = malloc(sizeof(struct node));


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
		char text[10];
		int data;
		while (fscanf(file_pointer, "%s %d", text, &data) != EOF)
		{
//			printf("%s , %d\n", text, data);
			if(!strcmp(text, "i"))
			{
				insert_in_ord(head, data);
			}else if(!strcmp(text, "d"))
			{
				del(head, data);
			}
		}
	}



//	insert_in_ord(head, 69);
//	insert_in_ord(head, 42);
//	insert_in_ord(head, 69);
//	insert_in_ord(head, 100);

	print_ll(head);

//	del(head, 20);
//	print_ll(head);
//	del(head, 100);
//	print_ll(head);
//	del(head, 42);
//	print_ll(head);
//	del(head, 100);
//	print_ll(head);
	return 0;

}
