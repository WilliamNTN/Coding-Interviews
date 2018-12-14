// How eould you design a sdtack whicih, in addition to push and pop,
// has a function min which returns the minimum element? Push,pop and min should all operate in O(1) time.


// Both solutions have time complexity O(1) and space complexity O(n)
// The one which does not use pointers is better.
#include <iostream>
using namespace std;


typedef struct Node{
	int data;
	Node *next = NULL;
	Node *nextMin = NULL;
	int min;

	Node(){};

	Node(int d){
		data = d;
	};

}Node;


typedef struct Stack{
	Node *top = NULL;
	Node *min = NULL;
}Stack;



void pushStackPointer(Stack *s, int d){
	Node *n = new Node(d);

	if(s->top == NULL){
		s->top = n;
		s->min = n;

		return;
	}

	if(d < s->min->data){
		n->nextMin = s->min;
		s->min = n;
	}

	n->next = s->top;
	s->top = n;
}

Node* removeStackPointer(Stack *s){

	if(s->top == NULL) return NULL;

	if(s->top == s->min){
		s->min = s->min->nextMin;
	}

	Node *n = s->top;
	s->top = s->top->next;

	return n;
}


Node *getStackMinPointer(Stack *s){
	return s->min;
}



void pushStackValue(Stack *s, int d){
	Node *n = new Node(d);

	if(s->top == NULL){
		s->top = n;
		n->min = d;
		return;
	}

	n->min = min(d,s->top->min);
	n->next = s->top;
	s->top = n;
}

Node *removeStackValue(Stack *s){

	if(s->top == NULL) return NULL;

	Node *n = s->top;
	s->top = s->top->next;

	return n;
}

int getStackMinValue(Stack *s){
	if(s->top == NULL) return NULL;
	return s->top->min;
}

int main(){

	Stack *s = new Stack();

	pushStackValue(s,6);
	pushStackValue(s,2);
	pushStackValue(s,4);
	pushStackValue(s,1);

	cout<<getStackMinValue(s)<<endl;
	removeStackValue(s);
	cout<<getStackMinValue(s)<<endl;
	removeStackValue(s);
	removeStackValue(s);
	cout<<getStackMinValue(s)<<endl;

	// pushStackPointer(s,6);
	// pushStackPointer(s,2);
	// pushStackPointer(s,4);
	// pushStackPointer(s,1);

	// cout<<getStackMinPointer(s)->data<<endl;
	// removeStackPointer(s);
	// cout<<getStackMinPointer(s)->data<<endl;
	// removeStackPointer(s);
	// removeStackPointer(s);
	// cout<<getStackMinPointer(s)->data<<endl;
}