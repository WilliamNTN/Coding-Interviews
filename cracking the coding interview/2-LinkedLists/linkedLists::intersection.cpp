
// Given two singly linked lists, determine if the two lists intersect.
// Return the intersction node. Note that the intersection is defined based on referece,
// not value.
#include "linkedLists::template.cpp"


int getLen(Node *a){

	if(a == NULL) return 0;
	Node *n = a;
	int count = 1;

	while(n->next != NULL){
		count++;
		n = n->next;
	}

	return count;
}



// Time: O(n), Space: O(1)
Node *intersection(Node *a, Node *b){
	if(a == NULL || b == NULL) return NULL;

	int len1 = getLen(a);
	int len2 = getLen(b);

	Node *g = len1 >= len2 ? a : b;
	Node *s = len1 >= len2 ? b : a;

	int diff = abs(len1-len2);

	while(diff > 0){
		diff--;
		g = g->next;
	}

	while(g != NULL){
		if(g == s) return g;
		g = g->next;
		s = s->next;
	}

	return NULL;
}


int main(){

	Node *s = new Node(0);
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);
	Node *d = new Node(4);
	Node *e = new Node(5);

	s->next = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	Node *na = new Node(-1);
	Node *nb = new Node(-2);
	Node *nc = new Node(-3);

	nc->next = nb;
	nb->next = na;
	na->next = a;

	Node *result = intersection(s,nc);
	if(result == NULL) cout<<"Fail"<<endl;
	else cout<<"Dat: "<<result->data<<endl;
}