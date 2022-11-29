vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> bfs;
        if(root == NULL) return bfs;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            int sz = q.size();
            vector<int> temp;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            bfs.push_back(temp);
        }
        return bfs;
    }
