#include <stdio.h>
#include <stdbool.h>



#define size 100



bool Binary(int array[], int len, int num);

int main(void)
{
	int array[size];
	int i, len, num, found;

	printf("Input the length of the index:> ");
	scanf("%d", &len);

	printf("Input index elements:> ");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Input element to search for:> ");
	scanf("%d", &num);

	found = Binary(array, len, num);

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


bool Binary(int array[], int len, int num)
{
	int begin, mid, end;

	begin = 0;
	end = len - 1;
	mid = (begin + end) / 2;

	while (begin <= end)
	{
		if (array[mid] < num)
		{
			begin = mid + 1;
		}
		else if (array[mid] == num)
		{
			return false;
		}
		else
		{
			end = mid - 1;
		}

		mid = (begin + end) / 2;
	}

	if (begin > end)
	{
		return true;
	}

	return true;
}
