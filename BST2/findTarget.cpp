class BSTIterator {
private:
    TreeNode* node;
    stack<TreeNode*> st;
    int a;
    //a -> 1 then normal inorder
    //a -> 0 then reverse inorder
public:
    BSTIterator(TreeNode* root, int x) {
        node = root;
        a = x;
        while(root){
            st.push(root);
            if(a){
                root = root->left; 
            }else{
                root = root->right;
            }
        }
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        TreeNode* new_node;
        if(a){
            new_node = node->right;
        }else{
            new_node = node->left;
        }
        while(new_node){
            st.push(new_node);
            if(a){
                new_node = new_node->left; 
            }else{
                new_node = new_node->right;
            }
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator normal(root, 1);
        BSTIterator rev(root, 0);
        int i = normal.next();
        int j = rev.next();
        while(i != j){
            if(i + j < k){
                i = normal.next();
            }else if(i + j > k){
                j = rev.next();
            }else{
                return true;
            }
        }
        return false;
    }
};
