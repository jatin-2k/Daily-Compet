class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        targetSum -= root->val;
        cout<<root->val<<": "<<targetSum<<endl;
        if(targetSum == 0 && !root->left && !root->right){
            return true;
        }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
            
    }
};