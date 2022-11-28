int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[n+1];
    vector<int> indeg(n+1, 0);
    for(auto edge : edges){
        adj[edge.first].push_back(edge.second);
        indeg[edge.second]++;
    }
    int count = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
            count++;
        }
    }
    while(q.empty() == false){
        int node = q.front();
        q.pop();
        for(auto adjNode : adj[node]){
            indeg[adjNode]--;
            if(indeg[adjNode] == 0){
                q.push(adjNode);
                count++;
            }
        }
    }
    return count != n;
}
