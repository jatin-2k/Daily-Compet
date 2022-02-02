class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        if(n<k) return {};
        vector<int> ans;
        vector<int> pmp(26,0),smp(26,0);
        for(int i=0; i<k; i++){
            smp[s[i]-'a']++;
            pmp[p[i]-'a']++;
        } 
        if(pmp == smp) ans = {0};
        for(int i=k; i<n; i++){
            smp[s[i-k]-'a']--;
            smp[  s[i]-'a']++;
            if(smp == pmp) ans.push_back(i-k+1);
        }
        return ans;
    }
};

