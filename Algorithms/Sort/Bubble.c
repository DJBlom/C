#include <stdio.h>


#define size 100

void Bubble(int array[], int len);

int main(void)
{
	int i, len;
	int array[size];
	
	printf("Input the legth of the index:> ");
	scanf("%d", &len);

	printf("Input the elements:\n");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &array[i]);
	}


	Bubble(array, len);
	
		
	return 0;
}

void Bubble(int array[], int len)
{
	int i, j, temp;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return;
}


