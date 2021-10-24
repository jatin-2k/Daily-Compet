class Solution {
  public:
    //Function to calculate maximum path sum.
    int findMaxUtil(Node *root, int &res)
    {
        //base case for recursion.
        if (root == NULL)
            return 0;
    
        //l and r store maximum path sum going recursively through left and
        //right subtrees of root(current node) respectively.
        int l = findMaxUtil(root->left, res);
        int r = findMaxUtil(root->right, res);
    
        //max path sum for parent call of root. This path must
        //include at-most one child of root.
        int max_single = max(max(l, r) + root->data, root->data);
    
        //max_top represents the sum when the node under consideration is the root
        //of the max sum path and no ancestors of root are there in max sum path. 
        int max_top = max(max_single, l + r + root->data);
    
        //storing the maximum result.
        res = max(res, max_top); 
    
        return max_single;
    }
    
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) 
    {
        int res = INT_MIN;
        findMaxUtil(root, res);
        
        //returning the result.
        return res;
    }
};