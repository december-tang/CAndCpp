#include <stdio.h>
#include <stdlib.h>

#define bool char
#define TRUE 1
#define FALSE 0

typedef struct TreeNode{
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* parent;
	int height;
	int value;
}TreeNode;

typedef struct Tree{
	TreeNode* root;
}Tree;


void initTree(Tree*tree);

int depth(TreeNode*node);

void addNodeToTree(Tree*tree,TreeNode* node);

void llRotate(Tree*tree,TreeNode**node);

void lrRotate(Tree*tree,TreeNode**node);

void rlRotate(Tree*tree,TreeNode**node);

void rrRotate(Tree*tree,TreeNode**node);

void midSeek(TreeNode*node);

int judgeBalance(TreeNode*node,TreeNode**unbalance);

void removeSubTreeFromTree(Tree*tree,TreeNode* node);

void lRotate(TreeNode**node);

void rRotate(TreeNode**node);
