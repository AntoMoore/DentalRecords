#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filehandling.h"
#include "printfiles.h"

void printList(node_t* head)
{
	//get current pointer
	node_t* current = head;

	//while current not empty
	while (current != NULL)
	{
		//output current value
		printf("\nPPS: %d \nName: %s %s \nYear: %d \nGender: %c \nEmail: %s \nNext Of Kin: %s %s \nLast Appointment: %d \nWeight: %.2f \nHeight: %.2f \nAllergies: %c \nSmoking: %d \nAlcohol: %d \nExercise: %d \n", 
			current->patientPPS, current->patientFirst, current->patientLast, current->patientYear, current->patientGender, current->patientEmail, current->nextOfKinFirst, current->nextOfKinLast,
			current->patientAppointment, current->patientWeight, current->patientHeight, current->patientAllergies, current->patientSmokes, current->patientAlcohol, current->patientExercise);

		//next node pointer
		current = current->next;

	}//while
}//printList

void printFile(node_t* head, FILE* patients)
{
	//get current pointer
	node_t* current = head;

	//while current not empty
	while (current != NULL)
	{
		//output current value
		fprintf(patients, "%d %s %s %d %c %s %s %s %d %f %f %c %d %d %d\n", current->patientPPS, current->patientFirst, current->patientLast,
			current->patientYear, current->patientGender, current->patientEmail, current->nextOfKinFirst, current->nextOfKinLast,
			current->patientAppointment, current->patientWeight, current->patientHeight, current->patientAllergies, current->patientSmokes, 
			current->patientAlcohol, current->patientExercise);

		//next node pointer
		current = current->next;

	}//while
}//printFile

void printReport(node_t* head, FILE* report)
{
	//local variables
	char first[30];
	char last[30];
	char kinFirst[30];
	char kinLast[30];
	char gender[8];
	char allergy[5];
	char smoking[30];
	char alcohol[30];
	char exercise[30];
	char appointment[80];
	//get current pointer
	node_t* current = head;

	//print report header
	fprintf(report, "PPS:   Patient Name:    Year Born:   Gender:      Email Address:          Next of Kin:     Last Appointment:  Weight:  Height:  Allergies:  Smokes:         Alcohol:        Exercise: \n");
	fprintf(report, "===========================================================================================================================================================================================\n");
	//while current not empty
	while (current != NULL)
	{
		//format full name
		strcpy(first, current->patientFirst);
		strcpy(last , current->patientLast);
		strcat(first, " ");
		strcat(first, last);

		//format next of kin
		strcpy(kinFirst, current->nextOfKinFirst);
		strcpy(kinLast, current->nextOfKinLast);
		strcat(kinFirst, " ");
		strcat(kinFirst, kinLast);

		//format time/date
		strcpy(appointment, formatTime(current->patientAppointment));
		//formatTime(current->patientAppointment);


		//format gender
		if (current->patientGender == 'm' || current->patientGender == 'M')
		{
			strcpy(gender, "Male");
		}
		else if (current->patientGender == 'f' || current->patientGender == 'F')
		{
			strcpy(gender, "Female");
		}

		//format allergy
		if (current->patientAllergies == 'y' || current->patientAllergies == 'Y')
		{
			strcpy(allergy, "Yes");
		}
		else if (current->patientAllergies == 'n' || current->patientAllergies == 'N')
		{
			strcpy(allergy, "No");
		}

		//format smoking
		if (current->patientSmokes == 1)
		{
			strcpy(smoking, "None");
		}
		else if (current->patientSmokes == 2)
		{
			strcpy(smoking, "Less than ten");
		}
		else if (current->patientSmokes == 3)
		{
			strcpy(smoking, "More than ten");
		}

		//format drinking
		if (current->patientAlcohol == 1)
		{
			strcpy(alcohol, "None");
		}
		else if (current->patientAlcohol == 2)
		{
			strcpy(alcohol, "Less than ten");
		}
		else if (current->patientAlcohol == 3)
		{
			strcpy(alcohol, "More than ten");
		}

		//format exercise
		if (current->patientExercise == 1)
		{
			strcpy(exercise, "Never");
		}
		else if (current->patientExercise == 2)
		{
			strcpy(exercise, "Less than twice");
		}
		else if (current->patientExercise == 3)
		{
			strcpy(exercise, "More than twice");
		}
		

		//output current value
		fprintf(report, "%-6d %-16s %-12d %-12s %-23s %-16s %-18s %-8.2f %-8.2f %-11s %-15s %-15s %-15s\n", 
			current->patientPPS, first, current->patientYear, gender, current->patientEmail, kinFirst,
			appointment, current->patientWeight, current->patientHeight, allergy, smoking, alcohol, exercise);

		//next node pointer
		current = current->next;

	}//while

	//footer
	fprintf(report, "===========================================================================================================================================================================================\n");
}//printReport


const char* formatTime(int epoch)
{
	//local variables
	time_t     now;
	struct tm  ts;
	char       buf[80];

	// Get time
	now = epoch;
	ctime(&now);

	// Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
	ts = *localtime(&now);
	strftime(buf, sizeof(buf), "%a %Y-%m-%d", &ts);
	return buf;
}//formatTime


