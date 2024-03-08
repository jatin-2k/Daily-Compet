class Solution {
public:
    bool wordPattern(string p, string s) {
        istringstream iss(s);
        string w;
        unordered_map<char,string> mp;
        unordered_map<string,char> pp;
        for(auto c: p){
            iss>>w;
            if(mp.find(c) != mp.end() && mp[c] != w) return false;
            if(pp.find(w) != pp.end() && pp[w] != c) return false;
            mp[c] = w;
            pp[w] = c;
        }
        if(iss>>w) return false;
        return true;
    }
};