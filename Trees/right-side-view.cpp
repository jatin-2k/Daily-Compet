class Solution {
public:
    set<int> s;
    vector<int> v;
    vector<int> rightSideView(TreeNode* root, int depth = 0) {
        if(!root) return v;
        if(s.find(depth) == s.end()){
            s.insert(depth);
            v.push_back(root->val);
        }
        rightSideView(root->right, depth+1);
        rightSideView(root->left, depth+1);
        return v;
    }
};