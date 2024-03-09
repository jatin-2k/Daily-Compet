class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& p) {
        if(arr.empty()) return {p};
        vector<vector<int>> ans;
        if(p[0] < arr[0][0]){
            ans.push_back(p);
        }
        else ans.push_back(arr[0]);
        
        for(auto &v: arr){
            if(v[1] >= p[0] && v[0] <= p[1]){
                v[1] = max(v[1], p[1]);
                v[0] = min(v[0], p[0]);
            }
            
            if(p[0] > ans.back()[1] && p[1] < v[0]) ans.push_back(p);
            
            if(v[0] <= ans.back()[1]){
                ans.back()[1] = max(v[1], ans.back()[1]);
            }
            else ans.push_back(v);
        }
        if(ans.back()[1] < p[0]) ans.push_back(p);
        return ans;
    }
};