void mergeSort(vector<int> &arr, int start, int end){
    if(start<end){
        int mid = (start + end) / 2;
        mergeSort(arr,start, mid);
        mergeSort(arr,mid+1, end);
        merge(arr, start, mid, end);
    }
}

void merge(vector<int> &arr, int start, int mid, int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;
    vector<int> a1(len1);
    vector<int> a2(len2);
    for(int i=start, j=0; i<=mid; i++,j++) a1[j] = arr[i];
    for(int i=mid+1, j=0; i<=end; i++,j++) a2[j] = arr[i];
    int i1 = 0;
    int i2 = 0;
    int ia = start;
    while(i1 < len1 && i2 < len2){
        if(a1[i1] <= a2[i2])
            arr[ia++] = a1[i1++];
        else{
            arr[ia++] = a2[i2++];
        }
    }
    while(i1<len1) arr[ia++] = a1[i1++];
    while(i2<len2) arr[ia++] = a2[i2++];
}