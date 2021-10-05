class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode* >q;
        q.push(root);

        bool isLtoR=true;
        while(!q.empty())
        {
            vector<TreeNode*>temp;
            vector<int>level;
            
            while(!q.empty())
            {
                temp.push_back(q.front());
                q.pop();
            }
            
            for(auto &i:temp)
            {
                level.push_back(i->val);
                if(i->left) q.push(i->left);
                if(i->right)q.push(i->right);
                
            }
             if(!isLtoR) reverse(level.begin(),level.end());
                
            ans.push_back(level);
            isLtoR=!isLtoR;
        }
        return ans;
    }
};