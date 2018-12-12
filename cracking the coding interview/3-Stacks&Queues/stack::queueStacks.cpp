#include <iostream>
using namespace std;

typedef struct Stack{
	struct Stack *next = NULL;
	int data;

	Stack(){};

	Stack(int d){
		this->data = d;
	}

}Stack;

void push(Stack **head, int data){

	Stack *n = new Stack(data);

	if((*head) == NULL)
		*head = n;
	else{
		n->next = *head;
		(*head) = n;
	}
}

bool isEmpty(Stack *head){
	return head == NULL;
}

void pop(Stack **head){
	if(head == NULL) return;

	(*head) = (*head)->next;
}

Stack *peek(Stack **head){
	return (*head);
}


void transfer(Stack **src, Stack **dst){

	while(!isEmpty(*src)){
		push(dst,peek(src)->data);
		pop(src);
	}
}
int main(){


	Stack *insertion = NULL, *removeStack = NULL;
	char comm;
	
	cin>>comm;
	while(comm != 'e'){
		if(comm == 'p'){
			int x;
			cin>>x;
			push(&insertion,x);
		}
		else{
			if(isEmpty(removeStack))
				transfer(&insertion,&removeStack);

			cout<<peek(&removeStack)->data<<endl;
			pop(&removeStack);
		}

		cin>>comm;
	}

}