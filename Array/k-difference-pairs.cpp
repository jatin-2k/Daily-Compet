class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0, j=1; j<n ; j++){
            while(i<j and nums[j]-nums[i] > k) i++;
            if(i<j and nums[j]-nums[i] == k){
                ans++;
                while(i+1<n and nums[i]==nums[i+1]) i++;
                i++;
            }
        }
        return ans;
    }
};