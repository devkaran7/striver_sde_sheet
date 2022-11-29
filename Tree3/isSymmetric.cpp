class Solution {
    bool help(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left->val != right->val){
            return false;
        }
        return help(left->left, right->right) && help(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return help(root->left, root->right);
    }
};
