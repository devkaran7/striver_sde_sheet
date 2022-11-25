ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* prev = NULL;
        ListNode* node = head;
        while(node){
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
