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
    TreeNode *head, *cur;
    
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!head) head = cur = new TreeNode();
        pre(root);
        root = head->right;
    }
    void pre(TreeNode *root){
        if(!root) return;
        
        cur -> right = root;
        cur = root;
        
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        root->left = root->right = NULL;
        pre(l);
        pre(r);
    }
};