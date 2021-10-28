class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root)
        {
            
            if(root->val>=low)
            {

                sum+=rangeSumBST(root->left,low,high);
        
            }

             if(root->val<=high)
            {
                sum+=rangeSumBST(root->right,low,high);
               
            }
            if(root->val>=low and root->val<=high)
            {
                sum+=root->val;
            }
        }
        return sum;
    }
    
};