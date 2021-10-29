class Solution
{
    public:
    map<int,int> m;
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>> q;
        vector<int> ans;
        q.push({root,0});
        while(!q.empty()){
            if(m[q.front().second]==0){
                m[q.front().second] = q.front().first ->data;
            }
            if(q.front().first -> left) q.push({q.front().first->left, q.front().second - 1});
            if(q.front().first -> right) q.push({q.front().first->right, q.front().second + 1});
            q.pop();
        }
        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
    }

};
