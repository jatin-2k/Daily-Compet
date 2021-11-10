class Solution
{
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
    int countWays(int n)
    {
        int m = 1000000007;
        int dp[n+1];
        for(int i=0; i<=n; i++){
            dp[i]=0;
        }
        dp[0]=1;
        for(int i=1; i<n; i++){
            for(int j=i; j<=n; j++){
                dp[j] = (dp[j]%m + dp[j-i]%m)%m;
            }
        }
        // your code here
        return dp[n]%m;
    }
};