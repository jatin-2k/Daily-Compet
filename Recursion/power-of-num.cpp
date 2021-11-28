class Solution{
    public:
    //You need to complete this fucntion
    int po(long long x, unsigned int y, int p)
    {
        int res = 1;     // Initialize result
     
        x = x % p; // Update x if it is more than or
                    // equal to p
      
        if (x == 0) return 0; // In case x is divisible by p;
     
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;
     
            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
    long long power(int N,int R)
    {
       //Your code here
       po(N,R,mod);
    }

};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}
