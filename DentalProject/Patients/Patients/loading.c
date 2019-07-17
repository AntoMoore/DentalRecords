#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"
#include "loading.h"

int loginUser(FILE* login)
{
	char userName[30];
	char userPass[7];
	char loginName[30];
	char loginPass[7];
	int numRead;
	int isLogin = 0;//false

	//prompt user to enter login details
	printf("Please Enter User Name: ");
	scanf("%s", userName);
	printf("Please Enter User Password: ");
	scanf("%s", userPass);

	//read until end of file or user logs in
	while (!feof(login) && isLogin == 0)
	{
		//read number of inputs
		numRead = fscanf(login, "%s %s", loginName, loginPass);

		if (numRead == 2)
		{
			//printf("%s %s", loginName, loginPass);
			if ((strcmp(userName, loginName) == 0) && (strcmp(userPass, loginPass) == 0))
			{
				printf("\nLogin Sucess...\n");
				isLogin = 1; //true

				return isLogin;
			}
		}//if
	}//while
	return isLogin;
}//loginUser

void loadFront(node_t** head, FILE* patients)
{
	//file input variables
	int numRead;
	int pps;
	char first[15];
	char last[15];
	int year;
	char gender;
	char email[30];
	char kinFirst[15];
	char kinLast[15];
	int appointment;
	float weight;
	float height;
	char allergies;
	int smokes;
	int alcohol;
	int exercise;

	//check number of entries
	numRead = fscanf(patients, "%d %s %s %d %c %s %s %s %d %f %f %c %d %d %d", &pps, first, last, &year, &gender, email, kinFirst, kinLast,
		&appointment, &weight, &height, &allergies, &smokes, &alcohol, &exercise);

	if (numRead == 15)
	{
		if (*head == NULL)
		{
			//set new node pointer
			node_t* newNode;

			//allocate memory for new node and set values
			newNode = (struct node*)malloc(sizeof(node_t));

			newNode->patientPPS = pps;
			strcpy(newNode->patientFirst, first);
			strcpy(newNode->patientLast, last);
			newNode->patientYear = year;
			newNode->patientGender = gender;
			strcpy(newNode->patientEmail, email);
			strcpy(newNode->nextOfKinFirst, kinFirst);
			strcpy(newNode->nextOfKinLast, kinLast);
			newNode->patientAppointment = appointment;
			newNode->patientWeight = weight;
			newNode->patientHeight = height;
			newNode->patientYear = year;
			newNode->patientAllergies = allergies;
			newNode->patientSmokes = smokes;
			newNode->patientAlcohol = alcohol;
			newNode->patientExercise = exercise;

			//next pointer is the "old" head of list
			newNode->next = *head;

			//new head is the new node
			*head = newNode;

		}//if
	}//if
}//loadFront

void loadEnd(node_t* head, FILE* patients)
{
	//file input variables
	int numRead;
	int pps;
	char first[15];
	char last[15];
	int year;
	char gender;
	char email[30];
	char kinFirst[15];
	char kinLast[15];
	int appointment;
	float weight;
	float height;
	char allergies;
	int smokes;
	int alcohol;
	int exercise;

	//check number of entries
	numRead = fscanf(patients, "%d %s %s %d %c %s %s %s %d %f %f %c %d %d %d", &pps, first, last, &year, &gender, email, kinFirst, kinLast,
		&appointment, &weight, &height, &allergies, &smokes, &alcohol, &exercise);

	if (numRead == 15)
	{
		//set pointers
		node_t* temp = head;
		node_t* newNode;

		//find end of list
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		//create new node
		newNode = (struct node*)malloc(sizeof(node_t));

		//set values
		newNode->patientPPS = pps;
		strcpy(newNode->patientFirst, first);
		strcpy(newNode->patientLast, last);
		newNode->patientYear = year;
		newNode->patientGender = gender;
		strcpy(newNode->patientEmail, email);
		strcpy(newNode->nextOfKinFirst, kinFirst);
		strcpy(newNode->nextOfKinLast, kinLast);
		newNode->patientAppointment = appointment;
		newNode->patientWeight = weight;
		newNode->patientHeight = height;
		newNode->patientYear = year;
		newNode->patientAllergies = allergies;
		newNode->patientSmokes = smokes;
		newNode->patientAlcohol = alcohol;
		newNode->patientExercise = exercise;

		//new node is end of list
		newNode->next = NULL;

		//second last node points to new node
		temp->next = newNode;

	}//if
}//loadEnd