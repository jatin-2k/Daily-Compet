/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *prev = NULL; Node *head = NULL;
        Node *cur = root;
        while(cur != NULL){
            while(cur != NULL){
                if(cur->left != NULL){
                    if(prev == NULL){
                        head = cur->left;
                    }
                    else {
                        prev->next = cur->left;
                    }
                    prev = cur->left;
                }
                if(cur->right != NULL){
                    if(prev == NULL){
                        head = cur->right;
                    }
                    else {
                        prev->next = cur->right;
                    }
                    prev = cur->right;
                }
                cur = cur->next;
            }
            
            cur = head;
            head = prev = NULL;
        }
        return root;
    }
};