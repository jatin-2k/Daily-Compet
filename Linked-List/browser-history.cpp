struct Node{
    string val;
    Node *prev;
    Node *next;
    Node(string v){
        val = v; prev = NULL; next = NULL;
    }
    Node(string v,Node* p, Node* n){
        val = v; prev= p; next = n;
    }
};

class BrowserHistory {
public:
    Node *head;
    Node *cur;
    
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        cur = head;
    }
    
    void visit(string url) {
        cur -> next = new Node(url,cur,NULL);
        cur = cur -> next;
    }
    
    string back(int steps) {
        for(int i=0; i<steps and cur->prev; i++, cur = cur->prev);
        return cur->val;
    }
    
    string forward(int steps) {
        for(int i=0; i<steps and cur->next; i++, cur = cur->next);
        return cur->val;
    }
};