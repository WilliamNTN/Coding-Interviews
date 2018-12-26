// Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth

#include "trees&graphs::binarySearchTree.cpp"
#include <queue>
#include <cstdlib>
using namespace std;


typedef struct ListNode{
	int data;
	ListNode *next = NULL;

	ListNode(){}
	ListNode(int d){
		data = d;
	}
}ListNode;


void addToList(ListNode **list, int d){
	ListNode *n = new ListNode(d);

	if(*list == NULL){
		*list = n;
		return;
	}

	n->next = *list;
	*list = n;
	return;
}


// Little messy, isnt it?
// Time: O(n), Space: O(n)

ListNode** listOfDepths(Node *tree){	
	if(tree == NULL) return NULL;
	ListNode **result = NULL;
	int resultPointer = 0;
	ListNode *thisList = NULL;
	int actualLevel = 0;
	queue<pair<Node*,int> > q;	

	q.push(make_pair(tree,1));

	while(q.size()){
		pair<Node*,int> d = q.front(); q.pop();
		Node *n = d.first;
		int level = d.second;
		if(level != actualLevel){
			if(thisList != NULL){
				result = (ListNode**)realloc(result,sizeof(ListNode*)*(resultPointer+1));
				result[resultPointer] = (ListNode*)malloc(sizeof(ListNode));
				result[resultPointer++] = thisList;
			}
			actualLevel = level;
			thisList = NULL;
		}
		addToList(&thisList,n->data);
		if(n->left != NULL){
			q.push(make_pair(n->left,level+1));
		}
		if(n->right != NULL){
			q.push(make_pair(n->right,level+1));
		}
	}

	result = (ListNode**)realloc(result,sizeof(ListNode*)*(resultPointer+1));
	result[resultPointer] = (ListNode*)malloc(sizeof(ListNode));
	result[resultPointer++] = thisList;

	return result;
}


void printLinkedList(ListNode *list){

	ListNode *n = list;
	while(n != NULL){
		cout<<n->data<<" ";
		n = n->next;
	}
	cout<<endl;
}
int main(){

	Node *tree = NULL;
	addToTree(&tree,5);
	addToTree(&tree,3);
	addToTree(&tree,7);
	addToTree(&tree,2);
	addToTree(&tree,4);
	addToTree(&tree,6);
	addToTree(&tree,9);
	printInOrder(tree);

	ListNode **result = listOfDepths(tree);
	cout<<"Start:"<<endl;
	for(int i = 0; i < 3; i++){
		cout<<i<<": "<<endl;
		ListNode *n = result[i];
		printLinkedList(n);

	}
	return 0;
}