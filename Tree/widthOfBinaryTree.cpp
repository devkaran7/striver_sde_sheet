int widthOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    long long ans = 0;
    queue<pair<TreeNode* , long long>> q;
    q.push({root, 0});
    while(q.empty() == false){
        int k = q.size();
        long long mini = q.front().second;
        for(int i = 0; i < k; i++){
            TreeNode* node = q.front().first;
            long long index = q.front().second - mini;
            q.pop();
            if(node->left){
                q.push({node->left, index*2ll+1});
            }
            if(node->right){
                q.push({node->right, index*2ll+2});
            }
            //r-l+1 and l = 0 so
            ans = max(index + 1, ans);
        }
    }
    return ans;
}
