Node* insert(Node* root, int k) {
    // Your code here
    if(root){
        if(root->data > k) root->left = insert(root->left,k);
        if(root->data < k) root->right = insert(root->right,k);
        return root;
    }
    else{
        return new Node(k);
    }
}