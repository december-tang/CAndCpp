#include "SeqQueue.h"

void initSeqQueue(SeqQueue*seqQueue){
	seqQueue->head = 0;
	seqQueue->tail = 0;
}

//如果队列满（即tail
void pushSeqQueue(SeqQueue*seqQueue,QueueElem elem){
	if(((seqQueue->tail+maxSize) - seqQueue->head)%maxSize==(maxSize-1)){
		printf("队列已满，无法入队");
	}
	else{
		seqQueue->dataArr[(seqQueue->tail++)%(maxSize)] = elem;
		
	}
}

void popSeqQueue(SeqQueue*seqQueue,QueueElem*elem){
	if(seqQueue->tail==seqQueue->head){
		printf("队列已空，无法出队\n");
	}else{
		*elem = seqQueue->dataArr[seqQueue->head];
		seqQueue->head = (seqQueue->head+maxSize+1)%(maxSize);
	}
}	

void getTop(SeqQueue*seqQueue,QueueElem*elem){
	if(seqQueue->tail==seqQueue->head){
		printf("队列已空,无元素\n");
	}else{
		*elem = seqQueue->dataArr[seqQueue->head];
	}
}

void printQueue(SeqQueue*seqQueue){
	printf("开始打印");
	if(seqQueue->head<seqQueue->tail){
		for(int i = seqQueue->head;i<seqQueue->tail;i++){
			printf("%d\n",seqQueue->dataArr[i]);
		}
	}else if(seqQueue->head==seqQueue->tail){
		printf("队列为空");
	}else{
		int i = seqQueue->head;
		while(i!=seqQueue->tail){
			printf("%d\n",seqQueue->dataArr[i]);
			i = (i+1)%maxSize;
		}

	}
}

//int main(){
//	SeqQueue*seqQueue = (SeqQueue*)malloc(sizeof(SeqQueue));
//	initSeqQueue(seqQueue);
//	pushSeqQueue(seqQueue,6);
//	pushSeqQueue(seqQueue,7);
//
//	pushSeqQueue(seqQueue,8);
//	pushSeqQueue(seqQueue,9);
//
//	printQueue(seqQueue);
//	QueueElem data;
//	popSeqQueue(seqQueue,&data);
//	printf("%d\n\n",data);
//	pushSeqQueue(seqQueue,9);
//	printQueue(seqQueue);
//	free(seqQueue);
//	return 0;
//}
