vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postOrder, inOrder, preOrder;
    if(root == NULL) return postOrder;
    stack<pair<TreeNode*, int>> st;
    TreeNode* node = root;
    while(true){
        if(node != NULL){
            preOrder.push_back(node->val);
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
                inOrder.push_back(temp->val);
                node = temp->right;
            }
        }
    }
    return postOrder/inOrder/preOrder;
}
