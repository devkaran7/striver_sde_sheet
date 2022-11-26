ListNode *getIntersectionNode(ListNode *firstHead, ListNode *secondHead) {
        if(firstHead == NULL || secondHead == NULL){
            return NULL;
        }
        ListNode* head1 = firstHead;
        ListNode* head2 = secondHead;

        while(head1 != head2){
            if(head1 == NULL){
                head1 = secondHead;
            }
            if(head2 == NULL){
                head2 = firstHead;
            }
            if(head1 == head2){
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1;
    }
