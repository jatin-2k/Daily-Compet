class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode *n1,*n2;
        n1 = root -> left;
        n2 = root -> right;
        return check(n1, n2);
    }
    
    bool check(TreeNode* n1, TreeNode* n2){
        if(!n1 && !n2) return true;
        if(n1 && n2 && n1->val == n2->val){
            return check(n1->left,n2->right) && check(n1->right,n2->left);
        }
        else return false;
    }
    
};