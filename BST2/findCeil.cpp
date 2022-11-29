int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    BinaryTreeNode<int>* root = node;
    int val = -1;
    while(root){
        if(root->data < x){
            root = root->right;
        }else{
            val = root->data;
            root = root->left;
        }
    }
    return val;
}
