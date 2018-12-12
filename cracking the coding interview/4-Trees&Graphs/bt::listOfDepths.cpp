#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node{
	int index;
	struct Node *l, *r;

	Node(){
	}
	Node(int i){
		index = i;
	}
}Node;

void insert(Node **bst, Node *n){

	if(*bst == NULL) *bst = n;
	else{
		if((*bst)->index >= n->index)
			insert((&(*bst)->l),n);
		else
			insert((&(*bst)->r),n);
	}
}

void inOrder(Node *bst){

	if(bst == NULL) return;

	inOrder(bst->l);
	cout<<bst->index<<endl;
	inOrder(bst->r);
}

vector<vector<int> > listOfDepths(Node *bt){
	vector<vector<int> > res;
 	vector<int> act;
	queue<pair<Node*,int> > q;
	q.push(make_pair(bt,0));
	int last = 0;

	while(q.size()){
		Node *t = (q.front().first);
		int d = q.front().second;
		q.pop();
		if(d != last){
			res.push_back(act);
			act.clear();
			last = d;
		}
		act.push_back(t->index);

		if(t->l != NULL) q.push(make_pair(t->l,d+1));
		if(t->r != NULL) q.push(make_pair(t->r,d+1));
	}
	res.push_back(act);
	return res;
}

int n;
int main(){
	
	cin>>n;
	Node *bt = NULL;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		Node *n = new Node(a);
		insert(&bt,n);
	}

	vector<vector<int> > result = listOfDepths(bt);

	cout<<"Depth: "<<result.size()<<endl;

	for(int i = 0; i<result.size();i++){
		for(int j = 0; j<result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}