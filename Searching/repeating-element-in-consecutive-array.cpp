class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int,int> binary(int *arr, int l, int r, int n){
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]>=(arr[0]+mid)) l=mid+1;
            else r = mid;
        }
        return {arr[l],n-(arr[n-1]-arr[0])};
    }
    pair<int, int> findRepeating(int *arr, int n){
        //code here
        if(arr[n-1]-arr[0]-n == -1) return {-1,-1};
        return binary(arr,0,n-1,n);
    }
};