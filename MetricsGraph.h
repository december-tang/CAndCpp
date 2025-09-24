#include <stdio.h>
#include <stdlib.h>
#define vertexSize 10

//定义邻接矩阵，vertexSize为顶点个数，1为有边，0为无边。无向图一定沿y=x对称，有向图不一定。
typedef int MetricsGraph[vertexSize][vertexSize];


