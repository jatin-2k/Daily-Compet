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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode *h, *cur;
        h = cur = new ListNode(0);
        while(l1 || l2){
            if(l1) c += l1->val;
            if(l2) c += l2->val;
            cur->next = new ListNode(c%10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            c /= 10;
        }
        if(c) cur->next = new ListNode(c);
        return h->next;
    }
};