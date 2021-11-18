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
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=0; i<n; i++){
            for(int j=sum/2; j>=a[i]; j--){
                if(j >= a[i])
                    dp[j] = dp[j] || dp[j-a[i]];
            }
        }
        return dp[sum/2];
    }
};