#include <iostream>
#include <stdlib.h>
#include <set>
using namespace std;

typedef struct Node{
	struct Node *next = NULL;
	int data;

	Node (){};
	Node(int d){
		data = d;
	};
}Node;

void list_insert(Node **head, int data){

	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;

	if(*head == NULL)
		*head = n;
	else{
		n->next = *head;
		*head = n;
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

int removeDuplicates(Node **head){ // O(nlogn)
	set<int> used;
	int count = 0;
	Node *a = (*head)->next;
	Node *last = *head;
	used.insert(last->data);
	while(a != NULL){
		if(used.count(a->data)>0){
			count++;
			last->next = a->next;
		}else{
			used.insert(a->data);
			last = last->next;
		}
		
		a = a->next;
	}

	return count;
}

int removeDuplicates2(Node **head){ // O(n^2)
	Node *actual = *head;
	int count = 0;
	while(actual != NULL){
		Node *a = actual->next;
		Node *last = actual;
		while(a != NULL){
			if(a->data == actual->data){
				last->next = a->next;
				count++;
			}
			else{
				last = last->next;
			}
			a = a->next;
		}
		actual = actual->next;
	}

	return count;
}
int main(){

	int n,a;
	cin>>n;
	Node *head = NULL;
	for(int i=0; i<n; i++){
		cin>>a;
		list_insert(&head,a);
	}
	list_print(head);

	removeDuplicates2(&head);
	list_print(head);
	return 0;
}