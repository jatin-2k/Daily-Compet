int countOnes(int arr[], int n)
{
    //Your code here
    if(arr[n-1]==1) return n;
    if(arr[0]==0) return 0;
    int l=0; int r= n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==1 && arr[mid+1]==0) return mid+1;
        if(arr[mid]==1 && arr[mid+1]==1) l = mid+1;
        else r = mid-1;
    }
    return 0;
}