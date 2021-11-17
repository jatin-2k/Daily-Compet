class Solution
{
    public:
    //Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int n)
    {
        long long maxi = *max_element(arr,arr+n);
        if(maxi<0) return maxi;
        vector<long long> dp(n,0);
        dp[0] = max(arr[0],0); 
        dp[1] = max({
                arr[1],arr[0],0
            });
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
        }
        return dp[n-1];
    }
};