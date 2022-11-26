ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* head = head1;
        if(head1->val < head2->val){
            head1 = head1->next;
        }else{
            head = head2;
            head2 = head2->next;
        }
        ListNode* node = head;
        while(head1 && head2){
            if(head1->val < head2->val){
                node->next = head1;
                head1 = head1->next;
            }else{
                node->next = head2;
                head2 = head2->next;
            }
            node = node->next;
        }
        if(head1){
            node->next = head1;
        }
        if(head2){
            node->next = head2;
        }
        return head;
    }
