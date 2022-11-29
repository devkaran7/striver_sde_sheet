class Solution {
private:
    void rec(TreeNode* node, int &cnt, int &ans, int k){
        if(node == NULL){
            return;
        }
        rec(node->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = node->val;
        }
        rec(node->right, cnt, ans, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans;
        rec(root, cnt, ans, k);
        return ans;
    }
};
