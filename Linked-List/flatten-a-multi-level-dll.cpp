class Solution {
    private:
    Node *ans;
    Node *cur;
    public:
    Solution(){
        ans = new Node(-1);
        cur = ans;
    }
    void insert(Node *n){
        cur -> next = n;
        n -> prev = cur;
        n -> next = NULL;
        n -> child = NULL;
        cur = n;
    }
    Node* flatten(Node* head) {
        if(!head) return NULL;
        solve(head);
        ans -> next ->prev = NULL;
        return ans->next;
    }
    void solve(Node *head){
        if(!head) return;
        Node *child = head-> child;
        Node *nxt = head-> next;
        insert(head);
        flatten(child);
        flatten(nxt);
    }
};