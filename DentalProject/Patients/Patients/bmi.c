#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"
#include "bmi.h"

void getStatistics(node_t* head)
{
	//local variables
	int input;
	int critera;
	float bmi;
	float aCount = 0;
	float bCount = 0;
	float cCount = 0;
	float dCount = 0;
	char percent = '%';

	//call ListLenght function for total patients
	int totalCount = Listlength(head);
	int found = 0; //false

	//get current pointer
	node_t* current = head;

	//prompt user
	printf("\nEnter 1 - Statistics On Smokers ");
	printf("\nEnter 2 - Statistics On Exercise \n");
	scanf("%d", &input);

	if (input == 1)
	{
		printf("\nEnter Patient Smoking Habits: ");
		printf("\n- Press 1 for Non-Smoker ");
		printf("\n- Press 2 for LESS Than 10 Per Day ");
		printf("\n- Press 3 for MORE Than 10 Per Day \n");
		scanf("%d", &critera);

		//while current not empty
		while (current != NULL)
		{
			//check for smokers
			if (critera == current->patientSmokes)
			{
				//get BMI
				bmi = calculateBmi(current->patientWeight, current->patientHeight);

				if (bmi < 18.5)
				{
					aCount++;
				}
				else if (bmi < 25 && bmi >= 18.5)
				{
					bCount++;
				}
				else if (bmi < 30 && bmi >= 25)
				{
					cCount++;
				}
				else if (bmi >= 30)
				{
					dCount++;
				}
				
			}//if

			//next node pointer
			current = current->next;

		}//while

		//print stats
		printf("\n  **** BMI Statistics **** ");
		printf("\n A - Less Than 18.5: %.2f%c", (aCount / totalCount) * 100, percent);
		printf("\n B - Less Than 25: %.2f%c", (bCount / totalCount) * 100, percent);
		printf("\n C - Less Than 30: %.2f%c", (cCount / totalCount) * 100, percent);
		printf("\n D - Greather Than 30: %.2f%c ", (dCount / totalCount) * 100, percent);
		printf("\n  ******   SMOKING  ****** \n");
		
	}
	else if (input == 2)
	{
		printf("\nEnter Patient Exercise Routine: ");
		printf("\n- Press 1 for No Exercise ");
		printf("\n- Press 2 for LESS Than Twice Per Week ");
		printf("\n- Press 3 for MORE Than Twice Per Week \n");
		scanf("%d", &critera);

		//while current not empty
		while (current != NULL)
		{
			//check for Exercise
			if (critera == current->patientExercise)
			{
				//get BMI
				bmi = calculateBmi(current->patientWeight, current->patientHeight);

				if (bmi < 18.5)
				{
					aCount++;
				}
				else if (bmi < 25)
				{
					bCount++;
				}
				else if (bmi < 30)
				{
					cCount++;
				}
				else if (bmi > 30)
				{
					dCount++;
				}

			}//if

			//next node pointer
			current = current->next;

		}//while

		//print stats
		printf("\n  **** BMI Statistics **** ");
		printf("\n A - Less Than 18.5: %.2f%c", (aCount / totalCount) * 100, percent);
		printf("\n B - Less Than 25: %.2f%c", (bCount / totalCount) * 100, percent);
		printf("\n C - Less Than 30: %.2f%c", (cCount / totalCount) * 100, percent);
		printf("\n D - Greather Than 30: %.2f%c ", (dCount / totalCount) * 100, percent);
		printf("\n  ******   EXERCISE  ****** \n");

	}//else
}//getStatistics

float calculateBmi(float weight, float height)
{
	//local variables
	float myBmi;

	//get Bmi
	myBmi = weight / (height * height);
	return myBmi;

}//calculateBmi
