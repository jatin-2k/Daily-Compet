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
    vector<int> ans;
    int h = 1;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        if(h > ans.size()) ans.push_back(root->val);
        h++;
        rightSideView(root->right);
        rightSideView(root->left);
        h--;
        return ans;
    }
};