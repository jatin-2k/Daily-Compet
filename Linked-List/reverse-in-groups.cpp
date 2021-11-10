void print(node *head){
    node *temp = head;
    while(temp){
        cout<<temp -> val<<" ";
        temp = temp ->next;
    }
}

node* myReverse(node *begin, node *end){
    node *prev = begin;
    node *curr = begin->next;
    node *fast = curr->next;
    node *first = curr;
    while(fast and fast!=end){
        curr->next = prev;
        prev = curr;
        curr = fast;
        fast = fast->next;
    }
    curr->next = prev;
    begin->next = curr;
    first->next = fast;
    return first;
}

void revk(node *head, int k){
    node *dummy = new node(-1);
    dummy->next = head;
    int i = 0;
    node *begin = dummy;
    while(head){
        i++;
        if(i%k==0){
            begin = myReverse(begin, head->next);
            head = begin -> next;
        }
        else
            head = head->next;
    }
    
    print(dummy->next);
}