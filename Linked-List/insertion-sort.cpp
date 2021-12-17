class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *start = new ListNode(INT_MIN);
        while(head){
            ListNode *nextBox = head -> next;
            
            ListNode *it = start;
            while(it->next && it->next->val < head->val){
                it = it->next;
            }
            head -> next = it -> next;
            it -> next = head;
            
            head = nextBox;
        }
        return start->next;
    }
};