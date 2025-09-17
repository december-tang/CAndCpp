#include <stdio.h>
#include <stdlib.h>

#define ElemType char

typedef struct TreeNode{
	struct TreeNode* left;
	ElemType data;
	struct TreeNode* right;
}Node,TreeNode;

typedef struct Tree{
	TreeNode*root;
}Tree;


void initTree(Tree*tree);

void addToTree(Tree* tree,ElemType data);

void midRootScan(Tree* tree);

void recursion(TreeNode*node);
