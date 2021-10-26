vector<int> inOrder(Node *root) {
    // code here
    vector<int> ans;
    if(root){
        
        vector<int> temp;
        temp = inOrder(root->left);
        ans.insert(ans.end(), temp.begin(), temp.end());
        
        ans.push_back(root->data);
        
        temp = inOrder(root->right);
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}