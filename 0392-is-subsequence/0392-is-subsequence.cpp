class Solution {
public:
    bool isSubsequence(string t, string s) {
        int n = s.size(), m = t.size();
        int idx = 0;
        if(m == 0) return true;
        if(m > n) return false;
        for(int i=0; i<n; i++){
            if(s[i]==t[idx]) idx++;
            if(idx == m) return true;
        }
        return false;
    }
};