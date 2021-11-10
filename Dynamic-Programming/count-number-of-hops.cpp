class Solution
{
    public:
    long long m = 1000000007;
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        vector<long long> dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        return recur(n, dp);
    }
    long long recur(int n, vector<long long> &dp){
        if(dp[n]) return dp[n];
        dp[n] = (recur(n-1, dp) + recur(n-2, dp) + recur(n-3,dp))%m;
        return dp[n];
    }
};