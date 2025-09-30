#include "MetricsGraph.h"
//记为有向无环图
void addArc(MetricsGraph*graph,int start,int end,int weight){
	if(start<vertexSize&&end<vertexSize){
		(*graph)[start][end] = weight;
	}else{
		printf("边插入位置越界");
	}
}

void dfs(MetricsGraph*graph,int vertex,int visited[vertexSize]){
	//邻接矩阵第vertex行，从头开始遍历
	//到达当前，即为访问到
	visited[vertex]=1;
	printf("visited :%d",vertex);
	for(int i = 0;i< vertexSize;i++){
		if(visited[i]!=1&&(*graph)[vertex][i]!=0){
			dfs(graph,i,visited);
		}
	}
}

void bfs(MetricsGraph*graph,int vertex,int visited[vertexSize]){
	for(int i = 0;i< vertexSize;i++){
		if((*graph)[vertex][i]!=0&&visited[i]==0){
			visited[i] = 1;
			printf("%d visited\n",i);
		}
	}
}

void sortList(LinkedList*queue){
	printf("\n");
	printLinkedList(queue);	
}

void createMinTreeWithPrime(MetricsGraph*graph,fun_callback sortList){
	LinkedList*list = (LinkedList*)malloc(sizeof(LinkedList));
	initLinkedList(list);
	for(int i = 0;i<vertexSize;i++){
		addToLinkedList(list,i);
	}
	sortList(list);
}

int main(){
	MetricsGraph*graph = (MetricsGraph*) malloc(sizeof(MetricsGraph));
	int start,end,weight;
	printf("输入起始顶点编号（从0开始）,输入999结束添加\n");
	scanf("%d",&start);	
	while(start!=999){
		printf("输入权重\n");
		scanf("%d",&weight);
		printf("输入终止顶点编号（从0开始）\n");
		scanf("%d",&end);
		addArc(graph,start,end,weight);
		printf("输入起始顶点编号（从0开始）,输入999结束添加\n");
		scanf("%d",&start);	
	}
	//整型数组的创建，需要注意
	int *visited=(int*)malloc(sizeof(int)*vertexSize);
	//找到一个入度为0的节点或者遍历各个节点
	for(int i = 0;i<vertexSize;i++){
		if(visited[i]!=1){
			dfs(graph,i,visited);
		}
	}
	createMinTreeWithPrime(graph,sortList);
	//	printf("bfs\n");
//	int *visited2 = (int*) malloc(sizeof(int)*vertexSize);
//	for(int i = 0;i<vertexSize;i++){
//		if(visited2[i]!=1){
//			visited2[i]= 1;
//			printf("%d visited\n",i);
//			bfs(graph,i,visited2);
//		}
//	}
	
	return 0;
}
