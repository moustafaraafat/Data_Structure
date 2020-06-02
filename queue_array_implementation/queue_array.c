/*
 * queue_array.c
 *
 *  Created on: May 18, 2020
 *      Author: Raafat
 */
#include "queue_array.h"


void createQueue(Queue *pQ)
{
	pQ->front = pQ->size = 0;
	pQ->rear = -1;
}
void enQueue(QUEUE_ENTRY e, Queue *pQ)
{
	pQ->rear = (pQ->rear + 1) % MAX_QUEUE;	/*increment first*/
	pQ->entry[pQ->rear] = e;
	pQ->size++;
}
void deQueue(QUEUE_ENTRY *pE, Queue *pQ)
{
	*pE = pQ->entry[pQ->front];	/*dequeue first*/
	pQ->front = (pQ->front + 1) % MAX_QUEUE;
	pQ->size--;
}
int queueFull(Queue *pQ)
{
	return pQ->size == MAX_QUEUE;
}
int queueEmpty(Queue *pQ)
{
	return !pQ->size;
}

int queueSize(Queue* pQ)
{
	return pQ->size;
}
void clearQueue(Queue* pQ)
{
	pQ->front = pQ->size = 0;
	pQ->rear = -1;
}

