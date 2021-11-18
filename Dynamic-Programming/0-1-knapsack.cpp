int Solution::solve(vector<int> &val, vector<int> &w, int s) {
    int n=val.size(),dp[s+1]={};
    for(int i=0;i<n;i++)
        for(int j=s;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
    return dp[s];
}