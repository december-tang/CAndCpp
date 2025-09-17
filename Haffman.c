#include "Haffman.h"

#define codeSize 100

void createHaffmanTree(LinkedList*list,HaffmanNode** root){
	while(1){
		HaffmanNode* node;
		node = (HaffmanNode*)malloc(sizeof(HaffmanNode));
		selectChildren(node,list);
		if(list->head->next==NULL){
			*root = node;
			return;
		}
		else
			addToLinkedList(list,node);
	}
}

//获取list前方两个元素，并且挂到一个新建的根上，将根加入到list中
void selectChildren(HaffmanNode* node,LinkedList*list){
	HaffmanNode* left;
	HaffmanNode* right;
	removeFromLinkedList(list,&left);
	removeFromLinkedList(list,&right);
	node->left = left;
	node->right = right;
	node->weight = left->weight+right->weight;
	printf("combined %d and %d\n",left->weight,right->weight);
}

void midSeek(HaffmanNode*node,char* str){
	HaffmanNode* tmp = node;
	if(tmp->left ==NULL&&tmp->right==NULL){
		printf("symbol:%c,weight:%d,path:%s\n",tmp->symbol,tmp->weight,str);
		return;
	}
	if(tmp->left!=NULL){
		//str是栈上内存，不需要手动释放，作用域结束会自动回收；
		char newStr[codeSize]="";
		strcpy(newStr,str);
		midSeek(tmp->left,strcat(newStr,"0"));
	}
	if(tmp->right!=NULL){
		char newStr[codeSize]="";
		strcpy(newStr,str);
		midSeek(tmp->right,strcat(newStr,"1"));
	}

}

int main(){
	printf("输入元素权重，以999结束\n");
	LinkedList*linkedList = (LinkedList*) malloc(sizeof(LinkedList));
	initLinkedList(linkedList);
	char symbol;
	printf("enter symbol\n");
	scanf(" %c",&symbol);
	printf("enter weight\n");
	int data;
	scanf("%d",&data);
	while(data!=999){
		HaffmanNode*haffNode = (HaffmanNode*)malloc(sizeof(HaffmanNode));
		haffNode->weight = data;
		haffNode->symbol = symbol;
		haffNode->left = NULL;
		haffNode->right = NULL;
		addToLinkedList(linkedList,haffNode);
		printf("enter symbol\n");
		scanf(" %c",&symbol);
		printf("enter weight\n");
		scanf("%d",&data);
	}
	printLinkedList(linkedList);
	HaffmanNode * node = (HaffmanNode*)malloc(sizeof(HaffmanNode));
	createHaffmanTree(linkedList,&node);
	char str[codeSize] = "";
	midSeek(node,str);
	return 0;
}
