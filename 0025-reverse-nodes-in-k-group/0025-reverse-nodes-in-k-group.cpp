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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0,head);
        int n = 0, cnt = 1;
        ListNode *prev = dummy, *cur = head;
        while(cur){ cur = cur->next; n++; }
        cur = head;
        //cout<<"n: "<<n<<endl;
        
        if(n<k) return head;
        
        while(cur && cur->next){
            //cout<<"prev: "<<prev->val<<" cur: "<<cur->val<<" cnt:"<<cnt<<endl;
            if(cnt%k == 0){ 
                prev = cur;
                cur = cur->next;
                if(n-cnt<k) break;
            }else{
                ListNode *nxt = cur->next;
                cur -> next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
            }
            cnt++;
        }
        return dummy->next;
    }
};