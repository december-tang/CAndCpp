#include "HalfSearch.h"
#define size 7

char halfSearch(int* data,int n,int request){
	int start = 0,end = n-1;
	int middle = (start+end)/2;
	while(start!=end){
		if(data[middle]>request){
			end = middle;
			middle = (start+end)/2;
		}else if(data[middle]<request){
			start = middle;
			middle = (start+end)/2;
		}else{
			printf("requested data found in arr\n");
			return 1;
		}
	}
//	if(data[middle]==request){
//		printf("requested data found\n");
//		return 1;
//	}
	return 0;
}

void addData(int*arr,int n,int index,int add){
	if(index>=n){
		printf("index out of bound error\n");
		return;
	}
	arr[index] = add;
}


int main(){
	int arr[size]={0};
	int data;
	int index;
	printf("enter a integer,end with 999\n");
	scanf("%d",&data);
	printf("add at index:\n");
	scanf("%d",&index);
	while(data!=999){
		addData(arr,size,index,data);
		printf("enter a integer,end with 999\n");
		scanf("%d",&data);
		printf("add at index:\n");
		scanf("%d",&index);
	}

	printf("enter the wanted data:\n");
	int wanted;
	scanf("%d",&wanted);
	int ret = halfSearch(arr,size,wanted);
	printf("return:%d\n",ret);
	return 0;
}
