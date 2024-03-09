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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        ListNode *cur = head;
        int n = 1;
        while(cur->next){
            cur = cur->next;
            n++;
        }
        cur->next = head;
        for(int i=0; i<n-k%n; i++){
            cur = cur->next;
            head = head->next;
        }
        cur->next = nullptr;
        return head;
    }
};