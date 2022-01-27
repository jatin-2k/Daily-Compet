class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i!=0 and (nums[i-1]+1==nums[i] or nums[i-1]==nums[i])){
                
            }
            else if(i!=n-1 and (nums[i]==nums[i+1]-1 or nums[i]==nums[i+1])){
                
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};