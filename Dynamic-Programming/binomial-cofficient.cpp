class Solution
{
    public:
    const int p = 1e9+7;
    
    //Function to return nCr mod 10^9+7 for given n and r.
    int nCrModp(int n, int r) 
    { 
        int C[r+1];
        memset(C, 0, sizeof(C));
        C[0] = 1; 
        for (int i = 1; i <= n; i++) 
        { 
        for (int j = min(i, r); j > 0; j--)
          C[j] = (C[j]%p + C[j-1]%p)%p; 
        } 
        return C[r]; 
    }
};