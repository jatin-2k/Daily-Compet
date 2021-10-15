class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n);
        int ans=0;
        for(int i=n-1; i>=2; i-- ){
            int sum = arr[i];
            int l=0, r=i-1;
            while(l<r){
                if(arr[l]+arr[r]+sum == 0){
                    return true;
                    l++; r--;
                }
                else if(arr[l]+arr[r]+sum > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }
};