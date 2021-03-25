// All the libraries used for this project.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Constant used for the text entered.
#define size 1000

// Declaration of the function.
void cipher(char *text, int key);

// Main program that takes a command line argument as input.
int main(int argc, char *argv[])
{
	// Variables used in this code.
	char text[size];
	int i, len, key;

	// This is to check that the command line argument only takes 2 elements as input.
	if (argc != 2)
	{
		printf("Usage: ./cipher [num], not [num..num]\n");
		return 1;

	}

	// This checks that the command line argument entered is a digit
	for (i = 0, len = strlen(argv[1]); i < len; i++)
	{
		if (!isdigit(argv[1][i]))
		{
			printf("Only give numbers as the key.\n");
			return 1;
		}
	}
	// This is to convert the command line argument entered into a intiger key to be used.
	key = atoi(argv[1]);

	// Takes the users input.
	printf("Input some text:> ");
	fgets(text, size, stdin);

	// Print out the message in the cipher format.
	printf("Ciphertext: ");
	cipher(text, key);
	
	// Returns 0 if there are not errors.
	return 0;
}

// The function used for this program.
void cipher(char *text, int key)
{
	int i, len;
	
	// Starting with a loop and then checking for alphabetical chars
	// to shift.
	// If a char is found, depending on if it's upper of lower case.
	// we will shift it by using it's ascii value.
	for (i = 0, len = strlen(&text[i]); i < len; i++)
	{
		if (isalpha(text[i]))
		{
			if (isupper(text[i]))
			{
				printf("%c", ((text[i] - 65 + key) % 26) + 65);
			}
			else if (islower(text[i]))
			{
				printf("%c", ((text[i] - 97 + key) % 26) + 97);
			}
		}
		else
		{
			printf("%c", (text[i]));
		}
	}
	printf("\n");

	return;
}
