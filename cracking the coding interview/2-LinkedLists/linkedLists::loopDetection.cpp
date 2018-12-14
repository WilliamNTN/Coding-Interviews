// Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop
// Example:
//	 Input: A -> B -> C -> D -> E -> C(the same C as earlier)
//	 Output: C

#include "linkedLists::template.cpp"



//Time = O(n), Space = O(1)w
Node *loopDetect(Node *a){

	if(a == NULL) return NULL;
	if(a->next == NULL) return NULL;

	Node *slow = a;
	Node *fast = a;

	slow = slow->next;
	fast = fast->next;
	if(fast->next != NULL) fast = fast->next;

	while(fast != NULL && slow != fast){
		slow = slow->next;
		fast = fast->next;
		if(fast != NULL) fast = fast->next;
	}

	if(fast == NULL) return NULL;

	fast = a;

	while(fast != slow){
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}


int main(){

	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);
	Node *d = new Node(4);
	Node *e = new Node(5);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = c;

	Node *result = loopDetect(a);
	if(result == NULL) cout<<"No loop"<<endl;
	else cout<<"Loop at: "<<result->data<<endl;
	return 0;
}