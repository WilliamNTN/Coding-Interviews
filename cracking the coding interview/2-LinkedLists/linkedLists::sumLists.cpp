// You have two numbers represented by a linked list, where each node contains a single digit
// The digits are stored in reverse order, such that the 1's digit is at the head of the list
// Write a function that adds the two numbers and returns the sum as a linked list;


#include "linkedLists::template.cpp"

int getLen(Node *a){

	if(a == NULL) return 0;

	int count = 1;
	Node *n = a;

	while(n->next != NULL){
		n = n->next;
		count++;
	}

	return count;
}

//Time: O(n), Space: O(n)
Node *sumLists(Node *a,Node *b, int rem){
	
	if(a == NULL && b == NULL && rem == 0)return NULL;

	Node *result = new Node();

	int value = rem;
	if(a != NULL) value += a->data;
	if(b != NULL) value += b->data;

	result->data = value%10;
	rem = value >= 10 ? 1 : 0;

	if(a != NULL || b != NULL){
		Node *nn = sumLists(a == NULL? NULL:a->next, b == NULL? NULL:b->next, rem);
		result->next = nn;
	}

	return result;
}

// Fololow up: Suppose the digits are stored in forward order. Repeat the above problem
// Book solution

typedef struct PartialSum{
	Node *sum = NULL;
	int rem = 0;
}PartialSum;

Node *sumListsForward(Node *a, Node *b){
	int len1 = getLen(a);
	int len2 = getLen(b);

	if(len1 < len2){
		a = padList(a,len2-len1);
	}else{
		b = padList(b,len1-len2);
	}

	PartialSum *sum = addListsHelper(a,b);

	if(sum.rem == 0){
		return sum.sum;
	}else{
		Node *result = insertBefore(sum.sum, sum.rem);
		return result;
	}
}


int main(){

	LinkedList *a = new LinkedList();
	LinkedList *b = new LinkedList();

	appendToTail(a,7);
	appendToTail(a,1);
	appendToTail(a,8);
	
	appendToTail(b,5);
	appendToTail(b,9);
	appendToTail(b,2);

	LinkedList *r = new LinkedList();
	r->head = sumLists(a->head,b->head,0);
	printList(r);
}