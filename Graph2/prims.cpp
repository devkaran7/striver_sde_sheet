int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;
        vector<int> visited(n, 0);
        while(pq.empty() == false){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node]) continue;
            visited[node] = 1;
            sum += wt;
            for(auto adjNode : adj[node]){
                if(visited[adjNode[0]]) continue;
                pq.push({adjNode[1], adjNode[0]});
            }
        }
        return sum;
    }
