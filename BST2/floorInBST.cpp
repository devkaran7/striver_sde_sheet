int floorInBST(TreeNode<int> * node, int x)
{
    // Write your code here.
    TreeNode<int>* root = node;
    int val = -1;
    while(root){
        if(root->val > x){
            root = root->left;
        }else{
            val = root->val;
            root = root->right;
        }
    }
    return val;
}
