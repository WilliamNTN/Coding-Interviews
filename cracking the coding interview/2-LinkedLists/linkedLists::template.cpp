#include <iostream>
#include <stdlib.h>
using namespace std;


typedef struct Node{
	Node *next = NULL;
	Node *before = NULL;
	int data;

	Node(){}

	Node(int d){
		data = d;
	}
}Node;


typedef struct LinkedList{
	Node *head = NULL;

	LinkedList(){}
}Class;


void appendToTail(LinkedList *list, int d){
	Node *end = new Node(d);

	if(list->head == NULL){
		list->head = end;
		return;
	}

	Node *n = list->head;
	while(n->next != NULL){
		n = n->next;
	}
	end->before = n;
	n->next = end;
}

void appendToHead(LinkedList *list, int d){

	Node *start = new Node(d);
	
	if(list->head == NULL){
		list->head = start;
		return;
	}

	Node *n = list->head;
	n->before = start;
	start->next = n;
	list->head = start;
}

void printList(LinkedList *list){

	Node *n = list->head;

	while(n != NULL){
		cout<<n->data<<endl;
		n = n->next;
	}
}

void printListInverse(LinkedList *list){
	Node *n = list->head;

	while(n->next != NULL){
		n = n->next;
	}

	while(n != NULL){
		cout<<n->data<<endl;
		n = n->before;
	}
}

void deleteNode(LinkedList *list, int d){

	if(list->head == NULL) return;

	if(list->head->data == d){
		Node *n = list->head;
		list->head = n->next;
		list->head->before = NULL;
		free(n);
	}
	Node *n = list->head;

	while(n != NULL){
		if(n->data == d){
			Node *a = n->before;
			
			a->next = n->next;
			if(n->next != NULL)
				n->next->before = a;

			free(n);

			return;
		}

		n = n->next;
	}

	return;
}

// int main(){

// 	LinkedList *list = new LinkedList();

// 	char cmm;
// 	int data;

// 	cin>>cmm>>data;
// 	while(cmm != 'q'){
// 		if(cmm == 't'){ // append tail
// 			appendToTail(list,data);
// 		}
// 		if(cmm == 'h'){ // append head
// 			appendToHead(list,data);
// 		}

// 		if(cmm == 'p'){ // print
// 			printList(list);
// 		}

// 		if(cmm == 'i'){ // print inverse
// 			printListInverse(list);
// 		}

// 		if(cmm == 'd'){ // delete
// 			deleteNode(list,data);
// 		}

// 		cin>>cmm>>data;
// 	}

// 	return 0;
// }