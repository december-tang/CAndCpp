#include <stdio.h>
#include <stdlib.h>
//外部头文件指定元素类型
#include "QueueElem.h"
//定义一个bool类型，真值为char
#define bool char
#define FALSE 0
#define TRUE 1
#define maxSize 4

typedef struct SeqQueue{
	QueueElem dataArr[maxSize];
	int tail;
	int head;
}SeqQueue;

void initSeqQueue(SeqQueue*seqQueue);


void pushSeqQueue(SeqQueue*seqQueue,QueueElem elem);

void popSeqQueue(SeqQueue*seqQueue,QueueElem*elem);

void getTop(SeqQueue*seqQueue,QueueElem*elem);

void printSeq(SeqQueue*seqQueue);
