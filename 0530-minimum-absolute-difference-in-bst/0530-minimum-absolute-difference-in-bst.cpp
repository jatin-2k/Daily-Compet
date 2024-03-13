/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MAX;
    int prev = 1000000;
    int getMinimumDifference(TreeNode* root) {
        calc(root);
        return ans;
    }
    
    void calc(TreeNode *root){
        if(!root) return;
        
        calc(root->left);
        ans = min(ans, abs(root->val - prev));
        //cout<<ans<<": "<<root->val<<" "<<prev<<endl;
        prev = root->val;
        calc(root->right);
    }
};