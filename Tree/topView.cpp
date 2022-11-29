vector<int> topView(Node *root)
{
    map<int, int> mp;
    vector<int> top;
    if(root == NULL){
        return top;
    }
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(q.empty() == false){
        Node* node = q.front().first;
        int x = q.front().second;
        q.pop();
        if(mp.find(x) == mp.end()){
            mp[x] = node->data;
        }
        if(node->left){
            q.push({node->left, x-1});
        }
        if(node->right){
            q.push({node->right, x+1});
        }
    }
    for(auto it : mp){
        top.push_back(it.second);
    }
    return top;
}
