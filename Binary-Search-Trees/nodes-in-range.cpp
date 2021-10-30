void c(Node *root, int l, int r, int &count){
    if(root)
    {
        if(root->data >= l && root->data <= r){
            count++;
        }
        if(root->data > l) c(root->left, l, r, count);
        if(root->data < r) c(root->right, l, r, count);
    }
}

//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here  
  int i =0;
  c(root, l, h, i);
  return i;
  
}