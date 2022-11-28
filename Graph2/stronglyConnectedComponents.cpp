void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &component){
    visited[node] = 1;
    component.push_back(node);
    for(auto adjNode : adj[node]){
        if(visited[adjNode]) continue;
        dfs(adjNode, adj, visited, component);
    }
}

void topodfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto adjNode : adj[node]){
        if(!visited[adjNode]){
            topodfs(adjNode, adj, visited, st);
        }
    }
    st.push(node);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    vector<int> trans[n];
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        trans[edge[1]].push_back(edge[0]);
    }
    stack<int> st;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            topodfs(i, adj, visited, st);
        }
    }
    fill(visited.begin(), visited.end(), 0);
    vector<vector<int>> scc;
    while(st.empty() == false){
        int node = st.top();
        st.pop();
        if(visited[node]) continue;
        vector<int> component;
        dfs(node, trans, visited, component);
        scc.push_back(component);
    }
    return scc;
}
