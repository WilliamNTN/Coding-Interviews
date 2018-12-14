//Write a code to remove duplicates from an unsorted linked list;
//FOLLOW UP: How would you solve this problm if a temporary buffer is not allowed?

#include "linkedLists::template.cpp"
#include <set>



void deleteNodeInverse(LinkedList *list, int d){
	if(list->head == NULL) return;

	Node *n = list->head;

	while(n->next != NULL) n = n->next;

	while(n != NULL){
		if(n->data == d){

			Node *a = n->before;
			
			a->next = n->next;
			if(n->next != NULL)
				n->next->before = a;

			free(n);

			return;
		}
		n = n->before;
	}

	return;
}

// Time: O(n), Space: O(n)
// Keep the last occurrences of each unique value
void removeDuplicates(LinkedList *list){	
	set<int> present;
	Node *n = list->head;
	while(n != NULL){
		if(present.count(n->data) > 0){
			int toDelete = n->data;
			n = n->next;
			deleteNodeInverse(list,toDelete);
		}
		else{
			present.insert(n->data);
			n = n->next;
		}
	}
}


// Time: O(n^2), Space: O(1)
void removeDuplicatesNoBuffer(LinkedList *list){

	if(list->head == NULL) return;
	
	Node *reference = list->head;

	while(reference->next != NULL){

		Node *compare = reference->next;

		while(compare != NULL){
			if(compare->data == reference->data){
				Node *a = compare->before;

				a->next = compare->next;
				if(compare->next != NULL)
					compare->next->before = a;
			}
			compare = compare->next;
		}

		reference = reference->next;
	}
}
int main(){

	LinkedList *list = new LinkedList();

	appendToTail(list,1);
	appendToTail(list,2);
	appendToTail(list,3);
	appendToTail(list,1);
	appendToTail(list,4);
	appendToTail(list,5);
	appendToTail(list,4);

	printList(list);

	removeDuplicatesNoBuffer(list);
	cout<<"--"<<endl;
	printList(list);

}