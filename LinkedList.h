#include "QueueElem.h"
#define bool char

#define TRUE 1
#define FALSE 0
typedef struct ListNode{
	struct ListNode* next;
	QueueElem data;
}ListNode;

typedef struct List{
	ListNode* head;
	ListNode* tail;
}LinkedList;

typedef void (*fun_callback)(LinkedList*queue);

void initLinkedList(LinkedList*queue);

void addToLinkedList(LinkedList*queue,QueueElem data);

bool removeFromLinkedList(LinkedList*queue,QueueElem data);

void printLinkedList(LinkedList*queue);

