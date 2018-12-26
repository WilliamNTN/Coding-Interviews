//Implement a function to check if a binary treeis balanced. (Max 1 difference from both sub-trees of any node)

#include "trees&graphs::binarySearchTree.cpp"



// Works, with poor time complexity
int getLevel(Node *n){
	if(n == NULL) return -1;

	int leftLevel = getLevel(n->left);
	int rightLevel = getLevel(n->right);

	return max(leftLevel,rightLevel)+1;
}
bool checkBalanced(Node *tree){

	if(tree == NULL) return true;

	int diff = abs(getLevel(tree->left) - getLevel(tree->right));
	if(diff >= 2) return false;

	return checkBalanced(tree->left) && checkBalanced(tree->right);
}


// -0x3f3f3f3f == error, not balanced
// Good compelxity
// Time: O(n), Space O(n)
int getLevelGood(Node *tree){

	if(tree == NULL) return -1;

	int leftLevel = getLevelGood(tree->left);
	int rightLevel = getLevelGood(tree->right);

	if(leftLevel == -0x3f3f3f3f || rightLevel == -0x3f3f3f3f) return -0x3f3f3f3f;

	int diff = abs(leftLevel - rightLevel);
	if(diff >= 2) return -0x3f3f3f3f;

	return max(leftLevel,rightLevel)+1;
}

bool checkBalancedGood(Node *tree){
	int res = getLevelGood(tree);
	if(res == -0x3f3f3f3f) return false;
						   return true; 
}
int main(){

	Node *tree = NULL;
	addToTree(&tree,5);
	addToTree(&tree,3);
	addToTree(&tree,7);
	addToTree(&tree,2);
	addToTree(&tree,4);
	addToTree(&tree,6);
	addToTree(&tree,8);
	addToTree(&tree,9);
	addToTree(&tree,10);
	printInOrder(tree);
	cout<<endl;
	cout<<"Balanced?: "<<checkBalancedGood(tree)<<endl;

	return 0;
}