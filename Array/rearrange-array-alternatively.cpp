class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
        long long a=0, b=n-1;
        long long max=arr[n-1] + 1;
        for(int i=0; i<n; i++){
            //even
            if(i%2==0){
                arr[i]= (max*((arr[b]>max)?arr[b]%max:arr[b]))+arr[i];
                b--;
            }
            //odd
            else{
                arr[i]= (max*(arr[a]%max)+arr[i]);
                a++;
            }
        }
        for(int i=0; i<n; i++){
            arr[i]= arr[i]/max;
        }
    }
};