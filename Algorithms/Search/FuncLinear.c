#include <stdio.h>

#define size 100




void Linear(int array[], int len, int num);

int main(void)
{
	int array[size];
	int i, num, len;

	printf("Input length of index:> ");
	scanf("%d", &len);

	printf("Input index elements:> ");
	for(i = 0; i < len; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Input element to search:> ");
	scanf("%d", &num);

	Linear(array, len, num);

	return 0;
}

void Linear(int array[], int len, int num)
{
	int i, found;

	for (i = 0; i < len; i++)
	{
		if (array[i] == num)
		{
			found = array[i];
			break;
		}
	}
	
	if (found == num)
	{
		printf("Element %d was found at index %d.", num, i + 1);
	}
	else
	{
		printf("Element not found");
	}
	printf("\n");

	return;
}
