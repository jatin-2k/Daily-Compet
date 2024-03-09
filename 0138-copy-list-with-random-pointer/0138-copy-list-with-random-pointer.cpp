/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur = head, *ans = new Node(0);
        Node *ac = ans;
        while(cur){
            Node *n = cur -> next;
            cur->next = new Node(cur->val);
            cur->next->next = n;
            cur = cur->next->next;
        }
        cur = head;
        while(cur){
            if(!cur->random) cur->next->random = NULL;
            else cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        while(cur){
            ac->next = cur->next;
            cur->next = cur->next->next;
            ac = ac->next;
            cur = cur->next;
        }
        return ans->next;
    }
};