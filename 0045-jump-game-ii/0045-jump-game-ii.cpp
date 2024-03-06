class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n+1, INT_MAX);
        jumps[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<=i+nums[i] && j<n; j++){
                jumps[j] = min(jumps[j], jumps[i]+1);
            }
        }
        // for(int i=0; i<n; i++) cout<<jumps[i]<<", ";
        // cout<<endl;
        return jumps[n-1];
    }
};