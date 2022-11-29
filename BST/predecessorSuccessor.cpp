pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* node = root;
    pair<int, int> p = {-1, -1};
    while(node){
        if(node->data <= key){
            node = node->right;
        }else{
            p.second = node->data;
            node = node->left;
        }
    }
    node = root;
    while(node){
        if(node->data >= key){
            node = node->left;
        }else{
            p.first = node->data;
            node = node->right;
        }
    }
    return p;
}
