class Solution {
private:
    bool helper(TreeNode* root, long long l, long long r){
        if(root == NULL){
            return true;
        }
        if(root->val <= l || root->val >= r){
            return false;
        }
        return helper(root->left, l, root->val) && helper(root->right, root->val, r);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, -1e10, 1e10);
    }
};
