void post(Node *root, vector<int> &ans){
    if(root){
        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->data);
    }
}
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  post(root,ans);
  return ans;
}