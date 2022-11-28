bool rec(int node, int par, vector<int> adj[], vector<int> &visited){
    visited[node] = 1;
    for(auto adjNode : adj[node]){
        if(adjNode == par) continue;
        if(visited[adjNode]) return true;
        if(rec(adjNode, node, adj, visited)){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> visited(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        if(rec(i, 0, adj, visited)){
            return "Yes";
        }
    }
    return "No";
}
