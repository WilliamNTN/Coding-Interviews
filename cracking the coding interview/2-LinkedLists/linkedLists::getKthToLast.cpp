
// Implement an algorithm to find the kth to last element of a singly linked list

#include "linkedLists::template.cpp"



// Time: O(n), Space: O(1)
Node* getKthLast(LinkedList *list, int kth){

	if(list->head == NULL) return NULL;

	int count = 0;
	Node *n = list->head;

	while(n != NULL){
		count++;
		n = n->next;
	}

	cout<<"Count: "<<count<<endl;
	int target = count-kth;

	count = 1;
	n = list->head;

	if(target < count) return NULL;
	while(count < target){
		n = n->next;
		count++;
	}

	return n;
}


int main(){

	LinkedList *list = new LinkedList();

	appendToTail(list,1);
	appendToTail(list,2);
	appendToTail(list,3);
	appendToTail(list,4);
	appendToTail(list,5);

	Node *n = getKthLast(list,0);
	if(n != NULL)
		cout<<"Return: "<<n->data<<endl;
	else
		cout<<"Fail"<<endl;

	return 0;
}