bool rec(int node, vector<int> adj[], vector<int> &visited){
    visited[node] = 1;
    for(auto adjNode : adj[node]){
        if(visited[adjNode] == 0){
            if(rec(adjNode, adj, visited)){
                return true;
            }
        }else if(visited[adjNode] == 1){
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[n+1];
    for(auto edge : edges){
        adj[edge.first].push_back(edge.second);
    }
    vector<int> visited(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        if(rec(i, adj, visited)){
            return true;
        }
    }
    return false;
}
