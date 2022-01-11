class Solution {
public:
    long long ans =0;
    int sumRootToLeaf(TreeNode* root, int n = 0) {
        if(!root) return 0;
        n = n<<1 | root->val;
        if(!root->left and !root->right){
            ans += n;
            return ans;
        }
        sumRootToLeaf(root->left, n);
        sumRootToLeaf(root->right, n);
        return ans;
    }
};