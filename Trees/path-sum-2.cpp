class Solution {
public:
    vector<int> cur;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        pathSum(root, targetSum, ans);
        return ans;
    }
    
    void pathSum(TreeNode* root, int targetSum, vector<vector<int>> &ans){
        if(!root) return;
        cur.push_back(root->val);
        targetSum -= root->val;
        if(targetSum == 0 && !root->left && !root->right){
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        pathSum(root->left, targetSum, ans);
        pathSum(root->right, targetSum, ans);
        cur.pop_back();
        return;
    }
};