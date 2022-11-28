class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &color, int col){
        color[node] = col;
        for(auto adjNode : adj[node]){
            if(color[adjNode] == -1){
                if(!dfs(adjNode, adj, color, !col)) return false;
            }else if(color[adjNode] == col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(i, graph, color, 0)){
                    return false;
                }
            }
        }
        return true;
    }
};
