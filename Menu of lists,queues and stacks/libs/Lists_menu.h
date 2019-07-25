#ifndef LISTS_MENU_H_
#define LISTS_MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Data_structures.h"

void lists_menu();
int new_node_list(List*);//Function for create a new node
void show_list(List*);//Function for see the current state of the list
int delete_node_list(List*);//Delete a node,through of his identifier
void search_node_list(List*);//Search a node in the list
void liberate_list(List*);//Liberate the list
void lists_menu(){
	List list;//Creating a new list
	
	list.head=NULL;//Initializing the list
	list.final=NULL;
		
	bool exit=false;
	int option;
	
	while(exit==false){
		system("cls");
		printf("\t\t\t#######\n");
		printf("\t\t\t#List#\n");
		printf("\t\t\t#######\n");
		printf("--------------------------------------------------------------------------------");
		if(list.head!=NULL){//For see the current status of the list,if the list does not empty
		printf("\t\t\t############################\n");
		printf("\t\t\t#Current status of the list#\n");
		printf("\t\t\t############################\n");	
		show_list(&list);//Funcion for see the list
		printf("--------------------------------------------------------------------------------");
		}
		printf("\t\tChosse an option\n");
		printf("\t\t1)New Node\n");
		printf("\t\t2)Delete Node\n");
		printf("\t\t3)Search Node\n");
		printf("\t\t4)Liberate List\n");
		printf("\t\t5)Exit\n");
		printf("\t\tOption:");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1:{	
				new_node_list(&list);
				break;
			}
			case 2:{
				delete_node_list(&list);
				break;
			}
			case 3:
				{
				search_node_list(&list);
				break;
			}
			case 4:{
				liberate_list(&list);
				printf("\t\tThe list was liberates with rotund successful\n\t\t");
				system("pause");
				break;
			}
			case 5:{
				printf("\t\tleaving the lists menu\n");
				liberate_list(&list);
				exit=true;
				break;
			}
			default:
				printf("\t\tWrong option\n");
				system("pause");
		}
	}
}
void show_list(List* list){
		struct Node* pointer=list->head;//Create a mew pointer mode,which points to the head of the list
		while(pointer->next){//This will show the current state of the list,the pointer travels in the list,showing each nodes
			printf("%d-",pointer->identifier);
			pointer=pointer->next;
		}
		printf("%d\n",pointer->identifier);
}

int new_node_list(List *list){//Here we define the funcion for create a new node in the list,Important note:The nodes are ordered as they are created
	struct Node *pointer=list->head,*pointer_previous=list->head;//We create two pointer nodes,the fist will pointer to the head of the list,which will travels
	//In the list and The second pointer node will be the one that points to the previous node of the first pointer node declared
	struct Node *incoming=(struct Node*)malloc(sizeof(struct Node));//here we create the new node and initialize it
	if(list->head==NULL){
		printf("\t\tEmpty List\n\t\tIndicate the number of first node:");
		scanf("%d",&incoming->identifier);
		list->head=incoming;
		incoming->next=NULL;
	}
	else{	
		printf("\t\tEnter the identifier of node:");
		scanf("%d",&incoming->identifier);
		while(pointer){//While pointer have something,here will verify if the identifier of the new node is already in the list
			if(incoming->identifier==pointer->identifier){
				printf("\t\tThe identifier of the new node is already in the list\n\t\t");
				system("pause");
				return -1;
			}
			pointer=pointer->next;
		}
		pointer=list->head;//Pointer will point again at the top of the list
		if(incoming->identifier<list->head->identifier){//here it will verify if he can already position himself at the top of the list
			incoming->next=list->head;
			list->head=incoming;
		}
		else{
			while(incoming->identifier>pointer->identifier&&pointer->next!=NULL){//Here it will search where position himself in the list
				pointer=pointer->next;
			}
			if(pointer->next==NULL&&incoming->identifier>pointer->identifier){//Here he will check if he will go to the bottom of the list
				pointer->next=incoming;
				incoming->next=NULL;	
			}
			else{
				while(pointer_previous->next!=pointer){//This is a part key,Here "pointer_previous" will be positioned in the previous pointer node
					pointer_previous=pointer_previous->next;
				}
				
				pointer_previous->next=incoming;//Here is inserted the new node
				incoming->next=pointer;
			}
		}
	}
	
	printf("\t\tNode inserted in the list\n\t\t");
	system("pause");
	return 0;
}

int delete_node_list(List* list){//Function for delete any node in the list
	struct Node* pointer=list->head;
	int number;
	printf("\t\tinsert the identifier of the node to be delete:");
	scanf("%d",&number);
	if(list->head->identifier==number){//Here already check if the head node is the node to be delete
		list->head=list->head->next;
		free(pointer);
	}
	else{
		while(pointer->identifier!=number&&pointer->next!=NULL){//here we search the node to be delete
			pointer=pointer->next;
		}
		if(pointer->identifier==number){//if we already found it
			struct Node* pointer_previous=list->head;//We declare a pointer that is positioned in the previous node of the pointer node
			if(pointer->next==NULL){//Here already he verify if the head node of the list is empty
				while(pointer_previous->next!=pointer){//Here the "pointer_previous" is positioned in the previous node of the pointer node
					pointer_previous=pointer_previous->next;
				}
				free(pointer);//Here the pointer is released,the node to be eliminate :)
				pointer_previous->next=NULL;//The link are fixed
				list->final=pointer_previous;
			}
			else{//If the list is not empty
				struct Node* pointer_rear=list->head;//We declare a pointer that is positioned in the node that comes after the pointer
				while(pointer_previous->next!=pointer){//we positioned the "pointer_previous"
					pointer_previous=pointer_previous->next;
				}
				pointer_rear=pointer_previous->next->next;//The "pointer_rear" is positioned
				free(pointer);//the node to be delete is released
				pointer_previous->next=pointer_rear;//The links are normalized
			}
		}
		else{
			printf("\t\tThe node that you looking to eliminate does not exist\n\t\t");
			system("pause");
			return -1;
		}
	}
	printf("\t\tThe node was eliminated with resounding success\n\t\t");
	system("pause");
	return 0;
}
void search_node_list(List* list){//Here is defined the function for to search a node
	int number;
	struct Node* pointer=list->head;//We declarated the pointer
	printf("\t\tEnter the identifier of the node to be search:");
	scanf("%d",&number);
	while(pointer->identifier!=number&&pointer->next!=NULL){//here is searched the node
		pointer=pointer->next;
	}
	if(pointer->identifier==number){//If we found it
		printf("\t\tThe node information you are looking for is:\n");
		printf("\t\tIdentifier: %d\n",pointer->identifier);
		printf("\t\tlink: %d\n\t\t",pointer->next);
	}
	else{
		printf("\t\tThe node not exist\n\t\t");
	}
	system("pause");
}
void liberate_list(List* list){//Here is liberated the list
	struct Node *pointer=list->head;
	while(pointer){
		list->head=list->head->next;
		free(pointer);
		pointer=list->head;
	}
}
#endif
