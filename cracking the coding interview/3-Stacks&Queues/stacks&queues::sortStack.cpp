// Write a program to sort a stack such that the smallest items are on the top.
// You can use an additional temporary stack, but you may not copy the elements
// into any other data structure.


#include "stacks&queues::template.cpp"

Stack* sortStack(Stack *s){
	if(s == NULL) return NULL;

	Stack *aux = new Stack();

	while(!isStackEmpty(s)){
		stackNode *n = popStack(s);
		while(!isStackEmpty(aux) && peekStack(aux)->data > n->data){
			stackNode *m = popStack(aux);
			pushStack(s,m->data);
		}
		pushStack(aux,n->data);
	}
	
	while(!isStackEmpty(aux)){
		stackNode *m = popStack(aux);
		pushStack(s,m->data);
	}		

	return s;
}


void printStack(Stack *s){

	while(!isStackEmpty(s)){
		stackNode *n = popStack(s);
		cout<<n->data<<endl;
	}
}

int main(){

	Stack *s = new Stack();

	pushStack(s,6);
	pushStack(s,4);
	pushStack(s,2);
	pushStack(s,3);
	pushStack(s,5);
	pushStack(s,1);
	s = sortStack(s);
	printStack(s);	
}