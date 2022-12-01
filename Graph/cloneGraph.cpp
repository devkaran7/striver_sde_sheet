Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(mp.find(node) != mp.end()){
            return mp[node];
        }
        Node* newnode = new Node(node->val);
        mp[node] = newnode;
        int n = node->neighbors.size();
        for(int i = 0; i < n; i++){
            newnode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newnode;
    }
