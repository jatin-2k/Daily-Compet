void helper(Node *root,int x,unordered_set<int>&dict)
{
    if(!root)
    {
        return;
    }
    dict.insert(x);
    helper(root->left,x-1,dict);
    helper(root->right,x+1,dict);
}
//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    if(!root)
    {
        return 0;
    }
    unordered_set<int>dict;
    helper(root,0,dict);
    return dict.size();
}