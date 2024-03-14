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
    bool isValidBST(TreeNode* root, long long mn = LLONG_MIN, long long mx = LLONG_MAX) {
        if(!root) return true;
        if((!root->left || (root->val > root->left->val && root->left->val > mn)) &&
           (!root->right || (root->val < root->right->val && root->right->val < mx)))
        {
            return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
        }
        return false;
    }
};