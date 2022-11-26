ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while(head1 || head2){
            int sum = carry;
            if(head1){
                sum += head1->val;
                head1 = head1->next;
            }
            if(head2){
                sum += head2->val;
                head2 = head2->next;
            }
            int value = sum%10;
            carry = sum/10;
            ListNode* new_node = new ListNode(value);
            node->next = new_node;
            node = node->next;
        }
        if(carry != 0){
            ListNode* new_node = new ListNode(carry);
            node->next = new_node;
        }
        return head->next;
    }
