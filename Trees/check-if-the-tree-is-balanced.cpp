class Solution{
    public:

    bool isBalanced(Node *root)
    {
        //  Your Code 
        bool B = true;
        maxH(root,B);
        return B;
    }
    
    int maxH(Node *root, bool &B){
        if(root){
            
            int l = maxH(root->left, B);
            int r = maxH(root->right, B);
            if(abs(r-l) > 1){
                B=false;
            }
            return max(r,l)+1;
        }
        return 0;
    }
};