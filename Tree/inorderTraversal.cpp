vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        if(root == NULL){
            return order;
        }
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            while(node != NULL){
                st.push(node);
                node = node->left;
            }
            if(st.empty()){
                break;
            }
            node = st.top();
            st.pop();
            order.push_back(node->val);
            node = node->right;
        }
        return order;
    }
