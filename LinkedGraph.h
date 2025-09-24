#include <stdio.h>
#include <stdlib.h>

#define vertexSize 6

typedef struct VexNode{
	int symbol;
	struct ArcNode* firstArc;
}VexList[vertexSize];

typedef struct ArcNode{
	int weight;
	int nextVexSeq;
	struct ArcNode* nextArc;
}ArcNode;


