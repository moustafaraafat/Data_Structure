/*
 * main.c
 *
 *  Created on: May 14, 2020
 *      Author: Raafat
 */
#include "linked_list.h"

int main()
{
	setbuf(stdout, NULL);/*To solve printing problem in Eclipse*/

	Node* list = NULL;
	linkedListMenu(&list);

	/*insertAtFirst(&list, 300);
	insertAtFirst(&list, 200);
	insertAtFirst(&list, 100);
	insertAtLast(&list, 400);
	printf("List: \n");
	printList(list);
	deleteAtFirst(&list);
	deleteAtFirst(&list);
	printf("After Del@first 2 times: \n");
	printList(list);
	deleteAtLast(&list);
	printf("After Del@last 1time: \n");
	printList(list);*/

	return 0;
}

