class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ml = nums[0];
        for(int i=1; i<n; i++){
            if(i>ml) return false;
            ml = max(i+nums[i], ml);
        }
        return true;
    }
};