class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<int> s;
        vector<long long> ans(n);
        for(int i=n-1; ~i ; i--){
            long long cur = arr[i];
            while(!s.empty() && arr[s.top()] <= cur) s.pop();
            ans[i] = (s.empty()) ? -1 : arr[s.top()];
            s.push(i);
        }
        return ans;
    }
};