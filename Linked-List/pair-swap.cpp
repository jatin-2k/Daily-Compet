struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    Node *prev = new Node(0), *c1, *c2, *next;
    prev -> next = head;
    c1 = head;
    c2 = head -> next;
    if(c2)
        next = c2 -> next;
    else
        return head;
    head = prev;
    while(c2 && c1){
        c1 -> next = next;
        c2 -> next = c1;
        prev -> next = c2;
        
        prev = c1;
        c1 = next;
        if(c1)
            c2 = c1 -> next;
        if(c2)
            next = c2 -> next;
    }
    return head-> next;
}