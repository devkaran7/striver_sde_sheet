class Solution {
private:
    bool notLeaf(Node *node){
        if(node->left == NULL && node->right == NULL){
            return false;
        }
        return true;
    }
private:
    void addleft(Node *root, vector<int> &res){
        Node *node = root;
        while(node){
            if(notLeaf(node)){
                res.push_back(node->data);    
            }
            if(node->left){
                node = node->left;
            }else{
                node = node->right;
            }
        }
    }
private:
    void addLeaves(Node *node, vector<int> &res){
        if(node == NULL){
            return;
        }
        if(notLeaf(node) == false){
            res.push_back(node->data);
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }
private:
    void addRight(Node *root, vector<int> &res){
        Node *node = root;
        vector<int> temp;
        while(node){
            if(notLeaf(node)){
                temp.push_back(node->data);
            }
            if(node->right){
                node = node->right;
            }else{
                node = node->left;
            }
        }
        for(int i = temp.size() - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        if(notLeaf(root)){
            res.push_back(root->data);
        }
        addleft(root->left, res);
        addLeaves(root, res);
        addRight(root->right, res);
        return res;
    }
};
