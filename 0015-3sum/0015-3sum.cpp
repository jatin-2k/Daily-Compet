class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<n-2; i++){
            int l = i+1, r = n-1;
            while(l<r){
                if(nums[l] + nums[r] + nums[i] == 0){
                    st.insert({nums[i], nums[l], nums[r]});
                    r--; l++;
                }
                else if(nums[l] + nums[r] + nums[i] > 0) r--;
                else if(nums[l] + nums[r] + nums[i] < 0) l++;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};