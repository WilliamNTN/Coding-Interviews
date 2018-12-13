//Write code to partition a linked list around a value x
//such that all nodes less than x come before all nodes greater than or equal to x

#include "linkedLists::template.cpp"



//Book solution
// Time: O(n), Space: O(1)
Node *partition(Node *node, int partition){

	Node *head = node;
	Node *tail = node;

	cout<<head->data<<" "<<tail->data<<" "<<endl;

	while(node != NULL){

		Node *next = node->next;

		if(node->data < partition){
			node->next = head;
			head = node;
		}
		else{
			tail->next = node;
			tail = node;
		}
		node = next;
	}

	tail->next = NULL;

	return head;
}


//First solution
// Time: O(n^2), Space: O(1)
Node *partition2(Node *head, int partition){
	if(head == NULL) return NULL;

	Node *gep = head, *sp = head;

	while(sp != NULL){
		while(gep != NULL && gep->data < partition){
			gep = gep->next;
			sp = sp->next;
		}

		while(sp != NULL && sp->data >= partition){
			sp = sp->next;
		}
		if(sp != NULL){
			gep->data += sp->data;
			sp->data = gep->data - sp->data;
			gep->data -= sp->data;

			sp = gep;
		}
	}

	return head;
}
int main(){

	LinkedList *list = new LinkedList();

	appendToTail(list,10);
	appendToTail(list,8);
	appendToTail(list,3);
	appendToTail(list,5);
	appendToTail(list,2);
	appendToTail(list,4);
	appendToTail(list,9);
	appendToTail(list,11);
	list->head = partition2(list->head,5);
	printList(list);
}