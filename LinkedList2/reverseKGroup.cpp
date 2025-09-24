/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* nextNode = head;
        for (int i = 0; i < k; i++) {
            if (nextNode == nullptr) return head;
            nextNode = nextNode->next;
        }
        ListNode* newHead = reverseKGroup(nextNode, k);
        ListNode* node = head;
        ListNode* prevNode = nullptr;
        while(node != nextNode) {
            ListNode* temp = node->next;
            node->next = prevNode;
            prevNode = node;
            node = temp;
        }
        head->next = newHead;
        return prevNode;
    }
};
