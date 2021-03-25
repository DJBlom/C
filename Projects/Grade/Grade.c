// All the libraries used for this project.
#include <stdio.h>
#include <math.h>

// Constant for the size of the arrays
#define size 1000

// All the custom functions used in the project
float ltrcount(char *text);
float wrdcount(char *text);
float sntcount(char *text);


// Main program.
int main(void)
{
	// All the variables used in the main program.
	char text[size];
	int letter, word, sentance, index;

	printf("Input some text to be checked:> ");
	fgets(text, size, stdin);

	// Final checkings of the program.
	index = round(0.0588 * (ltrcount(text) / wrdcount(text) * 100) - 0.296 * (sntcount(text) / wrdcount(text) * 100) - 15.8);

	if (index < 1)
	{
		printf("Before Grade 1.\n");
	}
	else if (index <= 15)
	{
		printf("Grade %d.\n", index);
	}
	else if (index >= 16)
	{
		printf("Grade 16+.\n");
	}

	// Return 0 upon completion if no errors had accured.	
	return 0;
}	

// Function to count all the letters in the program.
float ltrcount(char *text)
{
	int i, letters;

	i = 0;
	letters = 0;
	while (text[i] != '\0')
	{
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
		{
			letters++;
		}

		i++;
	}

	return letters;
}


// Fuction to count all the words in the program.
float wrdcount(char *text)
{
	int i, words;

	i = 0;
	words = 0;
	while (text[i] != '\0')
	{
		if (text[i] == ' ' || text[i] == '\0')
		{
			words++;
		}

		i++;
	}

	return words + 1;
}


// Function to count all the sentances in the program.
float sntcount(char *text)
{
	int i, sentances;

	i = 0;
	sentances = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			sentances++;
		}

		i++;
	}

	return sentances;
}
