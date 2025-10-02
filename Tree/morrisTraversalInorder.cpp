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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* node = root;
        while (node != nullptr) {
            cout << node->val << endl;
            if (node->left == nullptr) {
                inorder.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* rightMostNode = node->left;
                while(rightMostNode->right != nullptr && rightMostNode->right != node) {
                    rightMostNode = rightMostNode->right;
                }
                if (rightMostNode->right == node) {
                    rightMostNode->right = nullptr;
                    inorder.push_back(node->val);
                    node = node->right;
                } else {
                    rightMostNode->right = node;
                    node = node->left;
                }
            }
        }
        return inorder;
    }
};
