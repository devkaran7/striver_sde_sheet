TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l != NULL && r != NULL){
            return root;
        }
        if(l != NULL){
            return l;
        }else if(r != NULL){
            return r;
        }else{
            return NULL;
        }
    }
