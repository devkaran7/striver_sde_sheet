ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int ans = -1;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ans = 0;
                break;
            }
        }
        if(ans == -1){
            return NULL;
        }
        ListNode* node = head;
        while(node != slow){
            slow = slow->next;
            node = node->next;
        }
        return node;
    }
