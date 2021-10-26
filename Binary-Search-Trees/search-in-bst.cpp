bool search(struct Node* root, int x) {
    if(root){
        if(root->data == x) 
            return true;
        else if(root->data > x) 
            return search(root->left,x);
        else 
            return search(root->right,x);
    }
    return false;
}