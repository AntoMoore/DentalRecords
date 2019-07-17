#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filehandling.h"
#include "addnodes.h"

void addFront(node_t** head)
{
	//local variables
	char charInput;
	char strInput[30];
	int numInput;
	float floatInput;
	int day;
	int month;
	int year;
	int success = 0; //false
	int i = 0;
	time_t t_of_day;

	//set new node pointer
	node_t* newNode;

	//allocate memory for new node and set values
	newNode = (struct node*)malloc(sizeof(node_t));

	//=== set values ========
	//reset false
	success = 0;
	do
	{
		printf("\nEnter PPS: ");
		scanf("%d", &numInput);
		if ((numInput < 1000 || numInput > 10000) || (numInput == 0))
		{
			success = 0;
			printf("Incorrect Value - Enter a 4 Digit Number\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	newNode->patientPPS = numInput;

	//reset false
	success = 0;
	do
	{
		printf("\nEnter Patient First Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->patientFirst, strInput);

	success = 0; //reset
	do
	{
		printf("\nEnter Patient Last Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->patientLast, strInput);

	printf("\nEnter Year Born: ");
	scanf("%d", &newNode->patientYear);

	//reset
	success = 0;
	do
	{
		printf("\nEnter Gender (M/F): ");
		scanf(" %c", &charInput);
		if (charInput == 'm' || charInput == 'M')
		{
			success = 1;
		}
		else if (charInput == 'f' || charInput == 'F')
		{
			success = 1;
		}
		else
		{
			success = 0;
			printf("Incorrect Value - Enter 'M' or 'F'\n");
		}
	} while (success != 1);
	newNode->patientGender = charInput;

	//reset
	success = 0;
	do
	{
		printf("\nEnter Email Address: ");
		scanf("%s", strInput);
		//search through string to find @ symbol
		for (i = 0; i < strlen(strInput); i++)
		{
			charInput = strInput[i];
			if (charInput == '@')
			{
				success = 1; //true
			}
		}//for

		//check for .com
		if (strstr(strInput, ".com") == NULL)
		{
			// Invalid email
			success = 0;
			printf("Incorrect Value - Invalid Email\n");
		}

	} while (success != 1);
	strcpy(newNode->patientEmail, strInput);

	success = 0; //reset
	do
	{
		printf("\nEnter Next of Kin First Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->nextOfKinFirst, strInput);

	success = 0; //reset
	do
	{
		printf("\nEnter Next of Kin Last Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->nextOfKinLast, strInput);

	//prompt user for input
	do
	{
		printf("\nEnter Last Appointment Day (dd): ");
		scanf("%d", &day);
	} while (day < 0 && day > 31);
	
	do
	{
		printf("\nEnter Last Appointment Month (mm): ");
		scanf("%d", &month);
	} while (month < 1 && month > 12);
	
	do
	{
		printf("\nEnter Last Appointment Year (yyyy): ");
		scanf("%d", &year);
	} while (year < 1900);

	t.tm_year = (year - 1900);
	t.tm_mon = (month - 1);          
	t.tm_mday = day;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1;        // Is Day Light savings on? 1 = yes, 0 = no, -1 = unknown
	t_of_day = mktime(&t);
	newNode->patientAppointment = (int)t_of_day;

	//reset false
	success = 0;
	do
	{
		printf("\nEnter Weight: ");
		scanf("%f", &floatInput);
		if (floatInput <= 0)
		{
			success = 0;
			printf("Incorrect Value - Must be greater than zero\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	newNode->patientWeight = floatInput;

	//reset false
	success = 0;
	do
	{
		printf("\nEnter Height: ");
		scanf("%f", &floatInput);
		if (floatInput <= 0)
		{
			success = 0;
			printf("Incorrect Value - Must be greater than zero\n");

		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	newNode->patientHeight = floatInput;

	//reset
	success = 0;
	do
	{
		printf("\nEnter Enter Patient Allergies (Y/N): ");
		scanf(" %c", &charInput);
		if (charInput == 'y' || charInput == 'Y')
		{
			success = 1;
		}
		else if (charInput == 'n' || charInput == 'N')
		{
			success = 1;
		}
		else
		{
			success = 0;
			printf("Incorrect Value - Enter 'Y' or 'N'\n");

		}
	} while (success != 1);
	newNode->patientAllergies = charInput;

	success = 0; //reset
	do
	{
		printf("\nEnter Patient Smoking Habits: ");
		printf("\n- Press 1 for Non-Smoker ");
		printf("\n- Press 2 for LESS Than 10 Per Day ");
		printf("\n- Press 3 for MORE Than 10 Per Day \n");
		scanf("%d", &numInput);

		if (numInput != 1 && numInput != 2 && numInput != 3)
		{
			success = 0;
			printf("Incorrect Value - Enter between 1 - 3\n");
		}
		else
		{
			success = 1;
		}
	} while (success != 1);
	newNode->patientSmokes = numInput;

	success = 0; //reset
	do
	{
		printf("\nEnter Patient Alcohol Consumption: ");
		printf("\n- Press 1 for Non-Drinker ");
		printf("\n- Press 2 for LESS Than 10 Units Per Week ");
		printf("\n- Press 3 for MORE Than 10 Units Per Week \n");
		scanf("%d", &numInput);

		if (numInput != 1 && numInput != 2 && numInput != 3)
		{
			success = 0;
			printf("Incorrect Value - Enter between 1 - 3\n");
		}
		else
		{
			success = 1;
		}
	} while (success != 1);
	newNode->patientAlcohol = numInput;

	success = 0;
	do
	{
		printf("\nEnter Patient Exercise Routine: ");
		printf("\n- Press 1 for No Exercise ");
		printf("\n- Press 2 for LESS Than Twice Per Week ");
		printf("\n- Press 3 for MORE Than Twice Per Week \n");
		scanf("%d", &numInput);

		if (numInput != 1 && numInput != 2 && numInput != 3)
		{
			success = 0;
			printf("Incorrect Value - Enter between 1 - 3\n");
		}
		else
		{
			success = 1;
		}
	} while (success != 1);
	newNode->patientExercise = numInput;

	//next pointer is the "old" head of list
	newNode->next = *head;

	//new head is the new node
	*head = newNode;

}//addFront

void addEnd(node_t* head)
{
	//local variables
	char charInput;
	char strInput[30];
	int numInput;
	float floatInput;
	int day;
	int month;
	int year;
	int success = 0; //false
	int i = 0;
	time_t t_of_day;

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

	//=== set values ========
	//reset false
	success = 0;
	do
	{
		printf("\nEnter PPS: ");
		scanf("%d", &numInput);
		if ((numInput < 1000 || numInput > 10000) || (numInput == 0))
		{
			success = 0;
			printf("Incorrect Value - Enter a 4 Digit Number\n");
		}
		else
		{
			success = checkPPS(head, numInput);
		}

	} while (success != 1);
	newNode->patientPPS = numInput;

	//reset false
	success = 0;
	do
	{
		printf("\nEnter Patient First Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->patientFirst, strInput);

	success = 0; //reset
	do
	{
		printf("\nEnter Patient Last Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->patientLast, strInput);

	printf("\nEnter Year Born: ");
	scanf("%d", &newNode->patientYear);

	//reset
	success = 0;
	do
	{
		printf("\nEnter Gender (M/F): ");
		scanf(" %c", &charInput);
		if (charInput == 'm' || charInput == 'M')
		{
			success = 1;
		}
		else if (charInput == 'f' || charInput == 'F')
		{
			success = 1;
		}
		else
		{
			success = 0;
			printf("Incorrect Value - Enter 'M' or 'F'\n");
		}
	} while (success != 1);
	newNode->patientGender = charInput;

	//reset
	success = 0;
	do
	{
		printf("\nEnter Email Address: ");
		scanf("%s", strInput);
		//search through string to find @ symbol
		for (i = 0; i < strlen(strInput); i++)
		{
			charInput = strInput[i];
			if (charInput == '@')
			{
				success = 1; //true
			}
		}//for

		//check for .com
		if (strstr(strInput, ".com") == NULL)
		{
			// Invalid email
			success = 0;
			printf("Incorrect Value - Invalid Email\n");
		}

	} while (success != 1);
	strcpy(newNode->patientEmail, strInput);

	success = 0; //reset
	do
	{
		printf("\nEnter Next of Kin First Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->nextOfKinFirst, strInput);

	success = 0; //reset
	do
	{
		printf("\nEnter Next of Kin Last Name: ");
		scanf("%s", strInput);
		if (strlen(strInput) > 15 || strlen(strInput) < 3)
		{
			success = 0;
			printf("Incorrect Value - Must be at least 3 characters\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	strcpy(newNode->nextOfKinLast, strInput);

	//prompt user for input
	//prompt user for input
	do
	{
		printf("\nEnter Last Appointment Day (dd): ");
		scanf("%d", &day);
	} while (day < 0 || day > 31);

	do
	{
		printf("\nEnter Last Appointment Month (mm): ");
		scanf("%d", &month);
	} while (month < 1 || month > 12);

	do
	{
		printf("\nEnter Last Appointment Year (yyyy): ");
		scanf("%d", &year);
	} while (year < 1900);

	t.tm_year = (year - 1900);
	t.tm_mon = (month - 1);
	t.tm_mday = day;
	t.tm_hour = 1;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1;        // Is Day Light savings on? 1 = yes, 0 = no, -1 = unknown
	t_of_day = mktime(&t);
	newNode->patientAppointment = (int)t_of_day;

	//reset false
	success = 0;
	do
	{
		printf("\nEnter Weight: ");
		scanf("%f", &floatInput);
		if (floatInput <= 0)
		{
			success = 0;
			printf("Incorrect Value - Must be greater than zero\n");
		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	newNode->patientWeight = floatInput;

	//reset false
	success = 0;
	do
	{
		printf("\nEnter Height: ");
		scanf("%f", &floatInput);
		if (floatInput <= 0)
		{
			success = 0;
			printf("Incorrect Value - Must be greater than zero\n");

		}
		else
		{
			success = 1;
		}

	} while (success != 1);
	newNode->patientHeight = floatInput;

	//reset
	success = 0;
	do
	{
		printf("\nEnter Enter Patient Allergies (Y/N): ");
		scanf(" %c", &charInput);
		if (charInput == 'y' || charInput == 'Y')
		{
			success = 1;
		}
		else if (charInput == 'n' || charInput == 'N')
		{
			success = 1;
		}
		else
		{
			success = 0;
			printf("Incorrect Value - Enter 'Y' or 'N'\n");

		}
	} while (success != 1);
	newNode->patientAllergies = charInput;

	success = 0; //reset
	do
	{
		printf("\nEnter Patient Smoking Habits: ");
		printf("\n- Press 1 for Non-Smoker ");
		printf("\n- Press 2 for LESS Than 10 Per Day ");
		printf("\n- Press 3 for MORE Than 10 Per Day \n");
		scanf("%d", &numInput);

		if (numInput != 1 && numInput != 2 && numInput != 3)
		{
			success = 0;
			printf("Incorrect Value - Enter between 1 - 3\n");
		}
		else
		{
			success = 1;
		}
	} while (success != 1);
	newNode->patientSmokes = numInput;

	success = 0; //reset
	do
	{
		printf("\nEnter Patient Alcohol Consumption: ");
		printf("\n- Press 1 for Non-Drinker ");
		printf("\n- Press 2 for LESS Than 10 Units Per Week ");
		printf("\n- Press 3 for MORE Than 10 Units Per Week \n");
		scanf("%d", &numInput);

		if (numInput != 1 && numInput != 2 && numInput != 3)
		{
			success = 0;
			printf("Incorrect Value - Enter between 1 - 3\n");
		}
		else
		{
			success = 1;
		}
	} while (success != 1);
	newNode->patientAlcohol = numInput;

	success = 0;
	do
	{
		printf("\nEnter Patient Exercise Routine: ");
		printf("\n- Press 1 for No Exercise ");
		printf("\n- Press 2 for LESS Than Twice Per Week ");
		printf("\n- Press 3 for MORE Than Twice Per Week \n");
		scanf("%d", &numInput);

		if (numInput != 1 && numInput != 2 && numInput != 3)
		{
			success = 0;
			printf("Incorrect Value - Enter between 1 - 3\n");
		}
		else
		{
			success = 1;
		}
	} while (success != 1);
	newNode->patientExercise = numInput;

	//new node is end of list
	newNode->next = NULL;

	//second last node points to new node
	temp->next = newNode;

}//addEnd

int checkPPS(node_t* head, int pps)
{
	//local variables
	int searchNum = pps;;
	int valid = 0; //false

	//get current pointer
	node_t* current = head;

	//while current not empty
	while (current != NULL)
	{
		//check PPS number
		if (searchNum == current->patientPPS)
		{
			valid = 0; //false
			printf("Incorrect Value - PPS already in use\n");
			return valid;
		}
		else
		{
			valid = 1; //true
		}

		//next node pointer
		current = current->next;
	}//while

	return valid;

}//checkPPS


