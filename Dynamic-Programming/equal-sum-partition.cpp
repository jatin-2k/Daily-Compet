class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        // code here
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
        }
        if(sum%2!=0) return 0;
        bool dp[sum+1];
        bool dplast[sum+1];
        memset(dp,0,sizeof(dp));
        memset(dplast,0,sizeof(dplast));
        int k=n-1;
        int i=sum-a[k];
        dp[sum]=1;dplast[sum]=1;
        for(; i>=0 and k>=0; i = i-a[--k]){
            for(int j=sum; j>i; j--){
                if(dplast[j]){
                    if(j-a[k]==sum/2)return 1;
                    dp[j-a[k]]=1;
                }
            }
            for(int j=0; j<=sum; j++) dplast[j] = dp[j];
        }
        // for(int i=0; i<=sum; i++){
        //     cout<<dp[i]<<" ";
        // }
        return 0;
    }
};