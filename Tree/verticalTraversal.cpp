vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<int>> mp;
    vector<vector<int>> vert;
    if(root == NULL) return vert;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int y = 0;
    while(q.empty() == false){
        int sz = q.size();
        map<int, vector<int>> temp;
        while(sz--){
            TreeNode * node = q.front().first;
            int x = q.front().second;
            q.pop();
            temp[x].push_back(node->val);
            if(node->left){
                q.push({node->left, x-1});
            }
            if(node->right){
                q.push({node->right, x+1});
            }
        }
        for(auto &it : temp){
            sort(it.second.begin(), it.second.end());
            for(auto &jt : it.second){
                mp[it.first].push_back(jt);
            }
        }
        y++;
    }
    for(auto &it : mp){
        vert.push_back(it.second);   
    }
    return vert;
}
