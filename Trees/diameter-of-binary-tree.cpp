class Solution {
  public:
    int maxH(Node* root, int &ans) {
        if(root){
            int l = maxH(root->left,ans);
            int r = maxH(root->right,ans);
            if(l+r+1 > ans) ans = l+r+1;
            return max(l,r)+1;
        }
        else return 0;
    }
    
    int diameter(Node* root) {
        int ans = 0;
        maxH(root,ans);
        return ans;
    }
};