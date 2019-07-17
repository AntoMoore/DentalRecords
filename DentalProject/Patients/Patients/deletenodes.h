#ifndef DELETE_NODES
#define DELETE_NODES

int Listlength(node_t* head);
int findPosition(node_t* head, int pps);
void deletePatientFront(node_t** head);
void deletePatientPosition(node_t* head, int pos);

#endif