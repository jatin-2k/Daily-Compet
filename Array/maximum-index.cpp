class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        int l[n] = {0};
        int r[n] = {0};
        int m=a[0],max = -1;
        for(int i=0; i<n; i++){
            if(a[i]<m) m = a[i];
            l[i] = m;
        }
        m = a[n-1];
        for(int i=n-1; i>=0; i--){
            if(a[i]>m) m = a[i];
            r[i] = m;
        }
        int i=0,j=0;
        while(i<n and j<n){
            if(l[i]<=r[j]) j++;
            else i++;
            if(j-i > max) max = j-i;
        }
        return max-1;
    }
};

// 34 08 10 03 02 80 30 33 01

// 34 08 08 03 02 02 02 02 01
// 80 80 80 80 80 80 33 33 01

// 05 06 05 04 03 02 01 00 00