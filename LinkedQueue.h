#include "QueueElem.h"

typedef struct QueueNode{
	struct QueueNode* next;
	QueueElem data;
}QueueNode;

typedef struct Queue{
	QueueNode* head;
	QueueNode* tail;
}LinkedQueue;

void initLinkedQueue(LinkedQueue*queue);

void pushLinkedQueue(LinkedQueue*queue,QueueElem data);

void popLinkedQueue(LinkedQueue*queue,QueueElem*data);

void getTopOfLinkedQueue(LinkedQueue*queue,QueueElem*data);

void printLinkedQueue(LinkedQueue*queue);

