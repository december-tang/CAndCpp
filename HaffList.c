#include "HaffList.h"

void initLinkedList(LinkedList*queue){
	queue->head = (ListNode*)malloc(sizeof(ListNode));
	queue->head->next = NULL;
	queue->tail = queue->head;
}

//产生顺序值，从小到大排列
void addToLinkedList(LinkedList*queue,HaffmanNode* haffNode){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = haffNode;
	ListNode* tmp = queue->head;
	//从head节点开始向后对比，在当前将插入值与next的data做对比，小于则插入在当前和next之中
	while(tmp->next!=NULL){
		//当前指向的为小于插入值的项
		if(tmp->next->data->weight>=haffNode->weight){
			node->next = tmp->next;
			tmp->next = node;
			printf("elem %d added\n",haffNode->weight);
			break;
		}		
		else{
			tmp=tmp->next;
		}	
	}
	//在循环中没有插入，说明比所有的都大，放到最后插入
	if(tmp->next==NULL){
		node->next = NULL;
		tmp->next = node;
		return;
	}
}

bool removeFromLinkedList(LinkedList*queue,HaffmanNode**data){
	if(queue->head->next == NULL){
		printf("链式队列为空，无法出队");
		return FALSE;
	}else{
		ListNode* tmp = queue->head;
		if(tmp->next!=NULL){
			*data = tmp->next->data;
			tmp->next = tmp->next->next;
			return TRUE;
		}
		printf("无法找到指定元素\n");
		return FALSE;
	}
}


void printLinkedList(LinkedList*queue){
	ListNode * tmp = queue->head;
	while(tmp->next!=NULL){
		printf("output:%d\n",tmp->next->data->weight);
		tmp = tmp->next;
	}
}
//int main(){
//	LinkedList* queue = (LinkedList*)malloc(sizeof(LinkedList));
//	initLinkedList(queue);
//	addToLinkedList(queue,7);
//	addToLinkedList(queue,4);
//	addToLinkedList(queue,5);
//	addToLinkedList(queue,6);
//	
//
//	QueueElem data = 4;
//	bool poped = removeFromLinkedList(queue,data);
//	if(poped==1){
//	printf(" poped: %d\n",data);
//	}else{
//		printf("pop failed\n");
//	}
//
//	return 0;
//}
