//Menu of lists,queues and stacks
//Author:N3CR0M4NC3R
#include <stdio.h>
#include <stdlib.h>
#include "libs/Lists_menu.h"
#include "libs/Queue_menu.h"
#include "libs/Stacks_menu.h"
int main(){
	int option;
	bool exit=false;
	while(exit==false){
		//Message of welcome
		system("cls");
		printf("\t\t\t#############################\n");
		printf("\t\t\t#Welcome to the dinamic club#\n");
		printf("\t\t\t#############################\n");
		printf("--------------------------------------------------------------------------------");
		printf("\t\tPlease,chosse you opcion:\n");
		printf("\t\t1)Lists\n");
		printf("\t\t2)Queues\n");
		printf("\t\t3)Stacks\n");
		printf("\t\t4)Exit\n");
		printf("--------------------------------------------------------------------------------");
		printf("\t\tOption:");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1:{
				lists_menu();
				break;
			}
			case 2:{
				queues_menu();
				break;
			}
			case 3:{
				stacks_menu();
				break;
			}
			case 4:{
				exit=true;
				printf("\t\tGood bye user,Come back then :)\n\t\t");
				system("pause");
				break;
			}
			default:{
				printf("\t\tWrong option\n\t\t");
				system("pause");
			}
		}
	}
	return 0;
}
