class Solution {
private:
    int getSum(TreeNode* node, int &maxi){
        if(node == NULL) return 0;
        int left = max(0, getSum(node->left, maxi));
        int right = max(0, getSum(node->right, maxi));
        maxi = max(maxi, left + right + node->val);
        return node->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        getSum(root, maxi);
        return maxi;
    }
};
