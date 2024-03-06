class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, k = 0, ele = nums[0];
        for(int i=0; i<n; i++){
            if(ele != nums[i]){
                cnt = 1; ele = nums[i];
            }
            else cnt++;
            if(cnt <= 2) swap(nums[i], nums[k++]);
        }
        return k;
    }
};