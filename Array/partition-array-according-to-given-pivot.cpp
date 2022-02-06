class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), low=0, same=0, high=n;
        vector<int> res(n);
        for(int i=0; i<n; i++){
            if(nums[i] < pivot) same++;
            if(nums[i] > pivot) high--;
        }
        for(int i=0; i<n; i++){
            if(nums[i] < pivot) res[low++] = nums[i];
            if(nums[i] > pivot) res[high++] = nums[i];
            if(nums[i] == pivot) res[same++] = nums[i];
        }
        return res;
    }
};