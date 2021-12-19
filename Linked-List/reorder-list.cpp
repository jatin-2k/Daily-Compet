class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL;
        ListNode *cur = head;
        while(cur){
            ListNode *nxt = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *mid = slow;
        ListNode *head1 = head;
        ListNode *head2 = slow -> next;
        mid -> next = NULL;
        head2 = reverse(head2);
        while(head2){
            ListNode *nxt1 = head1 -> next;
            ListNode *nxt2 = head2 -> next;
            head1 -> next = head2;
            head2 -> next = nxt1;
            head1 = nxt1;
            head2 = nxt2;
        }
    }
};