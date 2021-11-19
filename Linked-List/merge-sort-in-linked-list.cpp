class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* splitList(Node *head) {
        Node *slow,*fast, *temp = NULL;
        slow = head; fast = head;
        while(fast && fast->next){
            
            fast = fast-> next-> next;
            if(!fast || !fast->next) temp = slow;
            slow = slow->next;
        }
        if(temp)
        temp->next = NULL;
        return slow;
    }
    
    Node* merge(Node *head1, Node* head2){
        Node * head = new Node(0), *temp;
        temp = head;
        while(head1 && head2){
            if(head1->data <= head2->data){
                head->next = head1;
                head1 = head1-> next;
            }
            else{
                head->next = head2;
                head2 = head2-> next;
            }
            head = head -> next;
        }
        if(head1) head -> next = head1;
        if(head2) head -> next = head2;
        
        return temp -> next;
    }
    
    Node* mergeSort(Node* head1) {
        // your code here
        Node *head2 = splitList(head1);
        if(head2 == head1) return head1;
        else{
            if(head1) head1 = mergeSort(head1);
            if(head2) head2 = mergeSort(head2);
            return merge(head1, head2);
        }
        
    }
};