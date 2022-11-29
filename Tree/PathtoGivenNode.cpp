bool findPath(TreeNode* root, int target, vector<int> &path){
    if(root == NULL) return false;
    path.push_back(root->val);
    if(root->val == target) return true;
    if(findPath(root->left, target, path)) return true;
    if(findPath(root->right, target, path)) return true;
    path.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* root, int target) {
    vector<int> path;
    if(root == NULL) return path;
    findPath(root, target, path);
    return path;
}
