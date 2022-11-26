ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        ListNode* ptr = head;
        for(int i = 0; i < n; i++){
            ptr = ptr->next;
        }
        if(ptr == NULL) return head->next;
        while(ptr->next != NULL){
            ptr = ptr->next;
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
