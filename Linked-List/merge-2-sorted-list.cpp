Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    
    Node *tail, *head;
    tail = new Node(NULL);
    head = tail;
    while(head1 && head2){
        if(head1 -> data < head2 -> data){
            tail -> next = head1;  //joda
            tail = head1;          //ans wali k last ele p aee
            head1 = head1 -> next; //bachi hui k head p aae
        }
        else{
            tail-> next = head2;
            tail = head2;
            head2 = head2 -> next;
        }
        tail -> next = NULL; //tod dia
    }
    if(head1) tail -> next = head1;
    if(head2) tail -> next = head2;
    
    return head->next;
}  