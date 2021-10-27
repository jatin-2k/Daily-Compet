void inorder(Node* root,map<int,int> &m)
{
    if(root==NULL)
        return;
    inorder(root->left,m);
    m[root->data]++;
    inorder(root->right,m);
}

vector <int> findCommon(Node *root1, Node *root2)
{
    //Your code here
    vector<int> v;
    if(root1==NULL || root2==NULL)
        return v;
    map<int,int> m;
    inorder(root1,m);
    inorder(root2,m);
    
    for(auto x:m)
    {
        if(x.second==2)
            v.push_back(x.first);
    }
    return v;
}