// Imagine a leteral stack of plates. If the stack gets too high,
// it might topple. Therefore, in real life, we would like to start,
// a new stack when the previous stack exceeds some threshold.
// Implement a data struct SetOfStacks that mimics this.
// SetOfStacks should be compose of several stacks and should create a new stack once the previous
// one exceeds capacity. Push and Pop should behave identically t a single stack.

#include <iostream>
using namespace std;


typedef struct Node{
	Node *next = NULL;
	int value;

	Node(){}
	Node(int d){
		value = d;
	}
}Node;

typedef struct Stack{
	Node *top = NULL;
	Stack *nextStack = NULL;
	int stackSize = 0;
}Stack;


typedef struct SetOfStacks{
	int threshold;
	Stack *topStack = NULL;

	SetOfStacks(){}

	SetOfStacks(int t){
		threshold = t;
	}
}SetOfStacks;


void pushStack(Stack *s, int val){
	Node *n = new Node(val);

	if(s->top == NULL){
		s->top = n;
	}
	else{
		n->next = s->top;
		s->top = n;
	}
	s->stackSize++;

	return;
}

void addStack(SetOfStacks *set){

	Stack *s = new Stack();
	s->nextStack = set->topStack;
	set->topStack = s;

	cout<<"Added stack"<<endl;
	return;	
}

void removeStack(SetOfStacks *set){

	Stack *s = set->topStack;
	set->topStack = s->nextStack;
	free(s);
	cout<<"Removed stack"<<endl;
	return;
}
bool isEmpty(Stack *s){
	return s->top == NULL;
}

Node* popStack(Stack *s){
	if(isEmpty(s)) return NULL;

	Node *n = s->top;
	s->top = n->next;
	return n;
}
void push(SetOfStacks *set, int val){

	if(set->topStack == NULL || set->topStack->stackSize == set->threshold){
		addStack(set);
	}
	pushStack(set->topStack,val);
	return;
}

Node* pop(SetOfStacks *set){

	if(set->topStack == NULL) return NULL;

	Node *n = popStack(set->topStack);
	if(isEmpty(set->topStack))
		removeStack(set);

	return n;
}

int main(){

	SetOfStacks *set = new SetOfStacks(3);

	push(set,1);
	push(set,2);
	push(set,3);
	push(set,4);
	push(set,5);

	pop(set);
	pop(set);

	push(set,4);

	return 0;
}