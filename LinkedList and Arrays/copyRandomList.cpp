Node* copyRandomList(Node* head) {
        Node* node = head;
        while(node != NULL){
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
            node = node->next->next;
        }
        node = head;
        while(node != NULL){
            if(node->random != NULL){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        Node* newHead = new Node(0);
        Node* newNode = newHead;
        node = head;
        while(node != NULL){
            newNode->next = node->next;
            node->next = node->next->next;
            newNode = newNode->next;
            node = node->next;
        }
        return newHead->next;
    }
