class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        if(!root) return 1;
        if(isSumProperty(root->left) && isSumProperty(root->right)){
            int sum=0;
            if(root->left) sum+=root->left->data;
            if(root->right) sum+=root->right->data;
            if(sum == 0 || sum == root->data) return 1;
        }
        return 0;
    }
};