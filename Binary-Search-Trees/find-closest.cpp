class Solution
{
    public:
    int mini = INT_MAX;
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        //Your code here
        if(root){
            mini = min(mini,abs(root->data - K));
            if(K<root->data)minDiff(root->left, K);
            if(K>root->data)minDiff(root->right, K);
            return mini;
        }
        return 1;
    }
};