class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> as1(26);
        vector<int> cur(26);
        for(auto &i: s1){
            as1[i-'a']++;
        }
        int i=0,j=0;
        for(; j<s1.size(); j++){
            cur[s2[j]-'a']++;
        }
        if(as1 == cur) return true;
        for(i=0; j<s2.size(); i++, j++){
            cur[s2[i]-'a']--;
            cur[s2[j]-'a']++;
            if(as1 == cur) return true;
        }
        return false;
    }
};