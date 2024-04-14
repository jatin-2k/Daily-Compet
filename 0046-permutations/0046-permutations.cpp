class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        foo(st);
        return ans;
    }
    void foo(unordered_set<int>& st){
        if(st.empty()){
            ans.push_back(cur);
            return;
        }
        unordered_set<int> s1 = st;
        for(int n: s1){
            cur.push_back(n);
            st.erase(n);
            foo(st);
            st.insert(n);
            cur.pop_back();
        }
    }
};