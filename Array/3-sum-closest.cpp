class Solution {
public:
    int threeSumClosest(vector<int>& nums, long long target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans= INT_MAX;
        for(int k=n-1; k>=2; k--){
            int i=0;
            int j=k-1;
            while(i<j){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target-ans) > abs(target-sum)) ans = sum;
                
                if(sum < target) i++;
                else j--;
            }
        }
        return ans;
    }
};