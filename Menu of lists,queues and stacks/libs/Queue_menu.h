#ifndef QUEUES_MENU_H_
#define QUEUES_MENU_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Data_structures.h"
void queues_menu();
void show_queue(Queue*);
void new_node_queue(Queue*,int*);
void insert_node_queue(Queue*,int*);
int consult_node_queue(Queue*);
int delete_node_queue(Queue*,int*);
int dispatch_node_queue(Queue*,int*);
void liberate_queue(Queue*);
void delete_any_node_queue(Queue*,int*);
void queues_menu(){
	int size=0;
	Queue queue;
	queue.head=NULL;
	queue.final=NULL;
	bool exit=false;
	int option;
	while(exit==false){
		system("cls");
		printf("\t\t\t########\n");
		printf("\t\t\t#Queue:#\n");
		printf("\t\t\t########\n");
		printf("--------------------------------------------------------------------------------");
		if(queue.head){
			printf("\t\t\t#####################################\n");
			printf("\t\t\t#The current state of the queue is::#\n");
			printf("\t\t\t#####################################\n");
			show_queue(&queue);
			printf("--------------------------------------------------------------------------------");
		}
		
		printf("\t\tchosse an option:\n");
		printf("\t\t1)New node\n");
		printf("\t\t2)Insertion\n");
		printf("\t\t3)Consult\n");
		printf("\t\t4)Delete\n");
		printf("\t\t5)Delete any\n");
		printf("\t\t6)Dispatch\n");
		printf("\t\t7)Liberate\n");
		printf("\t\t8)Exit\n");
		printf("\t\tOption:");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1:{
				new_node_queue(&queue,&size);
				break;
			}
			case 2:{
				insert_node_queue(&queue,&size);
				break;
			}
			case 3:{
				consult_node_queue(&queue);
				break;
			}
			case 4:{
				delete_node_queue(&queue,&size);
				break;
			}
			case 5:{
				delete_any_node_queue(&queue,&size);
				break;
			}
			case 6:{
				dispatch_node_queue(&queue,&size);
				break;
			}
			case 7:{
				liberate_queue(&queue);
				printf("\t\t\tThe queue was liberated with rotund successful\n\t\t");
				system("pause");
				size=0;
				break;
			}
			case 8:{
				printf("\t\tLeaving the queue menu\n");
				liberate_queue(&queue);
				size=0;
				exit=true;
				break;
			}
			default:
				printf("\t\tWrong option\n");
				system("pause");
		}
	}
	system("pause");
}
void new_node_queue(Queue* queue,int *size){//Function for create a new node in the queue
	struct Node* incoming;
	incoming=(struct Node*)malloc(sizeof(struct Node));//New node
	printf("\t\tEnter the identifier of the new node:");
	scanf("%d",&incoming->identifier);
	if(queue->head==NULL){//Is introduced in the top of the queue,as the stack is empty
		queue->head=incoming;
		incoming->next=NULL;
		queue->final=incoming;
	}
	else{//Is introduced in the bottom of the queue
		incoming->next=NULL;
		queue->final->next=incoming;
		queue->final=incoming;
	}
	(*size)++;
	printf("\t\tNode create succefully\n");
	system("pause");
}
int consult_node_queue(Queue* queue){//function for consult the first node of the queue
	if(queue->head==NULL){
		printf("\t\tQueue empty\n");
		system("pause");
		return -1;
	}
	else{
		printf("\t\tNode information:\n");
		printf("\t\tIdentifier: %d\n",queue->head->identifier);
		printf("\t\tNext: %d\n",queue->head->next);
	}
	system("pause");
	return 0;
}
void show_queue(Queue* queue){//function for show all nodes of te queue
	if(queue->head!=NULL){
		struct Node* pointer=queue->head;
		while(pointer->next){
			printf("%d-",pointer->identifier);
			pointer=pointer->next;
		}
		printf("%d\n",pointer->identifier);
	}
}
void insert_node_queue(Queue* queue,int *size){//function for insert a node chosen by the user
	struct Node* incoming;//New node
	struct Node* pointer=queue->head;//Pointer node
	int i=0;
	int position;
	incoming=(struct Node*)malloc(sizeof(struct Node));
	printf("\t\tEnter the identifier of the new node:");
	scanf("%d",&incoming->identifier);
	printf("\t\tEnter the position of the insertion the new node:");
	scanf("%d",&position);
	printf("\t\tThe size of the queue is:%d\n",*size);
	if(position<0){
		printf("\t\tNo exist negatives position neither neutrals\n");
	}
	else if(queue->head==NULL){//This part is dificcult for understand,but basically,I made an insertion of a node without using an auxiliary queue and without breaking the rules of the queue
		queue->head=incoming;
		incoming->next=NULL;
		queue->head=queue->final;
	}
	else{
		for(i=1;i<=(*size)+1;i++){
			if(i==position){
				queue->final->next=incoming;
				queue->final=incoming;
				incoming->next=NULL;
			}
			else{
				pointer=queue->head;
				queue->head=queue->head->next;
				queue->final->next=pointer;
				pointer->next=NULL;
				queue->final=pointer;
			}	
		}
	}
	printf("\t\tInsertion realizate with successful\n\t\t");
	(*size)++;
	system("pause");
}
int delete_node_queue(Queue* queue,int *size){//function for Delete the first node in the queue;
	struct Node* pointer=queue->head;
	if(queue->head==NULL){
		printf("\t\tQueue empty\n\t\t");
		system("pause");
		return -1;
	}
	else{
		queue->head=queue->head->next;
		free(pointer);
	}
	(*size)--;
	printf("\t\tNode eliminated with successful\n\t\t");
	system("pause");
	return 0;
}
int dispatch_node_queue(Queue* queue,int *size){//function for dispatch the first node in the queue
	if(queue->head==NULL){
		printf("\t\tQueue empty\n\t\t");
		system("pause");
		return -1;
	}
	else{
		consult_node_queue(queue);
		delete_node_queue(queue,size);
	}
	(*size)--;
}
void liberate_queue(Queue* queue){//Function for liberate the queue
	struct Node *pointer=queue->head;
	while(pointer){
		queue->head=queue->head->next;
		free(pointer);
		pointer=queue->head;
	}
}
void delete_any_node_queue(Queue* queue,int *size){//Function for delete a node chosen by the user,using the same algorithm for the insertion function
	int position,i;
	struct Node* pointer;
	if(queue->head==NULL){
		printf("\t\tQueue empty\n\t\t");
	}
	else{
		printf("\t\tEnter the identifier of the new node:");
		scanf("%d",&position);
		if(position<=0){
			printf("\t\tNo exist negative position neither neutrals\n");
		}
		else{
			for(i=1;i<=(*size);i++){
				if(i==position){
					pointer=queue->head;
					queue->head=queue->head->next;
					free(pointer);
				}
				else{
					pointer=queue->head;
					queue->head=queue->head->next;
					pointer->next=NULL;
					queue->final->next=pointer;
					queue->final=pointer;
				}
			}
		}
		(*size)--;
		printf("\t\tNode eliminated with successful\n\t\t");
	}
	system("pause");
}
#endif
