#include <stdio.h>


#define size 100


void Binary(int array[], int len, int num);

int main(void)
{
	int array[size];
	int i, len, num;

	printf("Input the length of the index:> ");
	scanf("%d", &len);

	printf("Input Element of the index:> ");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Input Elements to search for:> ");
	scanf("%d", &num);

	Binary(array, len, num);

	return 0;
}


void Binary(int array[], int len, int num)
{
	int begin, mid, end;

	begin = 0;
	end = len - 1;
	mid = (begin + end) / 2;

	while (begin <= end)
	{
		if (array[mid] < end)
		{
			begin = mid + 1;
		}
		else if (array[mid] == num)
		{
			printf("Element %d was found at index %d.", num, mid + 1);
			break;
		}
		else
		{
			end = mid - 1;
		}

		mid = (begin + end) / 2;
	}

	if (begin > end)
	{
		printf("Element not found.");
	}
	printf("\n");

	return;
}

