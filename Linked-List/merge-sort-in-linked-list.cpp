class Solution {
public:
    ListNode* sortList(ListNode* head, ListNode *last = nullptr) {
        if(!head or !head->next) return head;
        ListNode *mid = NULL;
        ListNode *slow = head, *fast = head->next;
        while(fast and fast != last and fast->next and fast->next != last){
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow->next;
        slow->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        return mergeSorted(l1,l2);
    }
    ListNode* mergeSorted(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 and l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next; 
            cur -> next = NULL;
        }
        if(l1) cur -> next = l1;
        if(l2) cur -> next = l2;
        return dummy->next;
    }
};