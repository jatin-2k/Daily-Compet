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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur, *end, *dummy;
        dummy = new ListNode(-1, head);
        cur = end = dummy;
        for(int i=0; i<n; i++)
            end = end->next;
        while(end and end->next){
            end = end->next;
            cur = cur->next;
        }
        if(cur->next){
            ListNode* nxt = cur->next->next;
            cur->next->next = NULL;
            delete(cur->next);
            cur->next = nxt;
        }
        return dummy->next;
    }
};