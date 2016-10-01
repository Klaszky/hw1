#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

struct HashItem
{
	int data;
	int key;
};

struct HashItem *hashArr[MAX];
struct HashItem *dItem;
struct HashItem *item;

int hashCode(int key)
{
	return key % MAX;
}

//struct HashItem *search(int key){}

void insert(int key, int data)
{}

//struct DataItem* del(struct HashItem *item){}

//void display(){}

int main(int argc, char *argv[])
{
	return 0;
}

