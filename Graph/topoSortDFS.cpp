class Solution
{
    private:
    void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &result){
        visited[node] = 1;
        for(auto adjNode : adj[node]){
            if(visited[adjNode]) continue;
            dfs(adjNode, adj, visited, result);
        }
        result.push_back(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
        vector<int> result;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfs(i, adj, visited, result);
            }
        }
        reverse(result.begin(), result.end());
        return result;
	}
};
