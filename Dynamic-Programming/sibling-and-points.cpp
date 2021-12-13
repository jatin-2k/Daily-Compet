int sp(int arr[], int n, int m)
{
    int a[n+1],sum=0;
    for(int i=0;i<n;i++){
        a[i]=arr[i];
        sum+=arr[i];
    }
    a[n-1]=m;
    sum+=m;
    if(sum%2!=0)
    return 0;
    int dp[n+1][(sum/2)+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<(sum/2)+1;j++){
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<(sum/2)+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum/2];

}