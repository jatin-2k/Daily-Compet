struct node{
    int pos;
    int dis;
    node(int p, int d){
        pos = p;
        dis = d;
    }
};

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        queue<node*> q;
        q.push(new node(n-1, 0));
        vector<int> ans(n,-1);
        ans[n-1] = 0;
        while(!q.empty()){
            node *cur = q.front(); q.pop();
            if(cur->pos - 1 >= 0 && ans[cur->pos - 1] == -1){
                ans[cur->pos - 1] = cur->dis + 1;
                q.push(new node(cur->pos-1, cur->dis+1));
            }
            if(cur->pos + 1 < n && ans[cur->pos + 1] == -1){
                ans[cur->pos + 1] = cur->dis + 1;
                q.push(new node(cur->pos+1, cur->dis+1));
            }
            for(auto &i: mp[arr[cur->pos]]){
                if(ans[i] == -1){
                    ans[i] = cur->dis + 1;
                    q.push(new node(i, cur->dis+1));
                }
            }
            mp[arr[cur->pos]].clear();
        }
        return ans[0];
    }
};
