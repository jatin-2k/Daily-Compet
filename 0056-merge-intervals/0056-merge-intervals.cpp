class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(auto v: arr){
            if(v[0] <= ans.back()[1]){
                //cout<<v[0]<<" "<<ans.back()[1]<<endl;
                ans.back()[1] = max(ans.back()[1], v[1]);
            }
            else{
                ans.push_back(v);
            }
        }
        return ans;
    }
};