vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) {
        // Code here
        vector<int> distance(n, 1e8);
        distance[s] = 0;
        for(int j = 0; j < n-1; j++){
            for(int i = 0; i < edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(distance[u] != 1e8 && distance[u] + w < distance[v]){
                    distance[v] = distance[u] + w;
                }
            }
        }
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(distance[u] != 1e8 && distance[u] + w < distance[v]){
                vector<int> temp = {-1};
                return temp;
            }
        }
        return distance;
    }
