// All the includes used for this list.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// One define for the name size.
#define SIZE 10


// Double linked list structure.
typedef struct Node
{
	char name[SIZE];
	struct Node *next;
	struct Node *prev;
}
Node;

// Initialization of head and last node in the list.
Node *HEAD = NULL;
Node *LAST = NULL;

// All the Functions created for this list.
void Create_List();
void Print_List();
void Enqueue();
void Dequeue();
void Clear_List();


// Main program, nothing fancy.
int main(void)
{
	Create_List();
	Enqueue();
	Dequeue();
	Print_List();
	Clear_List();
	
	return 0;
}


// The function to create the list.
// It's meant to create one or multiple
// nodes once off, and from there you can
// create individual ones.
void Create_List()
{
	// All the variables used in this function.
	int len;
	char *data;
	Node *Nnode;
	
	// Getting the lenght of the list ONE till OOM.
	printf("Size of List:\t");
	scanf("%d", &len);

	if (len >= 1)
	{
		// Creating the head node and checking that malloc
		// does not return error.
		HEAD = (Node *) malloc(sizeof(Node));
		if (HEAD == NULL)
		{
			printf("Not Enough Memory.\n");
			exit(1);
		}
		else
		{
			// Dynamically creating the variable
			// in which to store the name of the person.
			// Also checking that malloc does not return an error. 
			data = (char *) malloc(20 * sizeof(char));
			if (data == NULL)
			{
				printf("Not Enough Memory.\n");
				exit(1);
			}
			else
			{
				// Prompting user for input.
				printf("1)Name:\t");
				scanf("%s", data);

				// Running the algorithm to create
				// the head node, and setting it to last.
				strcpy(HEAD->name, data);
				HEAD->prev = NULL;
				HEAD->next = NULL;

				LAST = HEAD;
				

				for (int i = 2; i <= len; i++)
				{
					// Creating the new node if the user wants
					// to create a list thats longer than one.
					// Checking that malloc does not return an error.
					Nnode = malloc(sizeof(Node));
					if (Nnode == NULL)
					{
						printf("Not Enough Memory.\n");
						exit(1);
					}
					else
					{
						// If user said to create more than one node
						// this will prompt the user to input another name.
						printf("%d)Name:\t", i);
						scanf("%s", data);
						
						// Algrorithm to create multiple nodes in the right order.
						strcpy(Nnode->name, data);
						Nnode->prev = LAST;
						Nnode->next = NULL;

						LAST->next = Nnode;
						LAST = Nnode;
					}
				}
				
				// Message to say it was successfull.
				printf("List Successfully Created.\n");
			}
		}
	}
	else
	{
		// Error checking for incase there is no more memory to create a list.
		printf("Not Enough Memory.\n");
		exit(1);
	}

	// Freeing the allocated memory that
	// will not be freed in a list clearing.
	free(data);
}



// Function to print the list to stdout.
void Print_List()
{
	// All the variables used in this function.
	int counter;
	Node *temp;

	// Checking that head is not NULL
	// if head is NULL there is nothing to display.
	if (HEAD == NULL)
	{
		printf("List Is Empty.\n");
	}
	else
	{
		// Algorithm used to display the list
		// with a counter.
		counter = 1;
		temp = HEAD;
		while (temp != NULL)
		{
			printf("%d)Data:\t%s\n", counter, temp->name);
			temp = temp->next;

			counter++;
		}
	}

}




// Function to add a single node 
// to the back of the list.
void Enqueue()
{
	// All the variables used in the function.
	char *data;
	Node *Nnode;

	// Creating the first node
	// and checking that malloc does not return an error.
	Nnode = (Node *) malloc(sizeof(Node));
	if (Nnode == NULL)
	{
		printf("Not Enough Memory.\n");
		exit(1);
	}
	else
	{
		// Dynamically creating the variable 
		// to store the data collected from the user.
		// Checking that malloc does not return an error.
		data = (char *) malloc(20 * sizeof(char));
		if (data == NULL)
		{
			printf("Not Enough Memory.\n");
			exit(1);
		}
		else
		{
			printf("Add Data To Queue.\n");

			// Asking for user to input the name to be added to the list.
			printf("Name:\t");
			scanf("%s", data);

			// Algorithm used to add the node to the end of the list.
			strcpy(Nnode->name, data);
			Nnode->next = NULL;
			Nnode->prev = LAST;

			LAST->next = Nnode;
			LAST = Nnode;
		}

		printf("Data Add Successfull.\n");
	}

	// Freeing the memory allocated by malloc 
	// that will not be freed in a list clearing.
	free(data);
}



// A Function to remove a node form 
// the beginning of the list.
void Dequeue()
{
	// All the variable/s used in this function.
	Node *temp;

	// Making sure that there is 
	// something to remove from the list.
	if (HEAD == NULL)
	{
		printf("List Is Empty.\n");
	}
	else
	{
		// Algorithm to remove the first node in the list.
		temp = HEAD;
		HEAD = HEAD->next;
			
		if (HEAD != NULL)
		{
			HEAD->prev = NULL;
		}
		
		free(temp);
	}

	printf("First Job Cleared Successfull.\n");
}



// Function to clear the list completely.
void Clear_List()
{
	// All the variables used in the Fucntion.
	Node *temp;

	// Using a while loop to make 
	// sure the whole list will be cleared
	while (HEAD != NULL)
	{
		// If the head is NULL 
		// then there is nothing left to clear,
		// and the while loop will break.
		if (HEAD == NULL)
		{
			printf("List Is Cleared.\n");
			break;
		}
		else
		{
			// Algorithm to clear the entire list.
			// Pretty much the same except for the while loop. 
			temp = HEAD;
			HEAD = HEAD->next;

			if (HEAD != NULL)
			{
				HEAD->prev = NULL;
			}

			free(temp);
		}
	}
	printf("List Successfully Cleared.\n");
}
