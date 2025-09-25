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
private:
    int getLength(ListNode* head) {
        ListNode* node = head;
        int cnt = 0;
        while(node != nullptr) {
            node = node->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int listLength = getLength(head);
        if (listLength == 0) return nullptr;
        k = k % listLength;
        if (k == 0) return head;
        ListNode* node = head;
        for (int i = 0; i < listLength-k-1; i++) {
            node = node->next;
        }
        ListNode* node2 = node->next;
        ListNode* newHead = node2;
        while(node2->next != nullptr) node2 = node2->next;
        node->next = nullptr;
        node2->next = head;
        return newHead;
    }
};
