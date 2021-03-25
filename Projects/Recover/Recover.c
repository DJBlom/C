// All the lib includes.

#include <stdio.h>
#include <stdlib.h>

// My buffer used throughout the program.
#define BUFF 512

// Main program, it takes two arguments.
int main(int argc, char *argv[])
{

	// Checking for valid argument amount.
	if (argc != 2)
	{
		printf("./Recover [card.raw]\n");
		return 1;
	}


	// All my variables used in the program.
	int count = 0, found = 0;
	char *name = (char *) malloc(20 * sizeof(char));
	unsigned char buffer[BUFF];

	// Checking if malloc returns NULL.
	if (name == NULL)
	{
		return 1;
	}


	// Card specified by argument opened.
	FILE *file = fopen(argv[1], "r");

	// Making sure it does not equal NULL.
	if (file == NULL)
	{
		printf("Format of card is not jpeg.\n");
		return 1;
	}

	
	// Variable for seconed file to recover the argument file into.
	// also making sure it equals NULL.
	FILE *pic = NULL;

	// Algorithm to check and process the file given through the argument.
	while (fread(buffer, BUFF, 1, file) == 1)
	{
		// Checking if first 512 bytes are a jpeg.
		if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
		{
			// If jpeg already found close file
			// continue to open new file.
			if (found == 1)
			{
				fclose(pic);
			}
			else
			{
				found = 1;
			}
			
			// Found jpeg and start recovering.
			sprintf(name, "%03d1.jpg", count);
			pic = fopen(name, "w");
			count++;
		}
		
		// If jpeg already found a jpeg is in process of being written
		// keep writing to jpeg.		
		if (found == 1)
		{
			fwrite(&buffer, BUFF, 1, pic);
		}
	}

	// Print success appon recover.
	printf("Card recover successfull.\n");

	// Close all files and freeing malloc allocated memory.
	fclose(file);
	fclose(pic);
	free(name);

	return 0;
}
