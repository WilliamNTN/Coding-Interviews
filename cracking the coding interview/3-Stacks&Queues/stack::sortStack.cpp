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

void sort(Stack **head){

	Stack *sorted = NULL;

	while(!isEmpty(*head)){
		Stack *temp = peek(head);
		pop(head);

		while(peek(&sorted) != NULL && peek(&sorted)->data > temp->data){
			push(head,peek(&sorted)->data);
			pop(&sorted);
		}
		push(&sorted,temp->data);
	}

	while(!isEmpty(sorted)){
		push(head,peek(&sorted)->data);
		pop(&sorted);
	}
}

int main(){

	int n;
	Stack *stack = NULL;
	cin>>n;

	for(int i=0;i<n;i++){
		int a; cin>>a;
		push(&stack,a);
	}

	sort(&stack);

	while(!isEmpty(stack)){
		cout<<peek(&stack)->data<<endl;
		pop(&stack);
	}
}