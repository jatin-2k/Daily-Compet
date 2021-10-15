class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int x)
    {
        //Your Code Here
        sort(a,a+n);
        for(int i=n-1; i>=2; i--){
            int l=0,r=i-1;
            while(l<r){
                if(a[l]+a[r]+a[i] == x){
                    return true;
                }
                else if(a[l]+a[r]+a[i] > x){
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