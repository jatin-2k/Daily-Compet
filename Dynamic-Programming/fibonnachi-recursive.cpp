class Solution
{
    public:
    
    long long dp[100] = {0};
    //Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int n)
    {
        // Your Code Here
        dp[1] = 1; dp[2]=1;
        return f(n);
    }
    
    long long f(int n){
        if(dp[n]>0) return dp[n];
        if(n<=2){
            dp[n]=1;
            return 1;
        }
        dp[n] = f(n-1) + f(n-2);
        return dp[n];
    }
};