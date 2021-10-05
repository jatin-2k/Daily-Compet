class Solution
{
    public:
    //Function to check if two trees are identical.
    
    
    bool isIdentical(Node *r1, Node *r2)
    {
        return ( 
                (r1==NULL && r2==NULL) || 
                (r1 && r2 &&
                r1->data == r2->data &&
                isIdentical(r1->left, r2->left) &&
                isIdentical(r1->right, r2 -> right))
                );
    }
};