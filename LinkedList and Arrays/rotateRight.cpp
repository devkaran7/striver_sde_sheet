ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len = 0;
        ListNode* node = head;
        while(node){
            len++;
            node = node->next;
        }
        k = k % len;
        ListNode* ptr = head;
        for(int i = 1; i <= k; i++){
            ptr = ptr->next;
        }
        node = head;
        while(ptr->next){
            node = node->next;
            ptr = ptr->next;
        }
        ptr->next = head;
        head = node->next;
        node->next = NULL;
        return head;
    }
