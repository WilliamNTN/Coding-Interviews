#include <iostream>
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

	Node *n = new Node(data);

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

int getKthLast(Node *head, int k){

	if(head == NULL) return -1;
	int count = 0;
	Node *n = head;
	while(n != NULL){
		n = n->next;
		count++;
	}
	int target = count - k - 1;
	if(target < 0) return -1;

											
	n = head;
	while(target > 0){
		n = n->next;
		target--;
	}
	return n->data;
}
int main(){
	int n,k,a;
	cin>>n>>k;
	Node *head = NULL;
	for(int i=0; i<n; i++){
		cin>>a;
		list_insert(&head,a);
	}

	cout<<getKthLast(head,k)<<endl;
}