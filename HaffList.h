#include <stdio.h>
#include <stdlib.h>

#define bool char

#define TRUE 1
#define FALSE 0

typedef struct HaffmanNode{
        struct HaffmanNode* left;
        struct HaffmanNode* right;
	char symbol;
        int weight;
}HaffmanNode,HaffmanTree;

typedef struct ListNode{
	struct ListNode* next;
	HaffmanNode*data;
}ListNode;

typedef struct List{
	ListNode* head;
	ListNode* tail;
}LinkedList;

void initLinkedList(LinkedList*queue);

void addToLinkedList(LinkedList*queue,HaffmanNode* data);

bool removeFromLinkedList(LinkedList*queue,HaffmanNode**data);

void printLinkedList(LinkedList*queue);

