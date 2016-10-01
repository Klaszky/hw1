#include <stdio.h>
#include <string.h>

void *malloc(size_t size);
int **twoDarr;

int main(int argc, char *argv[])
{
	int rows, cols, value;
	int i, j;
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

		fscanf(file_pointer, "%d %d", &rows, &cols);

		twoDarr = (int **) malloc(rows * sizeof(int *));
		for(i = 0; i < rows; i++)
		{
			twoDarr[i] = (int *) malloc(cols * sizeof(int));
		}


		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
			{
				fscanf(file_pointer, "%d", &value);
				twoDarr[i][j] = value;
			}
		}

		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
			{
				fscanf(file_pointer, "%d", &value);
				twoDarr[i][j] += value;
			}
		}
	}

	printf("%d", twoDarr[0][0]);
	return 0;
}
