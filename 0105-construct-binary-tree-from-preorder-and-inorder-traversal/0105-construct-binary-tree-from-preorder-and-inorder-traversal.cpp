/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int &Postindex,int inI,int inJ,vector<int>&inorder, vector<int>&postorder)
    {
        if(Postindex>=postorder.size() || inI>inJ) // if the postorder index i.e(Postindex) is negative or the inI and inJ have collided 
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[Postindex++]);
        int i;
        for( i=inI;i<=inJ;i++)
        {
            if(inorder[i]==root->val)
            {
                break;
            }
        }
        
        root->left=solve(Postindex,inI,i-1,inorder,postorder);
        root->right=solve(Postindex,i+1,inJ,inorder,postorder); 
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& po, vector<int>& io) {
        int idx = 0;
        return solve(idx,0,io.size()-1,io,po);
    }
};