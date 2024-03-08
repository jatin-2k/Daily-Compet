class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char,char> mp,tp;
        for(int i=0; i<n; i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] != t[i]) return false;
            if(tp.find(t[i]) != tp.end() && tp[t[i]] != s[i]) return false;
            mp[s[i]] = t[i];
            tp[t[i]] = s[i];
        }
        return true;
    }
};