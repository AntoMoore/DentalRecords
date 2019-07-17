#ifndef FILE_LOADING
#define FILE_LOADING

//declare functions
int loginUser(FILE* login);
void loadFront(node_t** head, FILE* patients);
void loadEnd(node_t* head, FILE* patients);

#endif
