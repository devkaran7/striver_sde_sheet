class Solution {
private:
    int rec(TreeNode* node, int &maxi){
        if(node == NULL) return -1;
        int left = rec(node->left, maxi);
        int right = rec(node->right, maxi);
        maxi = max(maxi, 2 + left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        rec(root, maxi);
        return maxi;
    }
};
