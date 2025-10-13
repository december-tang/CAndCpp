#include "TypelessLinkedList.h"

//void initLinkedList(LinkedList*queue){
//	queue->head = (ListNode*)malloc(sizeof(ListNode));
//	queue->head->next = NULL;
//	queue->tail = queue->head;
//}
//
////产生顺序值，从小到大排列
//void addToLinkedList(LinkedList*queue,QueueElem data){
//	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//	node->data = data;
//	ListNode* tmp = queue->head;
//	//从head节点开始向后对比，在当前将插入值与next的data做对比，小于则插入在当前和next之中
//	while(tmp->next!=NULL){
//		//当前指向的为小于插入值的项
//		if(tmp->next->data>=data ){
//			node->next = tmp->next;
//			tmp->next = node;
//			printf("elem %d added\n",data);
//			break;
//		}		
//		else{
//			tmp=tmp->next;
//		}	
//	}
//	//在循环中没有插入，说明比所有的都大，放到最后插入
//	if(tmp->next==NULL){
//		node->next = NULL;
//		tmp->next = node;
//		return;
//	}
//}
//
//bool removeFromLinkedList(LinkedList*queue,QueueElem data){
//	if(queue->head->next == NULL){
//		printf("链式队列为空，无法出队");
//		return FALSE;
//	}else{
//		ListNode* tmp = queue->head;
//		while(tmp->next!=NULL){
//			if(tmp->next->data!=data){
//				tmp= tmp->next;
//			}else{
//				tmp->next = tmp->next->next;
//				return TRUE;
//			}
//		}
//		printf("无法找到指定元素\n");
//		return FALSE;
//	}
//}

LinkedList* generic_list_create(int elem_size,void (*free_func)(void*)){
	LinkedList*list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;

}




void printLinkedList(LinkedList*queue){
	ListNode * tmp = queue->head;
	while(tmp->next!=NULL){
		printf("output:%d\n",tmp->next->data);
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
