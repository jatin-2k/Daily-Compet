class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    
    int maxSumSubarray(int a[], int n)
    {
        int ans = *max_element(a,a+n);
        if(ans<0) return ans;
        int fw[n+1], bw[n+1];
        int maxi = INT_MIN;
        int cur = 0;
        for(int i=0; i<n; i++){
            cur+=a[i];
            fw[i]=cur;
            if(cur<0) {
                cur=0;
            }
            if(maxi<cur){ 
                maxi = cur;
            }
        }
        cur=0;
        maxi = INT_MIN;
        for(int i=n-1; ~i; i--){
            cur=max(cur+a[i],a[i]);
            maxi=max(maxi, cur);
            bw[i]=cur;
        }
        
        //not re initializing maxi cause it will contain answer 
        for(int i=1; i<n-1; i++){
            maxi = max(maxi, fw[i-1]+bw[i+1]);
        }
        
        return maxi;
    }
    
};