class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
    
        // Your code here
        int down[maxx+1]={0};
        int up[maxx+1]={0};
        for(int i=0; i<n; i++){
            up[L[i]]++;
            down[R[i]]--;
        }
        int max = 0;
        int ele = -1;
        for(int i=0,k=0; i<maxx+1; i++){
            k = k+up[i];
            if(k>max){
                max = k;
                ele = i;
            }
            k = k+down[i];
        }
        return ele;
    }
};