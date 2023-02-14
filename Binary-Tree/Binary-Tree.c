#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * create(){
	int x;
	struct node * newnode;
	
	newnode = (struct node *)malloc(sizeof(struct node));
	
	printf("enter data (-1 for no data)");
	scanf("%d",&x);
	
	if (x==-1){
		return 0;
	}
	
	newnode->data = x;
	
	printf("enter the left child of %d",x);
	newnode->left = create();
	
	printf("enter the right child of %d",x);
	newnode->right = create();
	
	return newnode;
}


void preorder(struct node * root){
	
	
	if (root == 0){
		return;
	}
	printf("%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
	

}

int main(void){
	
	struct node * root;
	root = create();
	preorder(root);
}
