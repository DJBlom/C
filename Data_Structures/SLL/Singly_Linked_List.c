// Dynamic SINGLY_LINKED_LIST for strings.
// This list is implemented as a STACK AND QUEUE.

// All the includes used in this program.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constant variable for the array size of the name.
#define SIZE 10


// The structure to create the nodes of the list.
typedef struct node
{
	char name[SIZE];
	struct node *next;
}
Node;

// Initializing the Head node to NULL.
Node *HEAD = NULL;


// All The Functions used in the program.
void Create_List();
void Print_List();
void Push();
void Pop();
void Clear_List();


// The main program, nothing fancy.
int main(void)
{
	Create_List();
	Push();
	Print_List();
	Pop();
	Clear_List();

	return 0;
}



// A function to create a list with either One node or Multiple.
void Create_List()
{
	// All the variables used in the function.
	int len;
	char *data;
	Node *temp, *tail;

	// Prompting the user for the
	// size of the list.
	printf("Size of List: ");
	scanf("%d", &len);

	if (len >= 1)
	{	
		// Creating the head node.
		// Checking that malloc does not return an error.
		HEAD = (Node *) malloc(sizeof(Node));
		if (HEAD == NULL)
		{
			printf("Not Enough Memory.\n");
			exit(1);
		}
		else
		{
			// Dynamically creating the variable,
			// for the data that will be collected.
			// Checking that malloc does not return an error.
			data = (char *) malloc(20 * sizeof(char));
			if (data == NULL)
			{
				printf("Not Enough Memory.\n");
				exit(1);
			}
			else
			{
				// Prompting user to input the name.
				// Also creating the head node.
				printf("Enter List Data.\n");
				printf("1)Name:\t");
				scanf("%s", data);

				// Algorithm to create the head node of the list.
				// and setting it to a temporary variable.
				strcpy(HEAD->name, data);
				HEAD->next = NULL;

				temp = HEAD;

				// Using a loop to add more nodes incase 
				// the user wants to have a list bigger than one.
				for (int i = 1; i < len; i++)
				{
					// Creating the tail node so that
					// anytime you want to add a node 
					// it will be at the end of the list.
					// Checking that malloc does not return an error.
					tail = (Node *) malloc(sizeof(Node));
					if (tail == NULL)
					{
						printf("Not Enough Memory.\n");
						exit(1);
					}
					else
					{
						// Asking the user for input.
						printf("%d)Name:\t", i + 1);
						scanf("%s", data);

						// Algorithm to create the rest of
						// the list.
						strcpy(tail->name, data);
						tail->next = NULL;

						temp->next = tail;
						temp = temp->next;
					}
				}			
			}
		}
	}
	else
	{
		printf("Not Enough Memory.\n");
		exit(1);
	}

	// Freeing the memory that will not 
	// be freed with a list clearing.
	free(data);
}



// A function to print the list to stdout.
void Print_List()
{
	// All the variables used in this function.
	int counter;
	Node *temp;

	// Checking that head is not NULL,
	// if head is NULL There is nothing to display.
	if (HEAD == NULL)
	{
		printf("No Item In List.\n");
	}
	else
	{
		// Printing the Data of the list to stdout.
		// Displaying a counter as well.
		printf("\nData In List.\n");
		temp = HEAD; 
		counter = 0; 
		
		while (temp != NULL) 
		{ 
			printf("%d)Data:\t%s\n", counter + 1, temp->name);
			temp = temp->next;

			counter++;
		}
	}
}



// A function to clear the 
// whole list.
void Clear_List()
{
	// All the variables used in this function.
	Node *temp;
	
	// Checking that head is not NULL
	// if head is NULL then there is nothing to clear.
	if (HEAD == NULL)
	{
		printf("List Is Empty.\n");
	}
	else
	{
		// Algorithm to clear a whole list.
		while (HEAD != NULL)
		{
			temp = HEAD;
			HEAD = HEAD->next;

			free(temp);
		}
	}

	printf("List Cleared.\n");
}



// A function to add to the STACK.
void Push()
{
	// All the variables used in this function.
	int len;
	char *data;
	Node *Nnode;

	// Creating the vairable to 
	// use for collecting user input.
	// Checking that malloc does not return an error.
	data = (char *) malloc(20 * sizeof(char));
	if (data == NULL)
	{
		printf("Not Enough Memory.\n");
		exit(1);
	}
	else
	{
		// Prompting user for input.
		printf("Number Of Names To Add:\t");
		scanf("%d", &len);

		// If user wants to push more 
		// than one at a time to the stack
		for (int i = 0; i < len; i++)
		{
			// Creating the new node.
			// Checking that malloc does not return an error.
			Nnode = (Node *) malloc(sizeof(Node));
			if (Nnode == NULL)
			{
				printf("Not Enough Memory.\n");
				exit(1);
			}
			else
			{
				// Prompting user for data.
				printf("%d)Name:\t", i + 1);
				scanf("%s", data);

				// Algorithm used to push
				// data to the list.
				strcpy(Nnode->name, data);
				Nnode->next = HEAD;

				HEAD = Nnode;
			}
		}
	}

	// Freeing the memory not
	// freed with a list clearing.
	free(data);
}


// A function to remove the first node in the list.
void Pop()
{
	// All the variables used in this function.
	Node *pop;

	// Checking that head is not NULL,
	// if it is there is nothing left to remove.
	if (HEAD == NULL)
	{
		printf("List Is Empty, Nothing To Pop.\n");
	}
	else
	{
		// Algorithm to remove first
		// node in the list.
		pop = HEAD;
		HEAD = HEAD->next;

		printf("Data Removed: %s\t\n", pop->name);
		free(pop);

	}
}
