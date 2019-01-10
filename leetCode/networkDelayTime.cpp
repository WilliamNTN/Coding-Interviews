//There are N network nodes, labelled 1 to N.
//Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node
//v is the target node, and w is the time it takes for a signal to travel from source to target.

//Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal?
//If it is impossible, return -1. 


class Solution {
public:
    vector<int> dijkstra(vector<pair<int,int>> graph[101], int start, int n){
        vector<int> dist(n+1,0x3f3f3f3f);
        dist[start] = 0;
        priority_queue<pair<int,int>>pq;
        pq.push(make_pair(0,start));
        
        while(pq.size()){
            pair<int,int> top = pq.top(); pq.pop();
            int u = top.second, d = top.first;
            
            if(d > dist[u]) continue;
            
            for(int j = 0; j < graph[u].size(); j++){
                int v =  graph[u][j].first;
                int w = graph[u][j].second;
                
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        
        return dist;    
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<pair<int,int> > graph[N+1];
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            
            graph[u].push_back(make_pair(v,w));
        }
        
        cout<<"Graph:"<<endl;
        for(int i = 1; i <=N; i++){
            cout<<i<<": ";
            for(int j = 0; j < graph[i].size(); j++){
                cout<<graph[i][j].first<<" ";
            }
            cout<<endl;
        }
        
        vector<int> distances = dijkstra(graph,K,N);
        int ans = -1;
        
        for(int i = 1; i <= N; i++){
            ans = max(ans,distances[i]);
            cout<<"Dist for "<<i<<" : "<<distances[i]<<endl;
        }
        if(ans == 0x3f3f3f3f) return -1;
        return ans;
    }
};