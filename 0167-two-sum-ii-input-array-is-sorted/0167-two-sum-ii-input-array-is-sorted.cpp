class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int r = n-1, l= 0;
        while(l<r){
            if(nums[l]+nums[r] > target) r--;
            else if(nums[l]+nums[r] < target) l++;
            else return {l+1,r+1};
        }
        return {-1,-1};
    }
};