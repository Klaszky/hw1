#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct hashItem
{
	int data;
};

struct hashItem *hashArr[MAX];
struct hashItem *dItem;
struct hashItem *item;

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
	
	if(hashArr[index] != NULL && hashArr[index]->data == value)
	{
		return;
	}
		
	while(hashArr[index] != NULL)
	{
		index++;

		if(index == MAX)
		{
			index = 0;
		}
	}
	hashArr[index] = item;
}

//struct DataItem* del(struct HashItem *item){}

//void display(){}

int main(int argc, char *argv[])
{
	insert(42);
	insert(42);
	insert(1042);
	search(1042);
	search(42);
	search(69);
	return 0;
}

