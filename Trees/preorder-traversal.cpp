class Solution {
  public:
    void inorder(Node* root, vector<int> &a)
    {
        if(root == NULL) return;
        a.push_back(root->data);
        inorder(root->left,a);
        inorder(root->right,a);
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};