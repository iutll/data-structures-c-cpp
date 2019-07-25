#ifndef STACKS_MENU_H_
#define STACKS_MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Data_structures.h"
void stacks_menu();
void new_node_stack(Stack*,int*);
int delete_any_node_stack(Stack*,int*);
void show_stack(Stack*);
void insertion_node_stack(Stack*,int*);
void consult_stack(Stack*);
int delete_node_stack(Stack*,int*);
void dispatch_node_stack(Stack*,int*);
void liberate_stack(Stack*);
void stacks_menu(){
	Stack stack;
	stack.head=NULL;
	int size=0;
	stack.final=NULL;
	bool exit=false;
	int option;
	while(exit==false){
		system("cls");
		if(stack.head){
			printf("\t\t\t####################################\n");
			printf("\t\t\t#The current state of the Stack is:#\n");
			printf("\t\t\t####################################\n");
			show_stack(&stack);
			printf("--------------------------------------------------------------------------------");
		}
		printf("\t\tStacks:\n\t\tChosse an option:\n");
		printf("\t\t1)Create new node\n");
		printf("\t\t2)Insertion new node\n");
		printf("\t\t3)Consult node\n");
		printf("\t\t4)Delete firs node\n");
		printf("\t\t5)Delete any node\n");
		printf("\t\t6)Dispatch first node\n");
		printf("\t\t7)Liberate Stack\n");
		printf("\t\t8)Exit\n");
		printf("\t\tOption:");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1:{
				new_node_stack(&stack,&size);
				break;
			}
			case 2:{
				insertion_node_stack(&stack,&size);
				break;
			}
			case 3:{
				consult_stack(&stack);
				break;
			}
			case 4:{
				delete_node_stack(&stack,&size);
				break;
			}
			case 5:{
				delete_any_node_stack(&stack,&size);
				break;
			}
			case 6:{	
				dispatch_node_stack(&stack,&size);
				break;
			}
			case 7:{
				liberate_stack(&stack);
				printf("\t\tThe stack was liberated with rotund successful\n");
				size=0;
				break;
			}
			case 8:{
				exit=true;
				printf("\t\tLeaving the queues menu\n");
				liberate_stack(&stack);
				break;
			}
			default:{
				printf("\t\tWrong option\n");
				system("pause");
			}
		}
	}
}
void show_stack(Stack* stack){//Function for show the stack
	if(stack->head!=NULL){
		struct Node* pointer=stack->head;
		while(pointer->next){
			printf("%d-",pointer->identifier);
			pointer=pointer->next;
		}
		printf("%d\n",pointer->identifier);
	}
}
void new_node_stack(Stack* stack,int *size){//Function for create a new node in the stack
	struct Node *incoming;//New node
	incoming=(struct Node*)malloc(sizeof(struct Node));
	printf("\t\tEnter the identifier of the new node:");
	scanf("%d",&incoming->identifier);
	if(stack->head==NULL){
		stack->head=incoming;
		stack->final=incoming;
		incoming->next=NULL;
	}
	else{
		incoming->next=stack->head;
		stack->head=incoming;
	}
	printf("\t\tNode inserted with successful\n\t\t");
	size++;
	system("pause");
}
void insertion_node_stack(Stack* stack,int *size){//Function for insert a new node in the stack using an auxiliar stack
		struct Node* incoming=(struct Node*)malloc(sizeof(struct Node));
		struct Node* pointer=stack->head;
		int pos;
		Stack aux_stack;
		aux_stack.head=NULL;
		aux_stack.final=NULL;
		printf("\t\tEnter the identifier of the new node to be inserted:");
		scanf("%d",&incoming->identifier);
		printf("\t\tEnter the position where you want place it:");
		scanf("%d",&pos);
		if(stack->head==NULL){//Here the new node will be positioned at the top of the list
			printf("\t\tStack empty,Inserting the new node in the head");
			stack->head=incoming;
			incoming->next=NULL;
			stack->final=incoming;
		}
		else{
			while(pos>1&&stack->head){//saving the nodes in the auxiliary stack until finding the position for the new node
				pos--;
				pointer=stack->head;
				stack->head=stack->head->next;
				pointer->next=aux_stack.head;
				aux_stack.head=pointer;
			}
			incoming->next=stack->head;//The new node is inserted
			stack->head=incoming;
			while(aux_stack.head){//The auxliary stack is emptied 
				pointer=aux_stack.head;
				aux_stack.head=aux_stack.head->next;
				pointer->next=stack->head;
				stack->head=pointer;
			}
			printf("\t\tInsertion successful\n\t\t");
			system("pause");
		}
}
int delete_node_stack(Stack* stack,int* size){//Function for delete the firs node of the stack
	struct Node *pointer=stack->head;
	if(stack->head==NULL){
		printf("\t\tStack Empty\n\t\t");
		system("pause");
		return -1;
	}
	else{
		pointer=stack->head;
		stack->head=stack->head->next;
		free(pointer);
	}
	printf("\t\tNode eliminated with successful\n\t\t");
	system("pause");
	size--;
	return 0;
}
int delete_any_node_stack(Stack* stack,int* size){//Function to delete a node chosen by the user using a auxliary stack
	struct Node* pointer=stack->head;
	Stack aux_stack;
	aux_stack.head=NULL;
	aux_stack.final=NULL;
	int pos;
	printf("\t\tEnter the position of the node to be delete:");
	scanf("%d",&pos);
	while(pos>1&&stack->head){//The node is seached using the auxiliary stack
		pointer=stack->head;
		stack->head=stack->head->next;
		pointer->next=aux_stack.head;
		aux_stack.head=pointer;
		pos--;
	}
	pointer=stack->head;//As the pointer is empty,get the address memory of the head node
	stack->head=stack->head->next;
	free(pointer);//The pointer to be delete is released
	while(aux_stack.head){//Te auxiliary stask is emptied
		pointer=aux_stack.head;
		aux_stack.head=aux_stack.head->next;
		pointer->next=stack->head;
		stack->head=pointer;
	}
	
	printf("\t\tNode eliminated with succeful\n\t\t");
	system("pause");
}
void consult_stack(Stack* stack){//Function for consult the first node of the stack
	struct Node *pointer=stack->head;
	if(stack->head==NULL){
		printf("\t\tEmpty stack\n\t\t");
	}
	else{
		printf("\t\tHead node information:\n");
		printf("\t\tIdentifier:%d\n",stack->head->identifier);
		printf("\t\tNext:%d\n\t\t",stack->head->next);
	
	}
	system("pause");
}
void dispatch_node_stack(Stack* stack,int *size){//Function for dispactch the first node of the stack
	if(stack->head==NULL){
		printf("\t\tEmpty stack\n");
	}
	else{
		consult_stack(stack);
		delete_node_stack(stack,size);
	}
}
void liberate_stack(Stack* stack){//Function for liberate stack
	struct Node* pointer=stack->head;
	while(pointer){
		stack->head=stack->head->next;
		free(pointer);
		pointer=stack->head;
	}
}
#endif
