int fun(int n, int a[])
{
    int ans = 1;
    int dp[n];
    dp[0] = 1;
    
    sort(a, a + n);
    for (int i = 1; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[i] % a[j] == 0){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
 
        ans = max(ans, dp[i]);
    }
    if(ans == 1) return -1;
    return ans;
}