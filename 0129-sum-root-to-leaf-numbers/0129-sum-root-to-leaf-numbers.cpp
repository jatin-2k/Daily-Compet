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
    int ans = 0;
    int sumNumbers(TreeNode* root, int cur = 0) {
        if(!root) return cur;
        cur = cur*10+root->val;
        if(!root->left && !root->right) ans += cur;
        sumNumbers(root->left, cur);
        sumNumbers(root->right, cur);
        return ans;
    }
};