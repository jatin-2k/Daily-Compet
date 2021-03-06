class Solution
{
    public:
    // Function for finding maximum AND value.
    int checkBit(int pattern, int arr[], int n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
            if ((pattern & arr[i]) == pattern)
                count++;
        return count;
    }
    
    int maxAND (int arr[], int N)
    {
        // Your code here
        int res = 0, count, n=N;
        for (int bit = 31; bit >= 0; bit--)
        {
            count = checkBit(res | (1 << bit),arr,n);
            if ( count >= 2 )       
                res |= (1 << bit);       
        }
     
        return res;
    }
};