class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int n)
    {
        // your code here
        int m = 1000000007;
        int dp[n+1];
        for(int i=0; i<=n; i++){
            dp[i]=0;
        }
        dp[0]=1;
        for(int i=1; i<=2; i++){
            for(int j=i; j<=n; j++){
                dp[j] = (dp[j]%m + dp[j-i]%m)%m;
            }
        }
        return dp[n]%m;
    }
};