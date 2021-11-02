class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
        // your code here
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int i=0; i<n; i++){
            minH.push(arr[i]);
            if(minH.size()<k) cout<<-1<<" ";
            if(minH.size()>k){
                minH.pop();
            }
            if(minH.size()==k){
                cout<<minH.top()<<" ";
            }
        }
    }
};