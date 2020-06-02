/*
 * queue_array.h
 *
 *  Created on: May 18, 2020
 *      Author: Raafat
 */

#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_
#include <stdio.h>
#define MAX_QUEUE 3
#define QUEUE_ENTRY int
typedef struct queue{
	int front;
	int rear;
	int size;
	QUEUE_ENTRY entry[MAX_QUEUE];
}Queue;

void createQueue(Queue *pQ);
void enQueue(QUEUE_ENTRY e, Queue *pQ);
void deQueue(QUEUE_ENTRY *pE, Queue *pQ);
int queueFull(Queue *pQ);
int queueEmpty(Queue *pQ);
void clearQueue(Queue* pQ);
int queueSize(Queue* pQ);

#endif /* QUEUE_ARRAY_H_ */
