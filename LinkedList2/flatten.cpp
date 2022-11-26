Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL){
       return root;
   }
   Node* head = new Node(0);
   Node* node = head;
   root->next = flatten(root->next);
   Node* list = root;
   Node* nextlist = root->next;
   while(list && nextlist){
       if(list->data < nextlist->data){
           node->bottom = list;
           list = list->bottom;
       }else{
           node->bottom = nextlist;
           nextlist = nextlist->bottom;
       }
       node = node->bottom;
   }
   if(list){
       node->bottom = list;
   }
   if(nextlist){
       node->bottom = nextlist;
   }
   return head->bottom;
}
