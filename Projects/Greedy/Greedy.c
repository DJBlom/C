// All the included libraries used in this program.
#include <stdio.h>
#include <math.h>


// Function used to get final result.
void Pcoins(float dollars);

// Main piece.
int main(void)
{
	// This is to check that the user does not input a negative intiger.
	float dollars;
	do
	{
		printf("Input some number of change:> ");
		scanf("%f", &dollars);
	}
	while (dollars < 0);
	
	// Function used for result.
	Pcoins(dollars);
	
	return 0;
}

void Pcoins(float dollars)
{
	// All variebles used in the function.
	int cents = round(dollars * 100);
	int coins[] = {25, 10, 5, 1};
	int size = sizeof(coins)/sizeof(int);
	int sum = 0;

	// Algorithm run through a loop.
	for (int i = 0; i < size; i++)
	{
		sum += cents / coins[i];
		cents %= coins[i];
	}
	printf("Total number of coins:> %d\n", sum);	
}
