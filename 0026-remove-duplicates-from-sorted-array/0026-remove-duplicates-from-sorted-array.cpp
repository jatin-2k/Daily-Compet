class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = -1, n = nums.size();
        for(int i=0;i<n; i++){
            if(k==-1 || nums[i] != nums[k]) swap(nums[i], nums[++k]);
        }
        return ++k;
    }
};