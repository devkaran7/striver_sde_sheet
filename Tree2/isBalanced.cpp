class Solution {
private:
    int getHeight(TreeNode* root, bool &flag){
        if(root == NULL) return -1;
        int left = getHeight(root->left, flag);
        int right = getHeight(root->right, flag);
        flag = flag & (abs(left - right) <= 1);
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        getHeight(root, flag);
        return flag;
    }
};
