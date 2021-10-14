long long int floorSqrt(long long int x) 
{
    // Your code goes here 
    long long int l = 0; long long int r = x;
    while(l<=r){
        long long int mid = (l+r)/2;
        if( (mid*mid)<=x && ((mid+1)*(mid+1))>x ) return mid;
        if((mid*mid)>x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}