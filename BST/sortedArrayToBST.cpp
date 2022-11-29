class Solution {
private:
    TreeNode* construct(int low, int high, vector<int> &nums){
        if(low > high) return NULL;
        int mid = (low + high) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = construct(low, mid - 1, nums);
        node->right = construct(mid + 1, high, nums);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return construct(0, n-1, nums);
    }
};
