vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<int> result;
        queue<int> q;
        vector<int> visited(n, 0);
        visited[0] = 1;
        q.push(0);
        while(q.empty() == false){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto adjNode : adj[node]){
                if(visited[adjNode]) continue;
                visited[adjNode] = 1;
                q.push(adjNode);
            }
        }
        return result;
    }
