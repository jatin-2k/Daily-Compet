class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            int t = 0;
            while(t < ans.size() && t < strs[i].size() && strs[i][t] == ans[t]) t++;
            ans = ans.substr(0,t);
        }
        return ans;
    }
};