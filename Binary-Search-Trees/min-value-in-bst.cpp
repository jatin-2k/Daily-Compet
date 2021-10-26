int minValue(Node* root) {
    // Code here
    return min(root->data, (root->left)? minValue(root->left): root->data);
}