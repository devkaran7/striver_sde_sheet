vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* node = root;
        while(node != NULL){
            if(node->left == NULL){
                inorder.push_back(node->val);
                node = node->right;
            }else{
                TreeNode* temp = node->left;
                while(temp->right != NULL && temp->right != node){
                    temp = temp->right;
                }
                if(temp->right == NULL){
                    temp->right = node;
                    node = node->left;
                }else{
                    temp->right = NULL;
                    inorder.push_back(node->val);
                    node = node->right;
                }
            }
        }
        return inorder;
    }
