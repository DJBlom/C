// All the libs used for this program.
#include <stdio.h>


// Custom function to find the GCD of two numbers.
int gcd(int n, int m);

// Main program to calculate the gear cutting with a cincitanni deviding head.
int main(void)
{
	// Variable used to get user input.
	int t;
	// A loop to check that the user puts a number above 5 in.
	do
	{
		printf("Input number of Gear Teeth:> ");
		scanf("%d", &t);
	}
	while (t < 5);

	// All variables used in this program as well as the array used. 
	int i, tr, p, hcf, rem, newR, newT, newTH, sum, max, min, remi,sumi, reme, sumu, newP, holeN, Hover;
	int pN[] = {15, 17, 18, 19, 20, 21, 23, 24, 27, 29, 31, 33, 37, 39, 41, 43, 47, 49};

	// Variable assignments and values given to them.
	p = 40;
	tr = p / t;
	rem = p - t;
	hcf = gcd(p, t);
	newR = rem / hcf;
	newT = t / hcf;
	newP = p / hcf;


	// Loop to check all the calculations.
	for (i = 0; i <= 17; i++)
	{
		// Checking all the calculations made if it matches up with the array used. 
		if (pN[i] % newT == 0)
		{
			// Logic for when the teeth is less than the plate and plate devided by teeth is an odd number.
			if (t <= p && p % t != 0)
			{
				sum = t * tr;
				max = (sum < p) ? p : sum;
				min = (sum < p) ? sum : p;
				remi = max - min;
				sumi = (remi < hcf) ? hcf : remi;
				reme = (remi < hcf) ? remi : hcf;
				sumu = sumi / reme;

				// Logic for when the amount of turns used is more than 1.
				if (tr >= 2)
				{
					holeN = pN[i];
					newTH = pN[i] / newT;
					Hover = newTH * sumu;
					printf("Amount of Turns = %d\n", tr);
					printf("Amount of spaces to move over = %d\n", Hover);
					printf("Hole number = %d\n", holeN);
					break;
				}
				// Logic for when the turns are equal to 1.
				else if (tr == 1)
				{
					holeN = pN[i];
					newTH = pN[i] / newT;
					Hover = newTH * newR;
					printf("Amount of Turns = %d\n", tr);
					printf("Amount of spaces to move over = %d\n", Hover);
					printf("Hole number = %d\n", holeN);	
					break;
				}
				// Logic for when none of the above applies.
				else
				{
					holeN = pN[i];
					newTH = pN[i] / newT;
					Hover = newTH * sumi;
					printf("Amount of Turns = %d\n", tr);
					printf("Amount of spaces to move over = %d\n", Hover);
					printf("Hole number = %d\n", holeN);	
					break;
				}
			}
			// Logic for if teeth and plate can be simplified directly.
			else if (p % t == 0)
			{
				holeN = pN[i];
				printf("Amount of Turns = %d\n", tr);
				printf("Hole number = %d\n", holeN);
				break;
			}
			// Logic for if the teeth is greater than the plate.
			else if (t >= p)
			{
				holeN = pN[i];
				newTH = pN[i] / newT;
				Hover = newTH * newP;
				printf("Amount of Turns = %d\n", tr);
				printf("Amount of spaces to move over = %d\n", Hover);
				printf("Hole number = %d\n", holeN);
				break;
			}
			// If nothing matches up you cannot cut the gear.
			else
			{
				printf("NO MATCH\n");
				break;
			}
		}
	}

	return 0;
}

// Custom fuction used to find the GCD recursively.
int gcd(int n, int m)
{
	if (m == 0)
	{
		return n;
	}
	else
	{
		return gcd(m, n % m);
	}
}
