class Solution {
public:
    void recurse(TreeNode* root ,int level , vector<int> &res)
    {
        if(root)
        {
            if(res.size()==level)
                res.push_back(root->val);
            recurse(root->right,level+1,res);
            recurse(root->left,level+1,res);
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recurse(root,0,res);
        return res;
    }
};