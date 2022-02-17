class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode *cur, *s1, *s2, *temp, *nxt, *dummy = new ListNode(-1, head);
        s1 = s2 = nxt = NULL;
        cur = dummy;
        for(temp = head; temp->next; temp = temp->next);
        temp->next = new ListNode(-1);
        while(cur){
            s1  = cur->next;
            s2  = s1 ? s1->next : NULL;
            nxt = s2 ? s2->next : NULL;
            if(s1->val == -1){ cur->next = NULL; break; }
            if(s2->val == -1){ s1->next = NULL; break; }
            cur->next = s2;
            if(s1) s1->next = nxt;
            if(s2) s2->next = s1;
            cur = s1;
        }
        return dummy->next;
    }
};

ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}