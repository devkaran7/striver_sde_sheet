vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    if(root == NULL) return inorder;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
        if(node == NULL){
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }else{
            st.push(node);
            node = node->left;
        }
    }
    return inorder;
}
