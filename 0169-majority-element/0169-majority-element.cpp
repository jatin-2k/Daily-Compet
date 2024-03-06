class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ele = nums[0];
        for(int i=0; i<n; i++){
            if(ele == nums[i]) cnt++;
            else {
                if(cnt == 1) ele = nums[i];
                else cnt--;
            }
        }
        return ele;
    }
};