class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q;
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                q.push({i, 0});
                color[i] = 0;
                while(q.empty() == false){
                    int node = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(auto adjNode : graph[node]){
                        if(color[adjNode] == -1){
                            q.push({adjNode, !col});
                            color[adjNode] = !col;
                        }else if(color[adjNode] == col){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
