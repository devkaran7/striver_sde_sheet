void mirror(Node* node) {
        // code here
        if(node == NULL) return;
        mirror(node->left);
        mirror(node->right);
        Node* temp = node->right;
        node->right = node->left;
        node->left = temp;
    }
