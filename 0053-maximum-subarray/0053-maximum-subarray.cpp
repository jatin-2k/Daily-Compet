class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            cur += nums[i];
            mx = max(mx, cur);
            cur = max(cur, 0);
        }
        return mx;
    }
};