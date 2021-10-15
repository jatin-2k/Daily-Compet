class Solution{
  public:

    // arr[]: input array
    // n: size of array
    // x: element to find index
    int bin(int arr[],int l, int r, int x){
        if(l<=r){
            int mid=(l+r)/2;
            if(arr[mid] == x) return mid;
            if(arr[mid+1] == x) return mid+1;
            if(arr[mid-1] == x) return mid-1;
            
            if(arr[mid]>x) return bin(arr,l,mid-1,x);
            else return bin(arr,mid+1,r,x);
        }
        return -1;
    }
    
    //Function to find index of element x in the array if it is present.
    int closer(int arr[],int n, int x)
    {
        //Your code here
        return bin(arr,0, n-1,x);
    }
};