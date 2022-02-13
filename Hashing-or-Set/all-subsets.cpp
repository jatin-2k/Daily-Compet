class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        sol(nums, n);
        return ans;
    }
    void sol(vector<int>& nums, int &n, vector<int> cur = {}, int index = 0) {
        if(index >= n){
            ans.push_back(cur);
            return;
        }
        sol(nums, n, cur, index+1);
        cur.push_back(nums[index]);
        sol(nums, n, cur, index+1);
        
    }
};