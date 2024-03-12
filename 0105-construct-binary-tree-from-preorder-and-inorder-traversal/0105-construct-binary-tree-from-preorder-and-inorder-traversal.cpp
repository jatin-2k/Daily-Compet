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
    int i = 0;
    int p = 0;
    TreeNode* buildTree(vector<int>& po, vector<int>& io, int stop = INT_MIN) {
        if(p >= po.size()) return nullptr;
        if(io[i] == stop) return i++,nullptr;
        
        TreeNode *t = new TreeNode(po[p++]);
        t->left = buildTree(po, io, t->val);
        t->right = buildTree(po, io, stop);
        return t;
    }
};