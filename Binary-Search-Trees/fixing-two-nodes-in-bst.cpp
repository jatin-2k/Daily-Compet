class Solution {
  public:
    Node* n1 = NULL;
    Node* p1 = NULL;
    Node* n2 = NULL;
    void check(Node* root, Node *&prev){
        if(root){
            check(root->left, prev);
            if(root->data <= prev->data){
                if(n1) n2 = root;
                else{
                    n1 = root;
                    p1 = prev;
                }
            }
            prev = root;
            check(root->right, prev);
        }
    }
    void correctBST( struct Node* root )
    {
        Node* i = new Node(INT_MIN);
        check(root,i );
        if(n1 && n2) {
            swap(p1->data, n2->data);
        }
        else swap(n1->data, p1->data);
    }
};