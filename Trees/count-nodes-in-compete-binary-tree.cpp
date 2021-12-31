class Solution {
public:
    int heightR(TreeNode* root){
        if(!root) return 0;
        return 1 + heightR(root->right);
    }
    int heightL(TreeNode* root){
        if(!root) return 0;
        return 1 + heightL(root->left);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hr = heightR(root->right);
        int hl = heightL(root->left);
        cout<<root->val<<" "<<hl<<" "<<hr<<" ";
        if(hr == hl){
            cout<<(1<<(hl+1))-1<<endl;
            return (1<<(hl+1))-1;
        }
        else{
            cout<<endl;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};