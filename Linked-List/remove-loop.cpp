class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *slow, *fast;
        slow = head;
        fast = head -> next;
        while(slow!=fast){
            if(!fast || !fast->next){
                return;
            }
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        int i=0;
        slow = slow->next;
        while(slow!=fast){
            i++;
            slow = slow -> next;
        }
        i++;
        
        Node* temp = head;
        slow = head;
        for(int j=0; j<i; j++){
            slow = slow -> next;
        }
        while(temp!=slow){
            temp = temp -> next;
            slow = slow -> next;
        }
        while(slow->next!=temp){
            slow = slow -> next;
        }
        slow -> next = NULL;
    }
};