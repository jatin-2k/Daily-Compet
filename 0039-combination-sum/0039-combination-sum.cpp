class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        int n = arr.size();
        combinationSum(arr, t, 0);
        return ans;
    }
    
    void combinationSum(vector<int>& c, int t, int idx){
        if(t==0){ ans.push_back(cur); return; }
        if(t < 0 || idx >= c.size()){ return; }
        combinationSum(c, t, idx+1);
        cur.push_back(c[idx]);
        combinationSum(c, t-c[idx], idx);
        cur.pop_back();
    }
};