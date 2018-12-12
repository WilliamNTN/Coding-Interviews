#include <iostream>
using namespace std;

typedef struct Stack{
	struct Stack *next = NULL;
	int data;
	int min;
	Stack(){};

	Stack(int d){
		this->data = d;
		this->min = d;
	}

}Stack;

void push(Stack **head, int data){

	Stack *n = new Stack(data);
	if((*head) == NULL)
		*head = n;
	else{
		n->min = min(n->min,(*head)->min);
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

int stackMin(Stack *head){
	return head->min;
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
		cout<<stackMin(stack)<<endl;
		pop(&stack);
	}

	return 0;
}