class Solution
{
    public:
    map<int,vector<int>> m;
    
    vector<int> verticalOrder(Node *root)
    {
        queue<pair<Node*,int>> q;
        vector<int> ans;
        q.push({root,0});
        while(!q.empty()){
            m[q.front().second].push_back(q.front().first ->data);
            if(q.front().first -> left) q.push({q.front().first->left, q.front().second - 1});
            if(q.front().first -> right) q.push({q.front().first->right, q.front().second + 1});
            q.pop();
        }
        for(auto i: m){
            for(auto j: i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};