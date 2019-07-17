#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"

void main()
{
	//files
	FILE* login;
	login = fopen("loginFile.txt", "r");

	//open patient records
	FILE* patients;
	patients = fopen("patient.txt", "r");

	//variables
	int choice;
	char ch;
	int varRead;
	int pps;
	int position;

	//initalised variables
	int isLogin = 0; //false

	//head of list
	node_t* head = NULL;

	//read login file
	if (login == NULL)
	{
		printf("\nNo LogIn File Found...\n");
	}
	else
	{
		//prompt user to enter login details
		isLogin = loginUser(login);
	}//else

	if (isLogin == 1)
	{
		//load patient report
		if (patients == NULL)
		{
			//No patient records found
			printf("\nPatient records not found!\n");
		}
		else
		{
			//load patient files
			while (!feof(patients))
			{
				//check if head pointer in null
				if (head == NULL)
				{
					//head pointer is empty (not loaded)
					loadFront(&head, patients);
				}
				else
				{
					//list already contains items
					loadEnd(head, patients);
				}
			}//while

			//close file
			fclose(patients);
		}//else

		//prompt user for inputs
		do
		{
			// === MENU === 
			printMenu();
			scanf("%d", &choice);

			if (choice == 1)
			{
				if (head == NULL)
				{
					//head pointer is empty (not loaded)
					addFront(&head);
				}
				else
				{
					//list already contains items
					addEnd(head);
				}
			}
			else if (choice == 2)
			{
				//output list
				printList(head);
			}
			else if (choice == 3)
			{
				//search
				search(head);
			}
			else if (choice == 4)
			{
				//update
				updatePatient(head);
			}
			else if (choice == 5)
			{
				//prompt user to enter pps
				printf("\nPlease enter PPS Number to Delete: ");
				scanf("%d", &pps);

				//find position in list
				position = findPosition(head, pps);
				if (position < 1 || position > Listlength(head) || position == -1)
				{
					printf("\nInvalid PPS: \n");
				}
				else if (position == 1)
				{
					deletePatientFront(&head);
					printf("\nDeleted Patient: %d \n", pps);
				}
				else
				{
					deletePatientPosition(head, position);
					printf("\nDeleted Patient: %d \n", pps);
				}
			}
			else if (choice == 6)
			{
				//patient stats
				getStatistics(head);
			}
			else if (choice == 7)
			{
				//open report 
				FILE* report;
				report = fopen("report.txt", "w");

				//Report file
				printReport(head, report);

				//close file
				fclose(report);
			}
			else if (choice == 8)
			{
				//make array and merge sort
				sortAppointments(head);
			}
			else if (choice == -1)
			{
				printf("Exit Program...");
			}
			else
			{
				printf("Invalid Option...");
			}
		} while (choice != -1);

		//on EXIT save patient details to file
		//open patient records
		FILE* patients;
		patients = fopen("patient.txt", "w");
		printFile(head, patients);

		//close files
		fclose(login);
		fclose(patients);
	}
	else
	{
		printf("\nWrong Login Details...\n");
	}
}//main