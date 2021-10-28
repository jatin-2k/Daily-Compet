class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
    
    bool dfs(TreeNode* root, TreeNode* node, int& k) {
        // cout << "node->val: " << node->val << "\n";
        
        if (!(k - node->val == node->val)) {
            bool found = search(root, k - node->val);
            // cout << "found: " << found << "\n";
            if (found) return true;
        }
        
        if (node->left) {
            bool test = dfs(root, node->left, k);
            if (test) return true;
        }
        if (node->right) {
            bool test = dfs(root, node->right, k);
            if (test) return true;
        }
        
        return false;
    }
    
    bool search(TreeNode* node, int n) {
        
        if (!node) return false;
        // cout << "node->val - : " << node->val << "\n";
        if (n == node->val) return true;
        if (n < node->val) return search(node->left, n);
        if (n > node->val) return search(node->right, n);
        return false;
    }