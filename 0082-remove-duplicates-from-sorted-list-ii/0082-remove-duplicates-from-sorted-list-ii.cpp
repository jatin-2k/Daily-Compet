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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(0,head);
        ListNode *cur = dummy;
        while(cur){
            ListNode *n = cur->next;
            while(n && n->next && n->val == n->next->val) n = n->next;
            if(n == cur->next) cur = n;
            else cur->next = n->next;
        }
        return dummy->next;
    }
};