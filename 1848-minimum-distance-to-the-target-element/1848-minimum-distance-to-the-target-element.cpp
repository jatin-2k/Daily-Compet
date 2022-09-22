class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int l,r,n = nums.size();
        l = r = start;
        while(true){
            if(r<n and (start-l > r-start or l<0)){
                if(nums[r]==target) return r-start;
                r++;
            }
            else if(l>=0){
                if(nums[l]==target) return start-l;
                l--;
            }
            else break;
        }
        return -1;
    }
};