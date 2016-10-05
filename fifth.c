// inclues and prototypes and a global var
//////////////////////////
#include <stdio.h>
#include <string.h>

int **twoDarr;

// function i'll run at end of program
//////////////////////////
void printArr(int numRows, int numCols, int **twoDarray)
{
	int i, j;
	for(i = 0; i < numRows; i++)
	{
		for(j = 0; j < numCols; j++)
		{
			if(j == 0)
			{
				printf("%d", twoDarray[i][j]);
			}
			else
			{
				printf("\t%d", twoDarray[i][j]);
			}
		}
		printf("\n");
	}
}


int main(int argc, char *argv[])
{
	// set up of twoD array and prep to read from file
	//////////////////////////
	int rows, cols, value;
	int i, j;
	FILE *filePointer;
	char *mode = "r";


	if(argc == 1)
	{
		printf("error\n");
		return 0;
	}
	else
	{
		// reads from file and sets up array
		//////////////////////////
		filePointer = fopen(argv[1], mode);
		if(filePointer == NULL)
		{
			printf("error\n");
			return 0;
		}

		fscanf(filePointer, "%d %d", &rows, &cols);

		// gets dimensions of array
		//////////////////////////
		twoDarr = (int **) malloc(rows * sizeof(int *));
		for(i = 0; i < rows; i++)
		{
			twoDarr[i] = (int *) malloc(cols * sizeof(int));
		}

		// populations array with initial values
		//////////////////////////
		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
			{
				fscanf(filePointer, "%d", &value);
				twoDarr[i][j] = value;
			}
		}

		// adds values current values to initial values
		//////////////////////////
		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
			{
				fscanf(filePointer, "%d", &value);
				twoDarr[i][j] += value;
			}
		}
	}

	// prints final array
	//////////////////////////
	printArr(rows, cols, twoDarr);
	return 0;
}
