class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        combinationSum(candidates, target, temp, 0);
        return ans;
    }
    void combinationSum(vector<int>& candidates, int target, vector<int> &cur, int id) {
        if(target == 0){ ans.push_back(cur); return; }
        if(target < 0 || id >= candidates.size()) return;
        combinationSum(candidates, target, cur, id+1);
        cur.push_back(candidates[id]);
        combinationSum(candidates, target - candidates[id], cur, id);
        cur.pop_back();
    }
};