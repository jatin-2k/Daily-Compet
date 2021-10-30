class Solution
{
    public:
    bool flag = true;
    //Function to check whether a Binary Tree is BST or not.
    void trav(Node* root, int &last){
        if(root){
            trav(root->left, last);
            if(root->data > last) last = root->data;
            else flag = false;
            trav(root->right, last);
        }
    }
    bool isBST(Node* root) 
    {
        int i = INT_MIN;
        trav(root, i);
        return flag;
    }
};