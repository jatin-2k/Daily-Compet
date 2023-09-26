class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pf = vector<int>(26,0);
        vector<int> sf = vector<int>(26,0);
        vector<int> ans = vector<int>();
        int n = s.size();
        
        for(int i=0; i<p.size(); i++){
            pf[p[i]-'a']++;
        }
        
        for(int r=0,l=0; r<n; r++){
            sf[s[r]-'a']++;
            while(sf[s[r]-'a'] > pf[s[r]-'a']){
                sf[s[l]-'a']--;
                l++;
            }
            // cout<<l<<", "<<"sf: {";
            // for(int i=0; i<26; i++) if(sf[i]) cout<<(char)(i+'a')<<":"<<sf[i]<<",";
            // cout<<"}\n";
            // cout<<r<<", "<<"pf: {";
            // for(int i=0; i<26; i++) if(pf[i])cout<<(char)(i+'a')<<":"<<pf[i]<<",";
            // cout<<"}\n";
            if(sf == pf) ans.push_back(l);
        }
        return ans;
    }
};