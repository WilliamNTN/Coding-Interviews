#include <iostream>
using namespace std;


typedef struct Node{
	int data;
	Node *left = NULL;
	Node *right = NULL;
	Node *parent = NULL;

	Node(){}
	Node(int d){
		data = d;
	}
}Node;


void addToTree(Node **tree, int data){

	if(*tree == NULL){
		Node *n = new Node(data);
		*tree = n;
		return;
	}

	if(data <= (*tree)->data){
		addToTree(&(*tree)->left,data);
		(*tree)->left->parent = *tree;
		return;
	}
	addToTree(&(*tree)->right,data);
	(*tree)->right->parent = *tree;
}

void printInOrder(Node *tree){
	if(tree == NULL) return;

	printInOrder(tree->left);
	cout<<tree->data<<" ";
	printInOrder(tree->right);
}

// int main(){

// 	Node *tree = NULL;

// 	addToTree(&tree,5);
// 	addToTree(&tree,3);
// 	addToTree(&tree,7);
// 	addToTree(&tree,2);
// 	addToTree(&tree,4);
// 	addToTree(&tree,6);
// 	addToTree(&tree,9);
// 	printInOrder(tree);
// }