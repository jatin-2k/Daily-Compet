class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i=0; i<n; i++){
            if(i!=0) nums[i] += nums[i-1];
            
            if(mp.find(nums[i]-k)!=mp.end()){
                ans += mp[nums[i]-k];
            }
            
            mp[nums[i]]++;
        }
        return ans;
    }
};