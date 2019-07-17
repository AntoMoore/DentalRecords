#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"
#include "deletenodes.h"

int Listlength(node_t* head)
{
	node_t* temp;
	int count = 0;
	temp = head;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}//length

int findPosition(node_t* head, int pps)
{
	//local variables
	int counter = 0;
	int searchNum = pps;
	int found = 0; //false
	char input;

	//get current pointer
	node_t* current = head;

	//while current not empty
	while (current != NULL)
	{
		//check PPS number
		if (searchNum == current->patientPPS)
		{
			found = 1; //true
			counter++;
			return counter;
		}
		else
		{
			counter++;
		}

		//next node pointer
		current = current->next;
	}//while

	// return false
	return -1;
}//findPosition


void deletePatientFront(node_t** head)
{
	//create temp node pointer
	node_t* temp;

	//make temp pointer equals head
	temp = *head;

	//assign head pointer to next node in list 
	*head = temp->next;

	//clear temp node
	free(temp);
}//deleteFront

void deletePatientPosition(node_t* head, int pos)
{
	//local variables
	int i;
	struct node* temp;
	struct node* prev_temp;
	struct node* newNode;

	//make a temp equals head pointer
	temp = head;

	for (i = 0; i < pos - 1; i++)
	{
		//search through nodes until pos
		prev_temp = temp;
		temp = temp->next;
	}

	//set pervious pointer to temp next
	prev_temp->next = temp->next;

	//clear temp
	free(temp);
}//deletePosition
