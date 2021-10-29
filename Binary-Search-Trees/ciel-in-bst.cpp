int findCeil(Node* root, int k) {
    if (!root) return -1;
    
    if(root->data == k) return root->data;
    if(root->data < k) return findCeil(root->right, k);
    if(root->data > k){
        int t = findCeil(root->left, k);
        return (t>=k)?t:root->data;
    }
    // Your code here
}