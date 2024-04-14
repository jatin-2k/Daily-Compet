class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        int n = arr.size();
        foo(arr, t, 0);
        return ans;
    }
    
    void foo(vector<int>& arr, int t, int idx){
        if(0 > t) return;
        if(0 == t){
            ans.push_back(cur);
            return;
        }
        for(int i=idx; i<arr.size(); i++){
            int x = arr[i];
            cur.push_back(x);
            foo(arr, t - x, i);
            cur.pop_back();
        }
    }
};