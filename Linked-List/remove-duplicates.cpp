class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        if(head==NULL){
            return NULL;
        }
        while(temp->next!=NULL)
        {
            if(temp->val==temp->next->val)
            {
                ListNode *ptr=temp->next;
                temp->next=ptr->next;
                delete ptr;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};