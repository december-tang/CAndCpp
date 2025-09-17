#include "avlTree.h"

void initTree(Tree*tree){
	tree->root= NULL;
}

//旋转的触发条件
//左右子树高度差大于1（从上往下判断？从下往上判断?）尝试从下往上推断，因为从上到下需经更多判断
void addNodeToTree(Tree*tree,TreeNode*node){
	if(tree->root==NULL){
		tree->root = node;
	}else{
		TreeNode* tmp = tree->root;
		while(1){
			if(tmp->value<node->value){
				if(tmp->right ==NULL){
					tmp->right = node;
					node->height = tmp->height+1;
					node->parent = tmp;
					printf("add %d to right\n",node->value);
					TreeNode* unbalance;
					int balance = judgeBalance(node,&unbalance);
					if(balance==2){
						removeSubTreeFromTree(tree,unbalance);
						//left subTree
						int subBalance = depth(unbalance->left->left)-depth(unbalance->left->right);
						if(subBalance>0){
							llRotate(tree,&unbalance);
						}else{
							lrRotate(tree,&unbalance);
						}
						addNodeToTree(tree,unbalance);
						midSeek(tree->root);
					}
					else if (balance == -2){	
						removeSubTreeFromTree(tree,unbalance);
						//right subTree
						int subBalance = depth(unbalance->right->left)-depth(unbalance->right->right);
						if(subBalance>0){
							rlRotate(tree,&unbalance);
						}else{
							rrRotate(tree,&unbalance);
						}
						addNodeToTree(tree,unbalance);
						midSeek(tree->root);

					}
					break;
				}else{
					tmp = tmp ->right;
				}
			}	
			else{
				if(tmp->left == NULL){
					tmp->left = node;
					node->height = tmp->height+1;
					node->parent = tmp;
					printf("add %d to left\n",node->value);
					TreeNode* unbalance;
					int balance = judgeBalance(node,&unbalance);
					if(balance==2){
						removeSubTreeFromTree(tree,unbalance);
						//left subTree
						int subBalance = depth(unbalance->left->left)-depth(unbalance->left->right);
						if(subBalance>0){
							llRotate(tree,&unbalance);
						}else{
							lrRotate(tree,&unbalance);
						}
						addNodeToTree(tree,unbalance);
						midSeek(tree->root);
					}else if (balance == -2){
						removeSubTreeFromTree(tree,unbalance);
						//left subTree
						int subBalance = depth(unbalance->right->left)-depth(unbalance->right->right);
						if(subBalance>0){
							rlRotate(tree,&unbalance);
						}else{
							rrRotate(tree,&unbalance);
						}
						addNodeToTree(tree,unbalance);
						midSeek(tree->root);

					}
					break;
				}else{
					tmp = tmp->left;
				}
			}	
		}
	}
}

void removeSubTreeFromTree(Tree*tree,TreeNode* node){
	//the remove and add of root is important
	if(node == tree->root){
		tree->root = NULL;
	}else{
		if(node->parent->left == node){
			node->parent->left = NULL;
		}else{
			node->parent->right = NULL;
		}
	}
}


int depth(TreeNode* node){
	if(node==NULL){
		return 0;
	}else{
		int depLeft = depth(node->left);
		int depRight = depth(node->right);
		int dep= depLeft>depRight?depLeft:depRight;
		return dep+1;
	}
}

//从下往上推，判断此节点是否为受破坏节点。不是则继续向上
//判断返回值，>1 表示左侧偏高，<-1表示右侧偏高，否则没有不平衡
int judgeBalance(TreeNode*tmp,TreeNode**unbalance){
	int leftDep = depth(tmp->left);
	int rightDep = depth(tmp->right);
	int minus =  leftDep-rightDep;
	//没有不平衡，需要继续向上推断；不为根节点，可以继续向上推断
	if(minus==2){
		*unbalance = tmp;
		printf("unbalance! left tree is higher\n");
		return minus;
	}else if(minus==-2){
		*unbalance = tmp;
		printf("unbalance! right tree is higher\n");
		return minus;
	}
	else if(tmp->parent!=NULL){
		tmp = tmp->parent;
		tmp->height++;
		return judgeBalance(tmp,unbalance);
	}else{
		printf("balance till the root\n");
		return minus;
	}
}

//1.有左子树，左孙子，没有右子树
//2.有右子树，深度为1，左子树高度为3，左子树的左孩子高度为2，左子树的右孩子高度为1
void llRotate(Tree* tree,TreeNode**node){
	printf("do llRotate\n");
	if(depth(*node) ==3){
		(*node)->left->right = *node;
		*node = (*node)->left;
		(*node)->right ->left = NULL;
		
	}else if(depth(*node) == 4){
		TreeNode* tmp = (*node)->left;
		(*node)->left = tmp->right;
		tmp->right = *node;
		*node = tmp;
	}
}

void lrRotate(Tree*tree,TreeNode**node){
	printf("do lrRotate\n");
	if(depth(*node) == 3){
		//left node attached
		(*node)->left->right->left = (*node)->left;
		(*node)->left->parent = (*node)->left->right;
		
		(*node)->left = (*node)->left->right;
		(*node)->left->parent = *node;
		//rotate
		*node = (*node)->left;
		(*node)->right = (*node)->parent;
		(*node)->parent->left = NULL;
		(*node)->left->right = NULL;
	}else if (depth(*node) == 4){
		//inner lRotate
		TreeNode* sub = (*node)->left;
		(*node)->left = NULL;
		lRotate(&sub);
		(*node)->left = sub;
		sub->parent = *node;
		//outer rRotate
		if((*node)->left->right ==NULL){
			(*node)->left->right = *node;
			(*node)->parent = *node;
			*node = (*node)->left;
			(*node)->right->left = NULL;
		}else{
			(*node)->parent = (*node)->left;
			(*node)->left = (*node)->left->right;
			(*node)->left->parent = *node;
			(*node)->parent->right = *node;
			*node = (*node)->parent;
		}
	}
}

void rrRotate(Tree*tree,TreeNode**node){

	printf("do rrRotate\n");
	if(depth(*node) ==3){
		(*node)->right->left = *node;
		*node = (*node)->right;
		(*node)->left->right = NULL;
		
	}else if(depth(*node) == 4){
		TreeNode* tmp = (*node)->right;
		(*node)->right = tmp->left;
		tmp->left = *node;
		*node = tmp;
	}
}

void rlRotate(Tree*tree,TreeNode**node){
	printf("do rlRotate\n");
	if(depth(*node) == 3){
		//left node attached
		(*node)->right->left->right = (*node)->right;
		(*node)->right->parent = (*node)->right->left;
		
		(*node)->right = (*node)->right->left;
		(*node)->right->parent = *node;
		//rotate
		*node = (*node)->right;
		(*node)->left = (*node)->parent;
		(*node)->parent->right = NULL;
		(*node)->right->left = NULL;
	}else if (depth(*node) == 4){
		//inner lRotate
		TreeNode* sub = (*node)->right;
		(*node)->right = NULL;
		rRotate(&sub);
		(*node)->right = sub;
		sub->parent = *node;
		//outer rRotate
		if((*node)->right->left ==NULL){
			(*node)->right->left = *node;
			(*node)->parent = *node;
			*node = (*node)->right;
			(*node)->left->right = NULL;
		}else{
			(*node)->parent = (*node)->right;
			(*node)->right = (*node)->right->left;
			(*node)->right->parent = *node;
			(*node)->parent->left = *node;
			*node = (*node)->parent;
		}
	}
}


//root before rotate,root after rotate
void lRotate(TreeNode**node){
	//with right leaf
	if((*node)->right->left ==NULL){
		(*node)->parent = (*node)->right;
		(*node)->right->left = *node;
		(*node)->right =NULL;
		*node= (*node)->parent;
	}else{
	//with left leaf
	//save the future root as the root of current root;
		(*node)->parent = (*node)->right;
		//move the left of future root;DO ONLY WHEN future root has left leaf
		if((*node)->right->left !=NULL){
			(*node)->right = (*node)->right->left;
			(*node)->right->parent = *node;
		}
		//attach the current root to the left of future root 
		(*node)->parent->left = (*node);
		//change root
		*node = (*node)->parent;	
	}
}

void rRotate(TreeNode** node){	
	//with left leaf
	if((*node)->left->right ==NULL){
		(*node)->parent = (*node)->left;
		(*node)->left->right = *node;
		(*node)->left =NULL;
		*node= (*node)->parent;
	}else{
	//with left leaf
	//save the future root as the root of current root;
		(*node)->parent = (*node)->left;
		//move the left of future root;DO ONLY WHEN future root has left leaf
		if((*node)->left->right !=NULL){
			(*node)->left = (*node)->left->right;
			(*node)->left->parent = *node;
		}
		//attach the current root to the left of future root 
		(*node)->parent->right = (*node);
		//change root
		*node = (*node)->parent;	
	}
}

void midSeek(TreeNode*node){
	if(node!=NULL){
		printf("output:%d\n",node->value);
		midSeek(node->left);
		midSeek(node->right);
	}
}

int main(){
	Tree*tree = (Tree*)malloc(sizeof(Tree));
	int data;
	printf("输入要加入的元素,999结束\n");
	scanf("%d",&data);
	while(data!= 999){
		TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
		node->left= NULL;
		node->value = data;
		node->height = 1;
		node->right = NULL;
		node->parent= NULL;
		addNodeToTree(tree,node);
		printf("输入要加入的元素,999结束\n");
		scanf("%d",&data);
	}
	return 0;
}
