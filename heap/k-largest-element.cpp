class Solution
{
    public:
    //Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<n; i++){
            q.push(arr[i]);
            if(q.size()>k) q.pop();
        }
        
        return q.top();
    }
};
Kth sm