string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> visited(n+1, 0);
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        q.push({i, 0});
        while(q.empty() == false){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode : adj[node]){
                if(adjNode == parent) continue;
                if(visited[adjNode]) return "Yes";
                visited[adjNode] = 1;
                q.push({adjNode, node});
            }
        }
    }
    return "No";
}
