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

void pop(Stack **head){
	if(head == NULL) return;

	(*head) = (*head)->next;
}

Stack *peek(Stack **head){
	return (*head);
}

bool isEmpty(Stack *head){
	return head == NULL;
}

int main(){

	int n;
	cin>>n;
	Stack *stack = NULL;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		push(&stack,x);
	}

	while(!isEmpty(stack)){
		cout<<peek(&stack)->data<<endl;
		pop(&stack);
	}

	return 0;
}