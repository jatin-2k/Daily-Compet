class Solution
{
    public:
    int ceilIdx(int arr[], int l, int r, int x){
        while(r>l){
            int m = (r+l) / 2; 
            if(arr[m] >= x) 
                r = m;
            else 
                l = m+1;
        }
        return r;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
        int dp[n];
        int len = 1;
        dp[0] = a[0];
        for(int i=1; i<n; i++)
        {
            if(a[i] > dp[len-1])
            {
                dp[len] = a[i];
                len++;
            }
            else
            {
                int c = ceilIdx(dp,0,len-1,a[i]);
                dp[c] = a[i];
            }
        }
        return len;
    }
};