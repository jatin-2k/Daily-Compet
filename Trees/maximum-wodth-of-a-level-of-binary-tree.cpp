class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts; // left most nodes at each level;
        return dfs(root, 1, 0, lefts);
    }
private:
    unsigned int dfs(TreeNode* n, unsigned int id, unsigned int d, vector<int>& lefts) { // d : depth
        if (!n) return 0;
        if (d >= lefts.size()) lefts.push_back(id);  // add left most node
        return max({id + 1 - lefts[d], dfs(n->left, id * 2, d + 1, lefts), dfs(n->right, id * 2 + 1, d + 1, lefts)});
    }
};