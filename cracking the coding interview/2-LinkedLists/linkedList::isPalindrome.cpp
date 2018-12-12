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




bool isPalindromeSingly(Node *head){ // Singly linked // Space O(n)
	// percorre até o final, botando em um vetor, e 
	// verifica se o vetor é palindromo.
}

bool isPlalindrome(Node *head){ // Space O(1)
	Node *f = head;
	Node *b = head;

	while(b->next != NULL) b = b->next;

	int ans = true;

	while(f != b){
		if(f->data != b->data) ans = false;
		f = f->next;
		b = b->before;
	}

	return ans;

}

int main(){
	int n,a;
	Node *root = NULL;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		list_insert(&root,a);
	}

	cout<<isPlalindrome(root)<<endl;
}