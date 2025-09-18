#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct TreeNode{
	ElemType data;
	short leftTrace;
	short rightTrace;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
typedef struct Tree{
	TreeNode* root;
}Tree;

void initTree(Tree*tree);

void addTreeNode(Tree*tree,ElemType data);

TreeNode* TraceScan(TreeNode*tree);

TreeNode* FirstLeftNode(TreeNode*node);

void surf(Tree*tree);
