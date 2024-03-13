/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pf = false;
    bool qf = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(!pf && root == p) pf = true;
        if(!qf && root == q) qf = true;
        TreeNode *l = lowestCommonAncestor(root->left, p,q);
        TreeNode *r = lowestCommonAncestor(root->right, p,q);
        if((l==p && r==q) || (l==q && r==p)) return root;
        if(root == p || root == q) return root;
        return l==NULL ? r : l;
    }
};