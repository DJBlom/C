#include <stdio.h>

#define size 100

void Insertion(int array[], int len);

int main(void)
{
	int array[size];
	int i, len;

	printf("Input the length of the index:> ");
	scanf("%d", &len);

	for (i = 0; i < len; i++)
	{
		printf("Input index elements:> ");
		scanf("%d", &array[i]);
	}

	Insertion(array, len);

	return 0;
}

void Insertion(int array[], int len)
{
	int i, j, temp;

	for (int i = 1; i < len; i++)
	{
		j = i;
		temp = array[i];
		while (j > 0 && array[j - 1] > temp)
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = temp;
	}

	for (i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return;
}
