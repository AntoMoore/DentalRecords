#ifndef FILE_HANDLE
#define FILE_HANDLE

//node struct
typedef struct node
{
	//node variables
	int patientPPS;
	char patientFirst[30];
	char patientLast[30];
	int patientYear;
	char patientGender;

	//pointer to next node
	struct node* next;
} node_t;

//declare functions
void loadFront(node_t** head, FILE* report);
void loadEnd(node_t* head, FILE* report);



#endif
