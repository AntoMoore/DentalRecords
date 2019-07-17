#ifndef FILE_HANDLE
#define FILE_HANDLE

//patient struct
typedef struct node
{
	//node variables
	int patientPPS;
	char patientFirst[15];
	char patientLast[15];
	int patientYear;
	char patientGender;
	char patientEmail[30];
	char nextOfKinFirst[15];
	char nextOfKinLast[15];
	int patientAppointment;
	float patientWeight;
	float patientHeight;
	char patientAllergies;
	int patientSmokes;
	int patientAlcohol;
	int patientExercise;

	//pointer to next node
	struct node* next;
} node_t;

#endif

