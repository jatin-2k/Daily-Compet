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
    int x = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ans = kthSmallest(root->left, k);
        if(x < k){
            x++;
            ans = root->val;
        }
        if(x < k){
            ans = kthSmallest(root->right, k);
        }
        return ans;
    }
};