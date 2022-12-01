class Solution {
private:
    TreeNode* f(vector<int> &arr, int ub, int &i){
        if(i == arr.size() || arr[i] > ub){
            return NULL;
        }
        TreeNode* node = new TreeNode(arr[i++]);
        node->left = f(arr, node->val, i);
        node->right = f(arr, ub, i);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return f(preorder, INT_MAX, i);
    }
};
