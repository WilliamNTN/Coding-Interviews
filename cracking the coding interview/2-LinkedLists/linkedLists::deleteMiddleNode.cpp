// Implement an algorithm to delete a node in the middle of a singly linked list, given only
// access to that node

#include "linkedLists::template.cpp"


// Time: O(n), Space: O(1)
bool deleteMiddleNode(Node* n){

	if(n == NULL || n->next == NULL) return false;

	Node *next = n->next;
	n->data = next->data;
	n->next = next->next;
	return true;
}


int main(){

	LinkedList *list = new LinkedList();

	appendToTail(list,1);
	appendToTail(list,2);
	appendToTail(list,3);
	appendToTail(list,4);
	appendToTail(list,5);

	printList(list);

	Node* n = list->head;
	n = n->next; n = n->next; // node 3;

	deleteMiddleNode(n);

	printList(list);
}