class Solution {
public:
    
    bool checkBST(TreeNode* root ,TreeNode* max ,TreeNode* min)
    {
        if(!root)return true;
        
        if((!min || root->val > min->val) and (!max || root->val < max->val))
        {
            return checkBST(root->left,root,min) and checkBST(root->right,max,root);
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return checkBST(root,NULL,NULL);
    }
};