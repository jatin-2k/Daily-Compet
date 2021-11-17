class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        if(n<2) return 0;
        if(!arr[0]) return -1;
        int range = arr[0];
        int steps = arr[0];
        int jumps = 1;
        for(int i=1; i<n-1; i++){
            range = max(range, arr[i]+i);
            steps--;
            if(!steps){
                jumps++;
                steps = range - i;
            }
            if(i>=range) return -1;
        }
        return jumps;
    }
};