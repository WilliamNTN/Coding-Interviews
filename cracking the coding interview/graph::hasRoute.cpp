#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int maxN = 101234;
vector<int> graph[maxN];


bool bfs(int s, int d){

	queue<int> q;
	set<int> visited;

	visited.insert(s);
	q.push(s);

	while(q.size()){
		int u = q.front(); q.pop();

		for(int i = 0; i<graph[u].size(); i++){
			int v = graph[u][i];
			if(v == d) return true;
			if(visited.count(v) == 0){
				visited.insert(v);
				q.push(v);
			}
		}
	}

	return false;
}
int main(){
	int n,m,a,b;

	cin>>n>>m>>a>>b;
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		
		graph[u].push_back(v);
	}

	if(bfs(a,b)) cout<<"yes"<<endl;
	else 		 cout<<"no"<<endl;

}