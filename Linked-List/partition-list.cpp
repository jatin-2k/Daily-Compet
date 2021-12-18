class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *sl = new ListNode(-1), *ll = new ListNode(-1);
        ListNode *ts = sl, *tl = ll;
        
        while(head){
            if(head -> val >= x){
                cout<<head -> val<<endl;
                ll -> next = head;
                ll = ll -> next;
            }
            else{
                cout<<head -> val<<endl;
                sl -> next = head;
                sl = sl -> next;
            }
            head = head -> next;
            ll -> next = NULL;
            sl -> next = NULL;
        }
        head = ts;
        while(head -> next) head = head->next;
        head -> next = tl -> next;
        return ts -> next;
    }
};