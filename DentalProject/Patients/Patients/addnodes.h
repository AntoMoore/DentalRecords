#ifndef ADD_NODE
#define ADD_NODE

//time struct
struct tm t;

//functions
void addFront(node_t** head);
void addEnd(node_t* head);
int checkPPS(node_t* head, int pps);

#endif
