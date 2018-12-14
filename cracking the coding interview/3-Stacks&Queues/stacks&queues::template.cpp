#include <iostream>
using namespace std;


typedef struct stackNode{
	int data;
	stackNode *next = NULL;

	stackNode(){}

	stackNode(int d){
		data = d;
	}
}stackNode;

typedef struct queueNode{
	int data;
	queueNode *next = NULL;

	queueNode(){}

	queueNode(int d){
		data = d;
	}
}queueNode;

typedef struct Stack{
	stackNode *top = NULL;
}Stack;

typedef struct Queue{
	queueNode *front = NULL;
	queueNode *last = NULL;
}Queue;

void pushStack(Stack *s, int d){
	stackNode *n = new stackNode(d);

	if(s->top == NULL){
		s->top = n;
		return;
	}

	n->next = s->top;
	s->top = n;
	return; 
}

stackNode* popStack(Stack *s){

	if(s->top == NULL) return NULL;

	stackNode *n = s->top;
	s->top = s->top->next;
	return n;
}

stackNode *peekStack(Stack *s){
	if(s->top == NULL) return NULL;
	return s->top;
}

bool isStackEmpty(Stack *s){
	return s->top == NULL;
}


void insertQueue(Queue *q, int d){
	queueNode *n = new queueNode(d);

	if(q->last == NULL){
		q->last = n;
		q->front = n;
		return;
	}

	q->last->next = n;
	q->last = n;

	return;
}


queueNode *removeQueue(Queue *q){
	if(q->front == NULL) return NULL;

	queueNode *n = q->front;
	q->front = q->front->next;
	return n;
}

queueNode *peekQueue(Queue *q){
	return q->front;
}

bool isQueueEmpty(Queue *q){
	return q->front == NULL;
}


// int main(){

// 	cout<<"Test stack"<<endl;
// 	Stack *s = new Stack();
// 	pushStack(s,1);
// 	pushStack(s,2);
// 	pushStack(s,3);

// 	cout<<peekStack(s)->data<<endl;
// 	popStack(s);
// 	cout<<peekStack(s)->data<<endl;

// 	cout<<"Test queue"<<endl;
// 	Queue *q = new Queue();
// 	insertQueue(q,1);
// 	insertQueue(q,2);
// 	insertQueue(q,3);

// 	cout<<peekQueue(q)->data<<endl;
// 	removeQueue(q);
// 	cout<<peekQueue(q)->data<<endl;

// }