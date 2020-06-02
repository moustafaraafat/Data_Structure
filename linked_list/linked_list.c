/*
 * linked_list.c
 *
 *  Created on: May 14, 2020
 *      Author: Raafat
 */

#include "linked_list.h"

void insertAtFirst(Node** pStart, uint32 data)
{
	/*1- Create the node*/
	Node* newNode = (Node*)malloc(1*sizeof(Node));
	/*2- Save the coming data to the newNode*/
	newNode->data = data;
	/*3- */
	newNode->next = (*pStart);
	/*4-*/
	(*pStart) = newNode;
}
void insertAtLast(Node** pStart, uint32 data)
{
	Node* last = (*pStart);
	/*1- Create the node*/
	Node* newNode = (Node*)malloc(1*sizeof(Node));
	/*2- Save the coming data to the newNode*/
	newNode->data = data;
	/*3- */
	newNode->next = NULL;
	/*4-*/
	if(*pStart == NULL){
		*pStart = newNode;
	}
	else{
		while(last->next != NULL){
			last = last->next;
		}
		last->next = newNode;
	}

}
void deleteAtFirst(Node** pStart)
{
	Node* delNode = *pStart;
	if(*pStart == NULL){
		printf("\nList is empty to delete a node!\n");
	}
	else{
		(*pStart) = (*pStart)->next;
		free(delNode);
	}
}
void deleteAtLast(Node** pStart)
{
	Node *last = (*pStart), *preLast = (*pStart);
	if(*pStart == NULL){
		printf("\nList is empty to delete a node!\n");
	}
	else if((*pStart)->next == NULL){
		free((*pStart));
		(*pStart) = NULL;
	}
	else{
		while(last->next != NULL){
			preLast = last;
			last = last->next;
		}
		preLast->next = NULL;
		free(last);
	}
}
void printList(Node* start)
{
	Node* currentNode = start;
	uint32 nodeIndex = 1;
	if(start == NULL){
		printf("\nList is empty!\n");
	}
	else{
		while(currentNode != NULL){
			printf("N%d: %d\n", nodeIndex, currentNode->data);
			nodeIndex++;
			currentNode = currentNode->next;
		}
	}
}
void linkedListMenu(Node** pStart)
{
	int choice = 0, data = 0;
	printf("1. Insert at first.\n");
	printf("2. Insert at last.\n");
	printf("3. Delete from first.\n");
	printf("4. Delete from last.\n");
	printf("5. Print list.\n");
	printf("6. Exit.\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf(" %d", &choice);
		switch(choice)
		{
		case 1:
			printf("Enter data to be inserted at first\n");
			scanf(" %d", &data);
			insertAtFirst(pStart, data);
			break;
		case 2:
			printf("Enter data to be inserted at last\n");
			scanf(" %d", &data);
			insertAtLast(pStart, data);
			break;
		case 3:
			printf("This will delete the node at first\n");
			deleteAtFirst(pStart);
			break;
		case 4:
			printf("This will delete the node at last\n");
			deleteAtLast(pStart);
			break;
		case 5:
			printList(*pStart);
			break;
		case 6:
			return;
		default:
			printf("Invalid choice\n");
			break;
		}
	}

}
