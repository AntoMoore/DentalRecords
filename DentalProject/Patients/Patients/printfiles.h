#ifndef PRINT_FILE
#define PRINT_FILE

//time struct
struct tm ts;

void printList(node_t* head);
void printFile(node_t* head, FILE* patients);
void printReport(node_t* head, FILE* report);
const char* formatTime(int epoch);

#endif
