class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int,int> mp;
        int curSum = 0;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            curSum += nums[i];
            if(mp.find(curSum - k) != mp.end()){
                ans += mp[curSum-k];
            }
            mp[curSum]++;
        }
        return ans;
    }
};