class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = -1, n = nums.size();
        for(int i=0;i<n; i++){
            if(nums[i] != val) swap(nums[i], nums[++k]);
        }
        return ++k;
    }
};