class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=1, n=arr.size(), mx=arr[0];
        if(n<3) return false;
        for(; i<n && arr[i-1]<arr[i]; i++) mx = max(mx,arr[i]);
        for(; i<n && arr[i-1]>arr[i]; i++) mx = max(mx,arr[i]);
        if(i==n and mx!=arr[0] and mx!=arr[n-1]) return true;
        else return false;
    }
};