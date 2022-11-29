class BSTIterator {
private:
    TreeNode* node;
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        node = root;
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        TreeNode* new_node = node->right;
        while(new_node){
            st.push(new_node);
            new_node = new_node->left;
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
