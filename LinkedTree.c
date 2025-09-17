#include "LinkedTree.h"

void initTree(Tree*tree){
	tree->root = NULL;
}

void addToTree(Tree*tree,ElemType data){
	TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	if(tree->root==NULL){
		tree->root = node;
	}else{
		TreeNode* target = tree->root;
		while(1){
			if(data<=target->data){
				if(target->left ==NULL){
					target->left = node;
					printf("add to left\n");
					break;
				}else{
					target= target->left;
				}
			}else{
				if(target->right == NULL){
					target->right = node;
					printf("add to right\n");
					break;
				}else{
					target = target->right;
				}
			}
		}
	}
}


void midRootScan(Tree*tree){
	if(tree->root==NULL){
		printf("树为空\n");
	}else{
		recursion(tree->root);
	}
}


void recursion(TreeNode*node){
	if(node!=NULL){
		printf("output %d\n",node->data);
		recursion(node->left);
		recursion(node->right);
	}
}


//int main(){
//	Tree*tree = (Tree*)malloc(sizeof(Tree));
//	initTree(tree);
//	addToTree(tree,3);
//	addToTree(tree,7);
//	addToTree(tree,5);
//	addToTree(tree,1);
//
//	midRootScan(tree);
//	return 0;
//}
