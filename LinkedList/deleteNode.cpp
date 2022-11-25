void deleteNode(ListNode* node) {
        ListNode* next_node = node->next;
        swap(next_node->val, node->val);
        node->next = next_node->next;
    }
