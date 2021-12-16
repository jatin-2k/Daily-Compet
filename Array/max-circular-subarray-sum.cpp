class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int normalAns = kdane(nums,n);
        int total=0, count=0;
        for(auto &i: nums){
            total += i;
            if(i<0) count++;
            i *= -1;
        }
        //if all are neg. then total+kdane will give zero
        if(count == n) return normalAns;
        return max(normalAns, total + kdane(nums, n));
        
    }
    int kdane(vector<int>& nums, int n){
        int cur=0;
        int ans=nums[0];
        for(auto i: nums){
            cur+=i;
            ans= max(ans,cur);
            cur= max(cur,0);
        }
        return ans;
    }
};