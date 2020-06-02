/*
 * linked_list.h
 *
 *  Created on: May 14, 2020
 *      Author: Raafat
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

typedef struct node{
	uint32 data;
	struct node *next;
}Node;

void insertAtFirst(Node** pStart, uint32 data);
void insertAtLast(Node** pStart, uint32 data);
void deleteAtFirst(Node** pStart);
void deleteAtLast(Node** pStart);
void printList(Node* start);
void linkedListMenu(Node** pStart);



#endif /* LINKED_LIST_H_ */
