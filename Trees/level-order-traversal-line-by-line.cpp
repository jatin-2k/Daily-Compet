class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<TreeNode*>temp;
            vector<int>level;
            
            //getting level out of queue
            while(!q.empty())
            {
                temp.push_back(q.front());
                q.pop();
            }
            // pushing level data in ans and inserting thre next level into the queue
            for(auto &i:temp)
            {
                level.push_back(i->val);
                if(i->left )
                q.push(i->left);
                if(i->right )
                q.push(i->right);
        
            }
            ans.push_back(level);
        }
            
            
        return ans;
    }
};