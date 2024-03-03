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
        ListNode *false_head = new ListNode(0, head);
        ListNode *fast = false_head, *slow = false_head;
        for(int i=0; i<n && fast; i++) fast = fast->next;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next;
        }
        fast = slow -> next -> next;
        slow -> next -> next = NULL;
        delete(slow -> next);
        slow -> next = fast;
        return false_head->next;
    }
};