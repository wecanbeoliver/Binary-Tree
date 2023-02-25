#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node * left;
	struct node * right;
} Node;

Node * GetNewNode(int data){
	Node * newnode = (Node *)malloc(sizeof(Node));
	newnode -> data = data;
	newnode -> left = NULL;
	newnode -> right = NULL;
	return newnode;
}

void Insert (Node ** rootPtr, int data){
	
 
	if (*rootPtr == NULL){
		*rootPtr = GetNewNode(data);
	}
	else if (data <= (*rootPtr)->data){
		Insert(&((*rootPtr)->left),data);
	}
	else {
		Insert(&((*rootPtr)->right),data);
	}
}

int x = 1; // node의 순서를 알려주기 위함
 
void preorder(Node * root){
	
	if (root == NULL){
		return;
	}
	printf("%d번째 : %d\n",x++,root->data);
	preorder(root->left);
	preorder(root->right);
}

Node * FindMin(Node * root){
	Node * current = root;
	
	while(current->left != NULL){
		current = current->left;
	}
	
	return current;
}

bool Search(Node * root, int data){
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left,data);
	else return Search(root->right,data);
} 

int max(int a, int b){
	if (a>b) return a;
	else return b;
}

int FindHeight(Node * root){
	if (root == NULL){
		return -1;
	}
	return max(FindHeight(root->left),FindHeight(root->right))+1;
}

Node * Delete(Node * root, int data){
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else
	{
		if (root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}
		else if (root->left == NULL){
			Node * temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL){
			Node * temp = root;
			root = root->left;
			free(temp);
		}
		else {
			Node * temp = FindMin(root);
			root->data = temp->data;
			root->right = Delete(root->right,data);
		}
		
	}
	return root;
}

int main(void){
	
	Node * root = NULL;
	Insert(&root,2);
	Insert(&root,1);
	Insert(&root,3);
	Insert(&root,2);
	Insert(&root,1);
	Insert(&root,3);
	Insert(&root,2);
	Insert(&root,1);
	Insert(&root,3);
	preorder(root);
	root = Delete(root,1);
	preorder(root);
	printf("%d",FindHeight(root));
	
	
	return 0;
}
