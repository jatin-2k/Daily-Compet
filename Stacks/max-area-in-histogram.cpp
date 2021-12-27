class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> l,r;
        long long max =0,cur = 0;
        l = ToLeft(arr,n);
        r = ToRight(arr,n);
        
        for(int i=0; i<n; i++){
            cur = arr[i]*(r[i]-l[i]-1);
            if(cur>max) max = cur;
        }
        return max;
    }
    
    vector<int> ToLeft(long long arr[], int n){
        stack<int> s;
        vector<int> ans(n);
        for(int i=0; i<n ; i++){
            long long cur = arr[i];
            while(!s.empty() && arr[s.top()] >= cur) s.pop();
            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        return ans;
    } 
    
    vector<int> ToRight(long long arr[], int n){
        stack<int> s;
        vector<int> ans(n);
        for(int i=n-1; ~i ; i--){
            long long cur = arr[i];
            while(!s.empty() && arr[s.top()] >= cur) s.pop();
            ans[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }
        return ans;
    } 
};