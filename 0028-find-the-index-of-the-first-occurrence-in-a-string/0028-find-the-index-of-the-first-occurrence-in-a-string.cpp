class Solution {
public:
    int strStr(string s, string t) {
        int n = s.size(), m = t.size();
        //if(n < m) return -1;
        for(int i=0; i+m<=n; i++){
            bool found = true;
            for(int j=0; i+j<n && j<m; j++){
                if(s[i+j] != t[j]){
                    found = false;
                    break;
                }
            }
            if(found) return i;
        }
        return -1;
    }
};