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

void list_insert(Node **head, int data){

	Node *n = new Node(data);

	if(*head == NULL)
		*head = n;
	else{
		n->next = *head;
		(*head)->before = n;
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


Node *getIntersection(Node *headone, Node *headtwo){

	if(headone == NULL || headtwo == NULL) return NULL;

	int n = 1, m = 1;

	Node *a = headone;
	while(a->next != NULL){
		n++;
		a = a->next;
	}

	Node *b = headtwo;
	while(b->next != NULL){
		m++;
		b = b->next;
	}

	if(a != b) return NULL;

	if(n >= m){
		n = n-m;
		m = 0;
	}
	else{
		m = m-n;
		n = 0;
	}

	a = headone;
	b = headtwo;
	while(n > 0){
		n--;
		a = a->next;
	}

	while(m > 0){
		m--;
		b = b->next;
	}

	while(a != b){
		a = a->next;
		b = b->next;
	}

	return a;
}
int main(){

	Node *one = NULL, *two = NULL;
	int n,m,a;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		list_insert(&one,a);
	}

	cin>>m;
	for(int i = 0; i<m; i++){
		cin>>a;
		list_insert(&two,a);
	}

	setConnection(one,1,&two,2);
	list_print(one);
	list_print(two);
	Node *r = getIntersection(one,two);

	if(r == NULL) cout<<"No interserction found"<<endl;
	else cout<<"Intersection found at value "<<r->data<<endl;
} 