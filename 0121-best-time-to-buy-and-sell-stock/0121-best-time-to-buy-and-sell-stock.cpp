class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mx= INT_MIN, ml = INT_MAX, ans = 0;
        for(int i=0; i<n; i++){
            if(mx < arr[i]) mx = arr[i];
            if(ml > arr[i]) ml = mx = arr[i];
            ans = max(mx-ml, ans);
        }
        return ans;
    }
};