bool search(struct Node* root, int x) {
    if(root){
        if(root->data == x) 
            return true;
        else if(root->data > x) 
            return search(root->left,x);
        else 
            return search(root->right,x);
    }
    return false;
}

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val == val) return root;
        if(root->val > val) return searchBST(root->left, val);
        if(root->val < val) return searchBST(root->right, val);
        return NULL;
    }
};