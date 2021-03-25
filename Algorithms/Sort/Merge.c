#include <stdio.h>

#define size 100

void Merge(int array[], int low, int mid, int high);
void MergeSort(int array[], int low, int high);

int main(void)
{
	int array[size];
	int i, len;
	
	// Length or array.
	printf("Input the length of the index:> ");
	scanf("%d", &len);

	// User input of elements.
	for (i = 0; i < len; i++)
	{
		printf("Inpu index element:> ");
		scanf("%d", &array[i]);
	}
	
	
	// Function for algorithm being called.
	MergeSort(array, 0, len - 1);

	// Printing of new index.
	for (i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}


void MergeSort(int array[], int low, int high)
{
	int mid;

	// Check if low is less than high.
	if (low < high)
	{
		mid = (low + high) / 2;
		
		MergeSort(array, low, mid);
		MergeSort(array, mid + 1, high);

		Merge(array, low, mid, high);
	}

	return;
}

void Merge(int array[], int low, int mid, int high)
{
	int temp[size];
	int lo1, lo2, mi, i;
	lo1 = low;
	lo2 = low;
	mi = mid + 1;

	while (lo1 <= mid && mi <= high)
	{
		if (array[lo1] <= array[mi])
		{
			temp[lo2] = array[lo1];
			lo1++;
		}
		else
		{
			temp[lo2] = array[mi];
			mi++;
		}

		lo2++;
	}

	if (lo1 > mid)
	{
		for (i = mi; i <= high; i++)
		{
			temp[lo2] = array[i];
			lo2++;
		}
	}
	else
	{
		for (i = lo1; i <= mid; i++)
		{
			temp[lo2] = array[i];
			lo2++;
		}
	}

	for (i = low; i <= high; i++)
	{
		array[i] = temp[i];
	}

	return;
}
