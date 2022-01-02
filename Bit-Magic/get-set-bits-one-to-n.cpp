class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int getSetBitsFromOneToN(int N){
        int two = 2,ans = 0;
        int n = N;
        while(n){
            ans += (N/two)*(two>>1);
            if((N&(two-1)) > (two>>1)-1) ans += (N&(two-1)) - (two>>1)+1;
            two <<= 1;
            n >>= 1;
        }
        return ans;
    }
    
    int countSetBits(int n)
    {
        // Your logic here
        return getSetBitsFromOneToN(n);
    }
};