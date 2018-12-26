// Given a directed graph, design an algorithm to find out wheter there is a route between two nodes
#include "trees&graphs::graph.cpp"
#include <queue>
#include <cstring>
using namespace std;


bool bfs(Graph *g, int source, int dest){
	if(g == NULL || g->adj == NULL) return false;
	if(source >= g->n || dest >= g->n) return false;
	if(source < 0 || dest < 0) return false;

	queue<int> q;
	q.push(source);
	bool visited[g->n];
	memset(visited,false,sizeof(visited));


	while(q.size()){
		int v = q.front(); q.pop();

		for(int i = 0; i < g->adj[v].size(); i++){
			int u = g->adj[v][i];
			if(u == dest) return true;
			if(!visited[u]){
				visited[u] = true;
				q.push(u);
			}
		}
	}

	return false;
}


int main(){

	Graph *g = new Graph(5,true);

	addEdge(g,0,1);
	addEdge(g,1,2);
	addEdge(g,1,3);
	addEdge(g,3,4);

	int a,b;
	cin>>a>>b;
	while(a != -1){
		cout<<bfs(g,a,b)<<endl;
		cin>>a>>b;		
	}
}