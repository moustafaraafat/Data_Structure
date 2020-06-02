/*
 * linked_list.c
 *
 *  Created on: May 14, 2020
 *      Author: Raafat
 */

#include "circular_linked_list.h"

void createFirstNode(Node** pLast, uint32 data)
{
	/*1- Create the node*/
	*pLast = (Node*)malloc(1*sizeof(Node));
	/*2- Save the coming data to the newNode*/
	(*pLast)->data = data;
	/*3- Make it point to itself*/
	(*pLast)->next = (*pLast);

}

void insertAtFirst(Node** pLast, uint32 data)
{
	if (*pLast == NULL){
		createFirstNode(pLast, data);
		return;
	}
	/*1- Create the node*/
	Node* newNode = (Node*)malloc(1*sizeof(Node));
	/*2- Save the coming data to the newNode*/
	newNode->data = data;
	/*3- */
	newNode->next = (*pLast)->next;
	/*4-*/
	(*pLast)->next = newNode;
}
void insertAtLast(Node** pLast, uint32 data)
{
	if (*pLast == NULL){
		createFirstNode(pLast, data);
		return;
	}
	/*1- Create the node*/
	Node* newNode = (Node*)malloc(1*sizeof(Node));
	/*2- Save the coming data to the newNode*/
	newNode->data = data;
	/*3- */
	newNode->next = (*pLast)->next;
	/*4-*/
	(*pLast)->next = newNode;
	*pLast = newNode;

}
void deleteAtFirst(Node** pLast)
{
	Node* delNode = (*pLast)->next;
	if(*pLast == NULL){
		printf("\nList is empty to delete a node!\n");
		return;
	}
	else if((*pLast)->next == *pLast){  /*one node handling*/
		free(*pLast);
		*pLast = NULL;
	}
	else{
		(*pLast)->next = (*pLast)->next->next;
		free(delNode);
	}
}
void deleteAtLast(Node** pLast)
{

	Node* currentNode = (*pLast)->next;
	if(*pLast == NULL){
		printf("\nList is empty to delete a node!\n");
		return;
	}
	else if((*pLast)->next == *pLast){  /*one node handling*/
		free(*pLast);
		*pLast = NULL;
	}
	else{
		while(currentNode->next != *pLast){
			currentNode = currentNode->next;
		}
		currentNode->next = currentNode->next->next;
		free(*pLast);  /*Free up the old last node*/
		*pLast = currentNode;	/*Make a new last*/
	}
}
void printList(Node* last)
{
	Node* currentNode =last;
	uint32 nodeIndex = 1;
	if(last == NULL){
		printf("\nList is empty!\n");
		return ;
	}
	else{
		do{
			currentNode = currentNode->next;
			printf("N%d: %d\n", nodeIndex, currentNode->data);
			nodeIndex++;
		}while(currentNode != last);
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
