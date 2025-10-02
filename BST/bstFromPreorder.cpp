/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* build(vector<int> &preorder, int &i, int upperBound) {
        if (i >= preorder.size() || preorder[i] >= upperBound) return nullptr;
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = build(preorder, i, node->val);
        node->right = build(preorder, i, upperBound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};

/*

dry run -> [8, 5, 1, 7, 10, 12]
i = 0, up = IM
8 -> left = 5
5 -> left = 1
1 -> left = null
1 -> right = null
5 -> right = 7
7 -> left = null
7 -> right = null
8 -> right = 10
10 -> left = null
10 -> right = 12
12 -> left = null
12 -> right = null

TC -> O(N)
SC -> O(N)

*/
