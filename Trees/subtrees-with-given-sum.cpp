int fun(Node *root, int x, int &count){
    if(root){
        int sum = 0;
        sum += fun(root->left, x, count);
        sum += fun(root->right, x, count);
        sum += root->data;
        if(sum == x) count++;
        return sum;
    }
    return 0;
}
//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
    // Code here
    int c = 0;
    fun(root, X, c);
    return c;
}