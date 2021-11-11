Node *swapkthnode(Node* head, int n, int k)
{
    // Your Code here
    if(n<k)return head;
    Node *n1,*n2, *temp = head, *b1 = NULL, *b2 = NULL;
    int i=1;
    while(temp){
        if(i==k-1) b1 = temp;
        if(i==k) n1 = temp;
        if(i==n-k) b2 = temp;
        if(i==n-k+1) n2 = temp;
        temp = temp->next;
        i++;
    }
    if(k+1 == n-k+1){
        n1 -> next = n2 -> next;
        if(b1) b1 -> next = n2;
        n2 -> next = n1;
        if(k==1) head = n2;
    }
    else if(k-1 == n-k+1){
        n2->next = n1-> next;
        if(b2) b2->next = n1;
        n1->next = b1;
        if(k==n) head = n1;
    }
    else if(k==n-k+1){
        return head;
    }
    else{
        //cout<<b1->next->data<<" "<<n2->data;
        //return NULL;
        if(b1) b1->next = n2;
        b1 = n1-> next;
        n1 -> next = n2 -> next;
        n2 -> next = b1;
        if(b2) b2 -> next = n1;
        if(k==1) head = n2;
        if(k==n) head = n1;
    }
    // temp = head;
    // while(temp){
    //     cout<<temp-> data<<" ";
    //     temp = temp -> next;
    // }
    
    return head;

}