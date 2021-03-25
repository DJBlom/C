#include <stdio.h>
#include <stdbool.h>


#define size 100



bool Linear(int array[], int len, int num);

int main(void)
{
	int array[size];
	int len, num, found;

	printf("Input index length:> ");
	scanf("%d", &len);

	printf("Input index elements:> ");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Input element to search for:> ");
	scanf("%d", &num);


	found = Linear(array, len, num);

	if (found == 0)
	{
		printf("Element %d was found in the index.", num);
	}
	else
	{
		printf("Element not found.");
	}
	printf("\n");

	return 0;
}



bool Linear(int array[], int len, int num)
{
	int i, found;

	for (i = 0; i < len; i++)
	{
		if (array[i] == num)
		{
			found = array[i];
		}
	}

	if (found == num)
	{
		return false;
	}
	
	return true;
}
