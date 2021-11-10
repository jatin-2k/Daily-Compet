ll count(ll n) 
{
   //code here
    ll dp[n+1]={0};
    dp[0]=1;
    int a[3]={3,5,10};
    for(int i=0;i<3;i++)
    {
        for(int j=a[i];j<=n;j++)
        {
            dp[j]+=dp[j-a[i]];
        }
    }
    return dp[n];
}