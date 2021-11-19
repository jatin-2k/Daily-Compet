//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long maximumAmount(int arr[], int n){
        return sol(arr,n);
    }
    int sol(int arr[], int n)
    {
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;i++)
        {
            dp[i][i+1]= max(arr[i],arr[i+1]);
        }
    
        for(int gap =3; gap<n; gap = gap + 2)
        {
            for(int i=0; i+gap<n; i++)
            {
                int j = gap + i;
    
                dp[i][j] = max((arr[i] + min(dp[i+2][j], dp[i+1][j-1])),
                                    (arr[j] + min(dp[i+1][j-1], dp[i][j-2])));
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[0][n-1];
    }
};

//6
//9 1 6 4 10 5

// 0 9 0 15 0 25 
// 0 0 6 0 16 0 
// 0 0 0 6 0 16 
// 0 0 0 0 10 0 
// 0 0 0 0 0 10 
// 0 0 0 0 0 0  s