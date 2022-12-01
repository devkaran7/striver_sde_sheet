class Solution {
private:
    TreeNode* helper(int &i, vector<int> &pre, vector<int> &in, int start, int end, unordered_map<int, int> &mp){
        if(end < start) return NULL;
        TreeNode* root = new TreeNode(pre[i]);
        int left = mp[pre[i]]-1;
        int right = mp[pre[i]]+1;
        if(left >= start){
            i++;
            root->left = helper(i, pre, in, start, left, mp);
        }
        if(right <= end){
            i++;
            root->right = helper(i, pre, in, right, end, mp);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        int i = 0;
        return helper(i, preorder, inorder, 0, n-1, mp);
    }
};
