#include "traceBTree.h"

void initTree(Tree* tree){
	tree->root = NULL;
}

void addTreeNode(Tree*tree,int data){
	if (tree->root == NULL){
		TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
		node->data = data;
		tree->root = node;
		return;
	}
	TreeNode* tmp = tree->root;
	while(tmp != NULL){
		if(tmp->data>data){
			if(tmp->left == NULL){	
				TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
				node->data = data;
				tmp->left = node;
				tmp->leftTrace = 0;
				return;
			}else{
				tmp = tmp->left;
			}
		}else if(tmp->data <data){	
			if(tmp->right == NULL){	
				TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
				node->data = data;
				tmp->right = node;
				tmp->rightTrace = 0;
				return;
			}else{
				tmp = tmp->right;
			}
		}else{
			printf("same value,ignore!\n");
		}
	}
}
TreeNode* FirstLeftNode(TreeNode* node){
	TreeNode* tmp = node;
	while(tmp->left!=NULL){
		tmp = tmp->left;
	}
	return tmp;

}

TreeNode* TraceScan(TreeNode*node){
	//has left child
	if(node->left!=NULL&&node->leftTrace ==0){
		TreeNode* front = TraceScan(node->left);
		printf("add trace from %d to %d\n",front->data,node->data);
		front->right = node;
		front->rightTrace = 1;
	}
	// a mid scan will not return a left tree as 
	printf("node:%d\n",node->data);
	//has right child
	if(node->right != NULL&&node->rightTrace ==0){
		if(node->right->left !=NULL){
			TreeNode* rightLeftNode = FirstLeftNode(node->right);
			rightLeftNode->left = node;
			rightLeftNode->leftTrace = 1;
			printf("add reverse trace from %d to %d\n",rightLeftNode->data,node->data);
		}
		return TraceScan(node->right);
//		TreeNode* next = TraceScan(node->right);
//		next->left = node;
//		next->leftLeaf = 1;
	}

	if(node->right ==NULL){
		return node;	
	}
}

void surf(Tree*tree){
	//整棵树的最左子树,先找到左子树再操作。
	TreeNode* tmp = FirstLeftNode(tree->root);
	while(tmp->right !=NULL){
		printf("surf:%d\n",tmp->data);
		if(tmp->rightTrace == 1){
			tmp = tmp->right;	
		}else{
			tmp = FirstLeftNode(tmp->right);
		}
	}
	
}

int main(){
	ElemType data ;
	Tree* tree = (Tree*) malloc(sizeof(Tree));
	printf("enter number;end with 999\n");
	scanf("%d",&data);
	while(data!=999){
		addTreeNode(tree,data);
		printf("enter number;end with 999\n");
		scanf("%d",&data);
	}
	TraceScan(tree->root);

	return 0;
}


