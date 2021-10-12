class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    
    long long maxSubarraySum(int a[], int n){
        
        // Your code here
        long long max_so_far = INT_MIN, max_ending_here = 0;
        int i;
        for (i = 0; i < n; i++) {
            max_ending_here = max_ending_here + a[i];
            
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
              if (max_ending_here < 0)
                  max_ending_here = 0;
            //cout<<max_so_far<<"woo"; 
        }
        return max_so_far;
    }
};