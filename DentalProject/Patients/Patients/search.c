#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"
#include "search.h"

void search(node_t* head)
{
	//local variables
	int searchNum;
	int found = 0; //false

	//get current pointer
	node_t* current = head;

	//prompt user
	printf("Enter Patient PPS: ");
	scanf("%d", &searchNum);

	//while current not empty
	while (current != NULL)
	{
		//check PPS number
		if (searchNum == current->patientPPS)
		{
			found = 1; //true
			printf("\nPPS: %d \nName: %s %s \nYear: %d \nGender: %c \nEmail: %s \nNext Of Kin: %s %s \nLast Appointment: %d \nWeight: %.2f \nHeight: %.2f \nAllergies: %c \nSmoking: %d \nAlcohol: %d \nExercise: %d \n",
				current->patientPPS, current->patientFirst, current->patientLast, current->patientYear, current->patientGender, current->patientEmail, current->nextOfKinFirst, current->nextOfKinLast,
				current->patientAppointment, current->patientWeight, current->patientHeight, current->patientAllergies, current->patientSmokes, current->patientAlcohol, current->patientExercise);

			return;
		}

		//next node pointer
		current = current->next;

	}//while
	if (found != 1)
	{
		printf("\nPatient Not Found!\n");
	}
}//search

void updatePatient(node_t* head)
{
	//local variables
	int searchNum;
	int found = 0; //false

	//get current pointer
	node_t* current = head;

	//prompt user
	printf("Enter Patient PPS: ");
	scanf("%d", &searchNum);

	//while current not empty
	while (current != NULL)
	{
		//check PPS number
		if (searchNum == current->patientPPS)
		{
			found = 1; //true
			printf("\nPatient Found!\n");

			printf("\nCurrent PPS: %d", current->patientPPS);
			//Cant change PPS as it is a unique value

			printf("\nCurrent First Name: %s", current->patientFirst);
			printf("\nNew First Name: ");
			scanf("%s", &current->patientFirst);

			printf("\nCurrent Last Name: %s", current->patientLast);
			printf("\nNew Last Name: ");
			scanf("%s", &current->patientLast);

			printf("\nCurrent Year Born: %d", current->patientYear);
			printf("\nNew Year Born: ");
			scanf("%d", &current->patientYear);

			printf("\nCurrent Gender: %c", current->patientGender);
			printf("\nNew Gender: ");
			scanf(" %c", &current->patientGender);

			printf("\nCurrent Email: %s", current->patientEmail);
			printf("\nNew Email: ");
			scanf("%s", &current->patientEmail);

			printf("\nCurrent Next of Kin First Name: %s", current->nextOfKinFirst);
			printf("\nNew Next of Kin First Name: ");
			scanf("%s", &current->nextOfKinFirst);

			printf("\nCurrent Next of Kin Last Name: %s", current->nextOfKinLast);
			printf("\nNew Next of Kin Last Name: ");
			scanf("%s", &current->nextOfKinLast);

			printf("\nCurrent Weight: %.2f", current->patientWeight);
			printf("\nNew Weight: ");
			scanf("%f", &current->patientWeight);

			printf("\nCurrent Height: %.2f", current->patientHeight);
			printf("\nNew Height: ");
			scanf("%f", &current->patientHeight);

			printf("\nCurrent Allergies: %c", current->patientAllergies);
			printf("\nNew Allergies: ");
			scanf(" %c", &current->patientAllergies);

			printf("\nCurrent Smoking: %d", current->patientSmokes);
			printf("\nNew Smoking: ");
			scanf("%d", &current->patientSmokes);

			printf("\nCurrent Alcohol: %d", current->patientAlcohol);
			printf("\nNew Alcohol: ");
			scanf("%d", &current->patientAlcohol);

			printf("\nCurrent Exercise: %d", current->patientExercise);
			printf("\nNew Exercise: ");
			scanf("%d", &current->patientExercise);

			return;
		}

		//next node pointer
		current = current->next;

	}//while
	if (found != 1)
	{
		printf("\nPatient Not Found!\n");
	}

}//updatePatient
