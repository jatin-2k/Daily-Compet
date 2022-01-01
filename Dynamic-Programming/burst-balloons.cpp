class Solution {
public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        int i = 1, j = n-1;
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        return solve(nums, i,j);
    }
    
    int solve(vector<int>& nums, int i, int j){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int k=i;k<j;k++){
            int temp = solve(nums, i,k) + solve(nums, k+1, j) + nums[i-1]*nums[k]*nums[j];
            if(temp > ans) ans = temp;
        }
        dp[i][j] = ans;
        return ans;
    }
};