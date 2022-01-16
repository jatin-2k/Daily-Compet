class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> ans(n), mx(n+1);
        for(int i=n-1; ~i ; i--){
            ans[i] = q[i][0];
            if(i+q[i][1]+1 < n) ans[i] += mx[i+q[i][1]+1];
            mx[i] = max(ans[i], mx[i+1]);
        }
        // for(int i=0; i<n; i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        return mx[0];
    }
};