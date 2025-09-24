#include "Kmp.h"

void createNextArr(char* pattern ,int next[]){
	//get the length of pattern string
	int len = strlen(pattern);
	//i for arr Down pointer,j for last matched position
	int i = 0,j = -1;
	next[0]= j;
	while(i<len){
		//j always go around the header sequently,but if match failed,j goes to the shorter header end,which is next[j],
		if(j==-1||pattern[i]==pattern[j]){
			i++;j++;next[i] = j;
		}else{
			j = next[j];
		}
	}
	printf("length is %d,next Array is:\n",len);
	for(int m= 0;m<len;m++){
		printf("%d ",next[m]);
	}
}

void findMaxSubString(char* mainString,char* pattern,int next[]){
	//point to mainString,pattern
	int i = 0, j = 0;
	int mLen = strlen(mainString);
	int pLen = strlen(pattern);
	//
	while(i<mLen&&j<pLen){
		if(j==-1||mainString[i]==pattern[j]){
			i++;j++;
		}else{
			j = next[j];
		}
	}
	if(j=pLen){
		printf("匹配成功，子串在%d位置结束\n",i);
	}else{
		printf("匹配失败\n");
	}
}

int main(){
	//can not use char* to create a string ,use char array
	char pattern[50];
	int next[50];
	char mainString[100];
	printf("enter a pattern string\n");
	scanf("%s",pattern);
	printf("enter a main string\n");
	scanf("%s",mainString);

	createNextArr(pattern,next);
	findMaxSubString(mainString,pattern,next);
	return 0;
}
