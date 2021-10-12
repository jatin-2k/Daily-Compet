class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int l[n] = {0};
        int r[n] = {0};
        long long m=arr[0];
        for(int i=0; i<n; i++){
            if(arr[i] > m) m = arr[i];
            l[i]=m;
        }
        m = arr[n-1];
        for(int i=n-1; i>=0; i--){
            if(arr[i] > m) m = arr[i];
            r[i]=m;
        }
        m=0;
        for(int i=0; i<n; i++){
            m+= min(l[i],r[i]) - arr[i];
        }
        return m;
    }
};
// a 3 0 0 2 0 4

// l 3 3 3 3 3 4
// r 4 4 4 4 4 4

// water = min(l,r)-a