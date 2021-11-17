int ceilIdx(int arr[], int l, int r, int x){
    while(r>l){
        int m = (l+r)/2;
        if(arr[m] >= x) r = m;
        else l = m+1;
    }
    return r;
}