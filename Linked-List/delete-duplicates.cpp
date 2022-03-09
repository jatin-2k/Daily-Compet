class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *dummy = new ListNode(-1000);
        ListNode *temp = head, *cur = dummy;
        while(temp){
            int data = temp->val;
            if(temp->next and temp->next->val == data){
                while(temp and temp->val == data) temp = temp->next;
            }
            else{
                cur->next = temp;
                cur = cur->next;
                temp = temp->next;
            }
        }
        cur->next = nullptr;
        return dummy->next;
            
    }
};