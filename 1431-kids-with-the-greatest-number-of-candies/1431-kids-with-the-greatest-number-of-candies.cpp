class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int t) {
        int mx = 0;
        int n = arr.size();
        vector<bool> ans(n, 0);
        for(int i=0; i<n; i++) mx = max(mx, arr[i]);
        for(int i=0; i<n; i++) ans[i] = arr[i] + t >= mx;
        return ans;
    }
};