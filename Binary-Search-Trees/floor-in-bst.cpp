// Function to find the floor of given number.
int floorUtil(Node* root, int key) {
    if (!root) return INT_MAX;

    // if data at current node is equal to given number, we return it.
    if (root->data == key) return root->data;

    // if data at current node is greater than given number, we call
    // the function recursively for left subtree.
    if (root->data > key) return floorUtil(root->left, key);

    // else data at current node is smaller than given number so we call
    // the function recursively for right subtree.
    int floorValue = floorUtil(root->right, key);

    return (floorValue <= key) ? floorValue : root->data;
}

// Function to return the floor of given number in BST.
int floor(Node* root, int key) {
    int ans = floorUtil(root, key);

    // returning floor of given number or -1 if no such element exists.
    if (ans == INT_MAX) return -1;

   