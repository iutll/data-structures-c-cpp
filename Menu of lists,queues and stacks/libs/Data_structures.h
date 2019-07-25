#ifndef STRUCT_OF_DATES_H_
#define STRUCT_OF_DATES_H_
struct Node{
	int identifier;
	struct Node *next;
};
typedef struct{
	struct Node* head;
	struct Node* final;
}List,Queue,Stack;
#endif
