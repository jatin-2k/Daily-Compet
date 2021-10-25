class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> fun(Node *root){
        if(root){
            pair<int,int> l = fun(root->left);
            pair<int,int> r = fun(root->right);
            return {
                l.second + r.second + root->data,
                max(l.first , l.second) + max(r.first , r.second)
            };
        }
        return {0,0};
    }
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> a = fun(root);
        return max(a.first,a.second);
        
    }
};