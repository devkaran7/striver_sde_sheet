class Solution
{
    private:
    int cnt = 0;
    int ans;
    int getLen(Node* root){
        if(root == NULL) return 0;
        return 1 + getLen(root->left) + getLen(root->right);
    }
    void inorder(Node* node, int K){
        if(node == NULL) return;
        inorder(node->left, K);
        cnt++;
        if(cnt == K){
            ans = node->data;
        }
        inorder(node->right, K);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int n = getLen(root);
        inorder(root, n-K+1);
        return ans;
    }
};
