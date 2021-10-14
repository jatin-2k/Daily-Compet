class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int arr[], int n) 
    { 
        //Your code here
        int l=0; int r=n-1;
        int cur=0; int max =0;
        while(l<r){
            cur = min(arr[l],arr[r])*(r-l-1);
            if(cur>max) max = cur;
            if(arr[l]<arr[r]) l++;
            else r--;
        }
        return max;
    } 
};