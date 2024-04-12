class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1; int r = 0;
        bool has0 = 0;
        int ans = 0;
        for(; r<n; r++){
            if(nums[r] == 0){
                if(has0) while(nums[++l] != 0);
                else has0 = true;
            }
            // for(int i=l+1; i<=r; i++){
            //     cout<<nums[i]<<", ";
            // }
            //cout<<"has: "<<r-l-1<<endl;
            ans = max(ans, r-l-1);
        }
        return ans;
    }
};