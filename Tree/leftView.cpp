vector<int> leftView(Node *root)
{
   //first node in level order traversal from left.
   vector<int> leftView;
   if(root == NULL) return leftView;
   queue<Node* > q;
   q.push(root);
   while(q.empty() == false){
       bool flag = false;
       int sz = q.size();
       while(sz--){
           Node* node = q.front();
           q.pop();
           if(flag == false){
               flag = true;
               leftView.push_back(node->data);
           }
           if(node->left){
               q.push(node->left);
           }
           if(node->right){
               q.push(node->right);
           }
       }
   }
   return leftView;
}
