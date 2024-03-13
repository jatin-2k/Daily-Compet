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
    vector<double> ans, num;
    int h = 1;
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        if(h > ans.size()){
            ans.push_back(root->val);
            num.push_back(1);
        }
        else{
            ans[h-1] = (ans[h-1]*num[h-1] + root->val) / (num[h-1]+1);
            num[h-1]++;
        }
        h++;
        averageOfLevels(root->left);
        averageOfLevels(root->right);
        h--;
        return ans;
    }
};