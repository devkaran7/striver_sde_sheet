vector <int> bottomView(Node *root) {
    map<int, int> mp;
    vector<int> bottom;
    if(root == NULL) return bottom;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(q.empty() == false){
        Node* node = q.front().first;
        int x = q.front().second;
        q.pop();
        mp[x] = node->data;
        if(node->left){
            q.push({node->left, x-1});
        }
        if(node->right){
            q.push({node->right, x+1});
        }
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}
