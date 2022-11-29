vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preOrder;
    if(root == nullptr) return preOrder;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
        if(node == NULL){
            if(st.empty()) break;
            node = st.top();
            st.pop();
            node = node->right;
        }else{
            preOrder.push_back(node->val);
            st.push(node);
            node = node->left;
        }
    }
    return preOrder;
}
