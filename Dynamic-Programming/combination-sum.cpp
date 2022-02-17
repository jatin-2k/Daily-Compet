class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> dp[target+1];
        dp[0]={{}};
        for(int i=0; i<=target; i++){
            for(auto cur: candidates){
                if(i>=cur){
                    for(vector<int> v: dp[i-cur]){
                        v.push_back(cur);
                        sort(v.begin(), v.end());
                        dp[i].insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto v: dp[target]){
            vector<int> tmp;
            for(auto i: v){
                tmp.push_back(i);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};