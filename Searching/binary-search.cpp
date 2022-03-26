int bin(int arr[], int l, int r, int k){
    if(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==k) return 1;
        if(arr[mid]<k) return bin(arr,mid+1,r,k);
        if(arr[mid]>k) return bin(arr,l,mid-1,k);
        return -1;
    }
    return -1;
}

int searchInSorted(int arr[], int n, int k) 
{ 
    // store left index in l with 0 and right in r with n-1
    int l = 0, r = n-1;
    // calculate mid
    int m = l + (r-l) / 2;

    // binary search to find the element in sorted array
    while (l <= r) { 
        // calculate mid on each iteration
        m = l + (r - l) / 2; 

        // Check if x is present at mid 
        if (arr[m] == k) 
            return 1; 

        // If x greater, ignore left half 
        if (arr[m] < k) 
            l = m + 1; 

        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
    
    // if we reach here, then element was not present 
    return -1; 
} 
