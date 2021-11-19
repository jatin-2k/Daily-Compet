bool isPalindrome(Node *head)
    {
        //Your code here
        Node * temp = head;
        int n=0;
        while(temp->next){
            n++;
            temp = temp -> next;
        }
        Node * head2;
        temp = head;
        for(int i=0; i<n/2; i++){
            temp = temp -> next;
        }
        head2 = temp -> next;
        temp -> next = NULL;
        head2 = reverseList(head2);
        while(head && head2){
            if(head->data != head2 ->data){
                return false;
            }
            head = head -> next;
            head2 = head2 -> next;
        }
        return true;
    }