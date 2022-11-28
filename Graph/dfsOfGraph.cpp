class Solution {
  private:
  vector<int> result;
    void dfs(int node, vector<int> adj[], vector<int> &visited){
        result.push_back(node);
        visited[node] = 1;
        for(auto adjNode : adj[node]){
            if(visited[adjNode]) continue;
            dfs(adjNode, adj, visited);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfs(i, adj, visited);
            }
        }
        return result;
    }
};
