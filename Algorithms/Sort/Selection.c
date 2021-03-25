#include <stdio.h>


#define size 100

void Selection(int array[], int len);

int main(void)
{
	int array[size];
	int i, len;

	printf("Input the length of the list:> ");
	scanf("%d", &len);

	
	for (i = 0; i < len; i++)
	{
		printf("Input element of the index:> ");	
		scanf("%d", &array[i]);
	}

	Selection(array, len);

	return 0;
}


void Selection(int array[], int len)
{
	int i, j, min, temp;

	for (i = 0; i < len - 1; i++)
	{
		min = i;

		for (j = i; j < len; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}

	
	for (i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return;
}
