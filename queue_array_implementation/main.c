/*
 * main.c
 *
 *  Created on: May 18, 2020
 *      Author: Raafat
 */

#include "queue_array.h"

int main(void)
{
	Queue q;
	int ret;
	createQueue(&q);
	enQueue(1, &q);
	enQueue(2, &q);
	enQueue(3, &q);
	enQueue(4, &q);		/*That will overflow, as MAXQ=3*/
	deQueue(&ret, &q);
	printf("First out = %d\n", ret);
	deQueue(&ret, &q);
	printf("Second out = %d\n", ret);
	if(queueEmpty(&q))
		printf("Queue is empty\n");
	else
		printf("Queue is not empty\n");
	if(queueFull(&q))
		printf("Queue is full\n");
	else
		printf("Queue is not full\n");
	enQueue(13, &q);
	enQueue(1994, &q);
	printf("Queue Size = %d\n", queueSize(&q));
	clearQueue(&q);
	printf("After clear Queue Size = %d\n", queueSize(&q));

	return 0;
}
