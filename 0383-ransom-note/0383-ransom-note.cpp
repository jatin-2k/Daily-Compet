class Solution {
public:
    bool canConstruct(string s1, string s2) {
        unordered_map<char,int> mp;
        for(auto c: s1) mp[c]++;
        for(auto c: s2) mp[c]--;
        for(auto p: mp) if(p.second > 0) return false;
        return true;
    }
};