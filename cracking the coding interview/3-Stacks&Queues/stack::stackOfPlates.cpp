#include <iostream>
using namespace std;


typedef struct Node{
	struct Node *next = NULL;
	int data;

	Node(){};
	Node(int d){
		this->data = d;
	}

}Node;

typedef struct Stack{
	struct Stack *next = NULL;
	Node *nodes = NULL;
	int nNodes;
}Stack;


void push_node(Stack **stack, int data){
	Node *n = new Node(data);
	if((*stack)->nodes == NULL){
		(*stack)->nodes = n;
	}
	else{
		n->next = (*stack)->nodes;
		(*stack)->nodes = n;
	}

	(*stack)->nNodes++;
}

void push(Stack **stack, int data, int stackCapacity){


	if((*stack)->nNodes == stackCapacity){
		Stack *ns = new Stack();
		ns->next = *stack;
		*stack = ns;
		cout<<"Create new Stack"<<endl;
	}

	push_node(stack, data);
}




int main(){
	int stackCapacity;
	cin>>stackCapacity;

	int n;
	cin>>n;
	Stack *stacks = new Stack();
	for(int i=0;i<n;i++){
		int x; cin>>x;
		push(&stacks,x,stackCapacity);
	}

}