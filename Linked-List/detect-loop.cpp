class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        if(fast and fast->next) do{
            slow = slow -> next;
            fast = fast -> next -> next;
        }while(fast and fast->next and fast != slow);
        if(!head or !head->next or fast != slow) return NULL;
        slow = head;
        while(fast!=slow){
            slow = slow->next; fast = fast->next;
        }
        return fast;
    }
};