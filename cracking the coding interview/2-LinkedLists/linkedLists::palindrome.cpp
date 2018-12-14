// Implement a function to checkif a linked list is a palindrome

#include "linkedLists::template.cpp"


void printNode(Node *d){
	while(d != NULL){
		cout<<d->data<<" ";
		d = d->next;
	}
	cout<<endl;
}

Node *addToHead(Node *head, int data){

	Node *add = new Node(data);
	if(head == NULL) head = add;
	else{
		add->next = head;
		head = add;
	}

	return head;
}


// Time: O(n), Space: O(n)
bool checkPalindrome(Node *head){
	Node *reverse = NULL;
	Node *n = head;

	while(n != NULL){
		reverse = addToHead(reverse,n->data);
		n = n->next;	
	}

	n = head;

	while(n != NULL){
		if(n->data != reverse->data) return false;
		n = n->next;
		reverse = reverse->next;
	}

	return true;
}


int main(){

	LinkedList *list = new LinkedList();

	appendToTail(list,1);
	appendToTail(list,2);
	appendToTail(list,3);
	appendToTail(list,3);
	appendToTail(list,2);
	appendToTail(list,2);

	cout<<checkPalindrome(list->head)<<endl;
}