class Solution{
    public:
    Node *copyList(Node *head)
    {
        Node *prev, *cur, *nxt;
        cur = head;
        prev = NULL;
        //Write your code here
        while(cur){
            nxt = cur -> next;
            cur -> next = new Node(cur -> data);
            cur -> next -> next = nxt;
            cur = nxt;
        }
        cur = head;
        while(cur && cur -> next){
            if(!cur -> arb) cur -> next -> arb = NULL;
            else cur -> next -> arb = cur -> arb -> next;
            cur = cur -> next -> next;
        }
        Node *cur1, *nxt1;
        prev = cur = head -> next;
        
        cur1 = head;
        while(cur && cur -> next && cur1 && cur1 -> next){
            nxt1 = cur1 -> next -> next;
            nxt = cur -> next -> next;
            
            cur -> next = nxt;
            cur1 -> next = nxt1;
            
            cur1 = nxt1;
            cur = nxt;
        }
        
        // cur = prev;
        // while(cur){
        //     cout<<cur<<" "<<cur->data<<" "<<cur->arb<<endl;
        //     cur = cur -> next;
        // }
        cur = head;
        while(cur->next->next){
            cur = cur -> next;
        }
        cur -> next = NULL;
        // cur = head;
        // while(cur){
        //     cout<<cur<<" "<<cur->data<<" "<<cur->arb<<endl;
        //     cur = cur -> next;
        // }
        return prev;
    }

};