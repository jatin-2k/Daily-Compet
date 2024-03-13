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
    TreeNode *end = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        end = root;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        flatten(l);
        root->left = NULL;
        root->right = l;
        end->right = r;
        flatten(r);
    }
};