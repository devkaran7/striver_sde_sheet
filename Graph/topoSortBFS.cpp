vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++){
            for(auto node : adj[i]){
                indeg[node]++;
            }
        }
        vector<int> result;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(q.empty() == false){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto adjNode : adj[node]){
                indeg[adjNode]--;
                if(indeg[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        return result;
	}
