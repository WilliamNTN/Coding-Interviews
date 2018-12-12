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

void setLoop(Node **head, int index){
	Node *dst = *head;
	int c1 = 1;
	while(c1 < index){
		dst = dst->next;
		c1++;
	}

	Node *src = *head;
	while(src->next != NULL)
		src = src->next;

	src->next = dst;
}

Node *getLoop(Node *head){

	if(head == NULL) return NULL;
	if(head->next == NULL) return NULL;
	Node *fast = head;
	Node *slow = head;

	slow = slow->next;
	fast = fast->next;
	if(fast->next == NULL) return NULL;
	else fast = fast->next;

	while(slow != fast){
		slow = slow->next;
		if(slow == NULL) return NULL;

		for(int i=0;i<2; i++){
			fast = fast->next;
			if(fast == NULL) return NULL;
		}
	}

	fast = head;

	while(fast != slow){
		fast = fast->next;
		slow = slow->next;
	}


	return slow;
}

int main(){

	int n,a;
	Node *root = NULL;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		list_insert_front(&root,a);
	}

	setLoop(&root,3);
	Node *r = getLoop(root);
	if(r == NULL) cout<<"No loop detected"<<endl;
	else cout<<"Loop at value "<<r->data<<endl;	
	
	return 0;
} 