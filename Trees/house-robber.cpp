class Solution {
public:
    int rob(TreeNode* root) {
        int i=0,e=0;
        rob(root,i,e);
        return max(i,e);
    }
    
    void rob(TreeNode *root, int &inc, int &exc){
        if(!root) return;
        int li=0,le=0,ri=0,re=0;
        rob(root->left, li, le);
        rob(root->right, ri, re);
        inc = max(inc, root->val + le + re);
        exc = max(exc, max(li,le) + max(ri,re));
    }
};