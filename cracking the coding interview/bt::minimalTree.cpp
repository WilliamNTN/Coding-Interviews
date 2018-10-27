#include <iostream>
using namespace std;

const int maxN = 101234;
int vals[maxN];

typedef struct Node{
	int index;
	struct Node *l, *r;

	Node(){
	}
	Node(int i){
		index = i;
	}
}Node;

void insert(Node **bst, Node *n){

	if(*bst == NULL) *bst = n;
	else{
		if((*bst)->index >= n->index)
			insert((&(*bst)->l),n);
		else
			insert((&(*bst)->r),n);
	}
}

void inOrder(Node *bst){

	if(bst == NULL) return;

	inOrder(bst->l);
	cout<<bst->index<<endl;
	inOrder(bst->r);
}

int main(){
	int n;
	cin>>n;

	Node *bst = NULL;
	for(int i = 0; i<n; i++)
		cin>>vals[i];

	int index = (n+1)/2;
	while(index >= 0){
		Node *n = new Node(vals[index]);
		insert(&bst,n);
		index--;
	}
	index = (n+1)/2;
	index++;
	while(index < n){
		Node *n = new Node(vals[index]);
		insert(&bst,n);
		index++;
	}

	inOrder(bst);

}