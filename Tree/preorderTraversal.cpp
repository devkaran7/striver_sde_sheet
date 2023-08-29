vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        if(root == NULL){
            return order;
        }
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            while(node != NULL){
                st.push(node);
                order.push_back(node->val);
                node = node->left;
            }
            if(st.empty()){
                break;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }
        return order;
    }
