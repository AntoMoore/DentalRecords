#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filehandling.h"
#include "sortdate.h"

void sortAppointments(node_t* head)
{
	//local variables
	char appoint[80];
	int i = 0;
	int capacity = Listlength(head);
	int *arr = (int *)malloc(sizeof(int)*capacity);

	//get current pointer
	node_t* current = head;

	//loop through list and add dates to the array
	while (current != NULL)
	{
		//set appointment date
		arr[i] = current->patientAppointment;
		i++;

		//next node pointer
		current = current->next;

	}//while

	//print unsorted array
	for (i = 0; i < capacity; i++)
	{
		strcpy(appoint, formatTime(arr[i]));
		printf("\n Unsorted Date: %s", appoint);
	}

	//call mergeSort
	merge_sort(0, capacity - 1, arr);

	//print sorted array
	for (i = 0; i < capacity; i++)
	{
		strcpy(appoint, formatTime(arr[i]));
		printf("\n Sorted Date: %s", appoint);
	}

	//clear memory
	free(arr);

}//sortAppointments

void merge_sort(int low, int high, int a[])
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(low, mid, a);
		merge_sort(mid + 1, high, a);
		merging(low, mid, high, a);
	}
	else
	{
		return;
	}
}//merge_sort

void merging(int low, int mid, int high, int a[])
{
	int l1, l2, i;
	int* b = (int *)malloc(sizeof(int) * high);

	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
	{
		if (a[l1] <= a[l2])
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}

	while (l1 <= mid)
		b[i++] = a[l1++];

	while (l2 <= high)
		b[i++] = a[l2++];

	for (i = low; i <= high; i++)
		a[i] = b[i];

}//merging