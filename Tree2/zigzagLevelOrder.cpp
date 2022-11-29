vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(root == NULL){
            return zigzag;
        }
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(q.empty() == false){
            int k = q.size();
            vector<int> temp;
            for(int i = 0; i < k; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                temp.push_back(node->val);
            }
            if(flag){
                reverse(temp.begin(), temp.end());
            }
            zigzag.push_back(temp);
            flag = flag ^ 1;
        }
        return zigzag;
    }
