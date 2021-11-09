class Solution
{
    public:
    cpp_int dp[120] = {0};
    //O(n2)
    cpp_int findCatalan(int n) 
    {
        if(n<=1) return dp[n]=1,dp[n];
        if(dp[n]) return dp[n];
        for(int i=1; i<=n; i++){
            dp[n] = dp[n] + findCatalan(i-1)*findCatalan(n-i);
        }
        return dp[n];
    }
    //O(n)
    cpp_int findCatalan(int n) 
    {
        dp[0]=1;
        for(int i=1; i<=n; i++){
            dp[i] = (((2*i)*(2*i-1)*dp[i-1])/(i*(i+1)));
        }
        return dp[n];
    }
    
};