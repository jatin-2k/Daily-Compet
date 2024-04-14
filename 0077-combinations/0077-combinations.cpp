class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> combine(int n, int k) {
        foo(1, n, k);
        return ans;
    }

    void foo(int idx, int n, int k){
        if(idx == n+1){
            if(k == 0){
                ans.push_back(cur);
            }
            return;
        }
        cur.push_back(idx);
        foo(idx+1, n, k-1);
        cur.pop_back();
        foo(idx+1, n, k);
    }
};