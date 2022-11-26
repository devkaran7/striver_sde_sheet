class Solution {
private:
    ListNode* reverse(ListNode *start, ListNode *end){
        ListNode* prev = NULL;
        ListNode* curr = start;
        while(curr != end){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start = head;
        ListNode *end = head;
        ListNode *newhead = NULL;
        ListNode *tail = NULL;
        while(start != NULL){
            int cnt = 0;
            while(end != NULL && cnt < k){
                end = end->next;
                cnt++;
            }
            if(cnt != k){
                tail->next = start;
                return newhead;
            }
            if(newhead == NULL){
                newhead = reverse(start, end);
            }else{
                tail->next = reverse(start, end);
            }
            tail = start;
            start = end;
        }
        return newhead;
    }
};
