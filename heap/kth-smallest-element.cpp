class Solution
{
    public:
    //Function to find the kth smallest element in the array.
    int kthSmallest(int arr[], int n, int k)
    {
        // Your code here
        priority_queue<int> maxH;
        for(int i=0; i<n; i++){
            maxH.push(arr[i]);
            if(maxH.size()>k) maxH.pop();
        }
        return maxH.top();
    }
};