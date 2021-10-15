class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        int ans=0;
        sort(arr,arr+n);
        for(int i=n-1; i>=2; i--){
            int sum=arr[i];
            int x=0, y=i-1;
            while(x<y){
                if(arr[x]+arr[y] > arr[i]){
                    ans+=y-x;
                    y--;
                }
                else{
                    x++;
                }
            }
        }
        return ans;
    }
};