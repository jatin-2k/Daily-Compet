class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        int max=1, cur=0;
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i=0,j=0;
        while(i<n){
            if(arr[i]<=dep[j]){
                cur++;
                i++;
            }
            else{
                cur--;
                j++;
            }
            if(max<cur) max = cur;
        }
        return max;
    }
};