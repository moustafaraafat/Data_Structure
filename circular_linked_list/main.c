/*
 * main.c
 *
 *  Created on: May 14, 2020
 *      Author: Raafat
 */
#include "circular_linked_list.h"

int main()
{
	setbuf(stdout, NULL);/*To solve printing problem in Eclipse*/

	Node* list = NULL;  /*Creation of a linked list*/
	linkedListMenu(&list);

	return 0;
}

