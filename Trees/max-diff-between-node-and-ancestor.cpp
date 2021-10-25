int fun(Node *root, int &m){
    if(root){
        int l = fun(root->left, m);
        int r = fun(root->right, m);
        m = max(m , root->data - min(l,r));
        return min(root->data,l,r);
    }
    return INT_MAX;
}

//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
    int ans = INT_MIN;
    fun(root,ans);
    return ans;
}