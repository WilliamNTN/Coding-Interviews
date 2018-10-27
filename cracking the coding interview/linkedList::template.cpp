#include <iostream>
using namespace std;

typedef struct Node{
	struct Node *next = NULL;
	struct Node *before = NULL;
	int data;

	Node (){};
	Node(int d){
		data = d;
	};
}Node;

void list_insert_back(Node **head, int data){

	Node *n = new Node(data);

	if(*head == NULL)
		*head = n;
	else{
		n->next = *head;
		(*head)->before = n;
		*head = n;
	}
}

void list_insert_front(Node **head, int data){
	Node *n = new Node(data);

	if(*head == NULL)
		*head = n;
	else{
		Node *a = *head;
		while(a->next != NULL)
			a = a->next;
		a->next = n;
		n->before = a;
	}
}

void list_print(Node *head){

	Node *n = head;
	while(n){
		cout<<n->data<<" ";
		n = n->next;
	}
	cout<<endl;
	return;
}

void list_print_back(Node *head){
	Node *n = head;
	while(n->next != NULL)
		n = n->next;

	while(n){
		cout<<n->data<<" ";
		n = n->before;
	}
	cout<<endl;
}

void setConnection(Node *headone, int index1, Node **headtwo, int index2){

	int c1 = 1, c2 = 1;

	Node *one = headone;
	while(c1 < index1){
		c1++;
		one = one->next;
	}

	Node *two = *headtwo;
	while(c2 < index2){
		c2++;
		two = two->next;
	}

	two->next = one;
}


int main(){

	
	return 0;
} 