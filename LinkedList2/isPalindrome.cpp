class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* node = head;
        ListNode* prev = NULL;
        while(node){
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode* dummy = head;
        while(dummy && slow){
            if(dummy->val != slow->val){
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};
