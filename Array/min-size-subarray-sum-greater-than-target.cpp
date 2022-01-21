class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int ans = INT_MAX;
        for(int p1=0, p2=0; p1<n; p1++){
            while(p2<n && cur < target){
                cur+=nums[p2];
                p2++;
            }
            if(cur >= target) ans = min(ans, p2-p1);
            cur-=nums[p1];
        }
        return (ans==INT_MAX)?0:ans;
    }
};