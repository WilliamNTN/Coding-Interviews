//write a algorithm to find the "next" (in order) node
//of a given node in a binary search tree.

#include "trees&graphs::binarySearchTree.cpp"
using namespace std;




// Time: O(n), Space: O(1)

int successor(Node *n){
	if(n == NULL) return -0x3f3f3f3f; // Fail code

	if(n->right != NULL){
		Node *v = n->right;
		while(v->left != NULL)
			v = v->left;

		return v->data;
	}

	Node *v = n->parent;
	while(v->parent != NULL && v->data < n->data){
		v = v->parent;
	}
	if(v->data < n->data) return -0x3f3f3f3f;
	return v->data;
}

Node *getNode(Node *tree, int d){
	if(tree == NULL) return NULL;

	Node *n = tree;
	while(n != NULL && n->data != d){
		if(n->data <= d)
			n = n->right;
		else
			n = n->left;
		cout<<n->data<<endl;
	}

	if(n != NULL) return n;
	return NULL;
}

int main(){

	Node *tree = NULL;

	addToTree(&tree,5);
	addToTree(&tree,3);
	addToTree(&tree,8);
	addToTree(&tree,2);
	addToTree(&tree,4);
	addToTree(&tree,7);
	addToTree(&tree,9);
	addToTree(&tree,1);
	addToTree(&tree,6);
	addToTree(&tree,10);
	printInOrder(tree);
	cout<<endl<<"Start"<<endl;
	int search;
	cin>>search;
	while(search != -1){
		Node *n = getNode(tree,search);
		cout<<"Result for "<<n->data<<": ";
		int t = successor(n);
		cout<<t<<endl;
		cin>>search;
	}
}
