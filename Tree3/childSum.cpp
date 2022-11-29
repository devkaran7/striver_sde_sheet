void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL) return;
    if(root->left != NULL && root->left->data < root->data){
        root->left->data = root->data;
    }
    changeTree(root->left);
    if(root->right != NULL && root->right->data < root->data){
        root->right->data = root->data;
    }
    changeTree(root->right);
    int temp = 0;
    if(root->left != NULL) temp += root->left->data;
    if(root->right != NULL) temp += root->right->data;
    root->data = max(root->data, temp);
}  
