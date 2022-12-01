class Solution {
private:
    TreeNode* helper(int &i, vector<int> &post, vector<int> &in, int start, int end, unordered_map<int, int> &mp){
        if(end < start) return NULL;
        TreeNode* root = new TreeNode(post[i]);
        int left = mp[post[i]]-1;
        int right = mp[post[i]]+1;
        if(right <= end){
            i--;
            root->right = helper(i, post, in, right, end, mp);
        }
        if(left >= start){
            i--;
            root->left = helper(i, post, in, start, left, mp);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        int i = n-1;
        return helper(i, postorder, inorder, 0, n-1, mp);
    }
};
