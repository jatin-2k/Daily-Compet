class Solution
{
    public:
    vector<int> dp;
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        dp = vector<int>(n+1,-1);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            if(i>=x){
                int cuts = dp[i-x];
                if(cuts != -1){
                    dp[i] = max(dp[i], cuts+1);
                }
            }
            if(i>=y){
                int cuts = dp[i-y];
                if(cuts != -1){
                    dp[i] = max(dp[i], cuts+1);
                }
            }
            if(i>=z){
                int cuts = dp[i-z];
                if(cuts != -1){
                    dp[i] = max(dp[i], cuts+1);
                }
            }
        }
        if(dp[n] == -1) return 0;
        return dp[n];
    }
    
};