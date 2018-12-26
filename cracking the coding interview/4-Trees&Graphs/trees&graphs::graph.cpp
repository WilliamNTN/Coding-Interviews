#include <iostream>
#include <vector>
using namespace std;

// Adj list implementation
typedef struct Graph{
	int n; // number of vertices
	vector<int>* adj; // pointer to adj

	bool directed;

	Graph(){}
	Graph(int v, bool direct){
		n = v;
		adj = new vector<int>[v];
		directed = direct;
	}


}Graph;

void addEdge(Graph *g, int source, int dest){

	if(g == NULL) return;
	if(source >= g->n || dest >= g->n) return;
	if(g->adj == NULL) return;

	g->adj[source].push_back(dest);
	if(!(g->directed))
		g->adj[dest].push_back(source);
}

void printGraph(Graph *g){

	for(int i = 0; i < g->n; i++){
		cout<<"Adjs of "<<i<<": ";
		for(int j = 0; j < g->adj[i].size(); j++){
			cout<<g->adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

// int main(){

// 	Graph *g = new Graph(3,true);

// 	addEdge(g,0,1);
// 	addEdge(g,0,2);
// 	addEdge(g,1,0);
// 	addEdge(g,1,2);
// 	addEdge(g,2,0);
// 	addEdge(g,2,1);

// 	printGraph(g);
// 	return 0;
// }