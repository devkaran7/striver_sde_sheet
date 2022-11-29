struct Node{
    int maxi;
    int mini;
    int sum;
    bool flag;
    Node(int a, int b, int c, int d){
        maxi = a;
        mini = b;
        sum = c;
        flag = d;
    }
};
class Solution {
private:
    Node rec(TreeNode* root, int &ans){
        if(root == NULL){
            Node node(-1e9, 1e9, 0, true);
            return node;
        }
        Node left = rec(root->left, ans);
        Node right = rec(root->right, ans);
        int sum = left.sum + right.sum + root->val;
        int maxi = max({right.maxi, left.maxi, root->val});
        int mini = min({right.mini, left.mini, root->val});
        if(left.maxi < root->val && right.mini > root->val && left.flag && right.flag){
            ans = max(ans, sum);
            Node node(maxi, mini, sum, true);
            return node;
        }
        Node node(maxi, mini, sum, false);
        return node;
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        rec(root, ans);
        return ans;
    }
};
