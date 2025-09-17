#include "LinkedQueue.h"

void initLinkedQueue(LinkedQueue*queue){
	queue->head = (QueueNode*)malloc(sizeof(QueueNode));
	queue->head->next = NULL;
	queue->tail = queue->head;
}

void pushLinkedQueue(LinkedQueue*queue,QueueElem data){
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = data;
	node->next = NULL;
	queue->tail->next = node;
	queue->tail = node;
}

void popLinkedQueue(LinkedQueue*queue,QueueElem*data){
	if(queue->tail == queue->head){
		printf("链式队列为空，无法出队");
	}else{
		*data = queue->head->next->data;
		queue->head->next = queue->head->next->next;
	}
}

void getTopOfLinkedQueue(LinkedQueue*queue,QueueElem*data){
	if(queue->tail == queue->head){
		printf("链式队列为空，无法出队");
	}else{
		*data = queue->head->next->data;
	}

}

void printLinkedQueue(LinkedQueue*queue){
	QueueNode* pointer = queue->head->next;
	while(pointer!=NULL){
		printf(" output %d \n",pointer->data);
		pointer= pointer->next;
	}
}

//int main(){
//	LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
//	initLinkedQueue(queue);
//	pushLinkedQueue(queue,3);
//	pushLinkedQueue(queue,4);
//	pushLinkedQueue(queue,5);
//	pushLinkedQueue(queue,6);
//	printLinkedQueue(queue);
//
//	QueueElem data;
//	popLinkedQueue(queue,&data);
//	printf(" poped: %d\n",data);
//
//
//	printLinkedQueue(queue);
//	return 0;
//}
