#include<iostream>
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++) nums[i] = nums[i]+nums[i-1];
        int lsum=0, rsum=nums[n-1];
        for(int i=0; i<n; i++){
            rsum = nums[n-1] - nums[i];
            if(lsum == rsum) return i;
            lsum = nums[i];
        }
        return -1;
    }
};