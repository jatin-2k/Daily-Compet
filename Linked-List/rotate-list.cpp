class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* end = head;
        int n = 1;
        while(end->next){
            end = end->next;
            n++;
        }
        k = k%n;
        end->next = head;
        for(int i=0; i<n-k; i++){
            end = end->next;
        }
        head = end->next;
        end->next = NULL;
        return head;
    }
};