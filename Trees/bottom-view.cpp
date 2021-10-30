class Solution {
  public:
  map<int,Node*> m;
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>> q;
        q.push({root,0});
        vector<int> ans;
        while(!q.empty()){
            Node * t = q.front().first;
            int d = q.front().second;
            m[d] = t;
            if(t->left) q.push({t->left, d-1});
            if(t->right) q.push({t->right, d+1});
            q.pop();
        }
        for(auto i: m){
            ans.push_back(i.second -> data);
        }
        return ans;
    }
};