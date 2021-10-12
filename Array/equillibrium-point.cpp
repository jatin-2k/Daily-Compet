class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        // Your code here
        int sum = 0;
        int leftsum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i];
     
        for (int i = 0; i < n; ++i)
        {
            sum -= arr[i];
     
            if (leftsum == sum)
                return i+1;
     
            leftsum += arr[i];
        }
        return -1;
    }

};