// Implement a MyQueue class which implements a queue using two stacks

#include "stacks&queues::template.cpp"

typedef struct MyQueue{
	Stack *popStack = NULL;
	Stack *pushStack = NULL;

	MyQueue(){
		popStack = new Stack();
		pushStack = new Stack();
	}

}MyQueue;



void insert(MyQueue *q, int d){
	pushStack(q->pushStack,d);
}


void transfer(Stack *a, Stack *b){

	while(!isStackEmpty(a)){
		stackNode *n = popStack(a);
		pushStack(b,n->data);
	}
}
stackNode *remove(MyQueue *q){

	if(!isStackEmpty(q->popStack)){
		return popStack(q->popStack);
	}

	if(isStackEmpty(q->pushStack)) return NULL;

	transfer(q->pushStack, q->popStack);
	return popStack(q->popStack);
}

int main(){

	MyQueue *q = new MyQueue();

	insert(q,1);
	insert(q,2);
	insert(q,3);
	insert(q,4);

	cout<<remove(q)->data<<endl;

	insert(q,5);

	cout<<remove(q)->data<<endl;

}