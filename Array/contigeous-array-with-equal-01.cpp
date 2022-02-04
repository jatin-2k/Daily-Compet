class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0, ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            cnt += (nums[i])? 1: -1;
            auto it = mp.find(cnt);
            if(it == mp.end()){
                mp[cnt] = i;
            }
            else{
                ans = max(ans, i-it->second);
            }
        }
        return ans;
    }
};
