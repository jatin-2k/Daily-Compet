class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n==0) return ans;
        int prev = nums[0];
        int idx = 0;
        for(int i=1; i<=n; i++){
            if(i<n && nums[i] == prev+1){
                
            }
            else if(idx == i-1){
                
                ans.push_back(to_string(nums[idx]));
                idx = i;
            }
            else{
                //string s = "" + nums[idx] + "->" + nums[i-1];
                //cout<<s<<endl;
                ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[i-1]));
                idx = i;
            }
            
            if(i<n) prev = nums[i];
        }
        return ans;
    }
};