class Solution
{
    public:
    int m = 1000000007;
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        int dp[n+1];
        for(int i=0; i<=n; i++){
            dp[i]=0;
        }
        dp[0]=1;
        return recur(n,dp);
    }
    int recur(int n, int dp[]){
        if(n<=1){
            return 1;
        }
        if(dp[n]) return dp[n];
        dp[n] = (recur(n-1,dp)%m + recur(n-2,dp)%m)%m;
        return dp[n]%m;
    }
};