#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"
#include "menu.h"

void printMenu()
{
	printf("\n==================================================");
	printf("\n|| Please Enter 1 to Add a New Patient          ||");
	printf("\n|| Please Enter 2 to Display All Patients       ||");
	printf("\n|| Please Enter 3 to Display Individual Patient ||");
	printf("\n|| Please Enter 4 to Update Patient Details     ||");
	printf("\n|| Please Enter 5 to Delete Patient Details     ||");
	printf("\n|| Please Enter 6 to Generate Patient statistics||");
	printf("\n|| Please Enter 7 to Generate Report File       ||");
	printf("\n|| Please Enter 8 to Search by Appointment Date ||");
	printf("\n|| Please Enter -1 to Exit                      ||");
	printf("\n==================================================\n");
}//printMenu
