vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postOrder;
    if(root == NULL) return postOrder;
    stack<pair<TreeNode*, int>> st;
    TreeNode* node = root;
    while(true){
        if(node != NULL){
            st.push({node, 1});
            node = node->left;
        }else{
            if(st.empty()) break;
            TreeNode* temp = st.top().first;
            int flag = st.top().second;
            st.pop();
            if(flag == 2){
                postOrder.push_back(temp->val);
            }else{
                st.push({temp, 2});
                node = temp->right;
            }
        }
    }
    return postOrder;
}
