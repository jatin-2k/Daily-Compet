class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> sf = vector<int>(500,0);
        vector<int> tf = vector<int>(500,0);
        int n = s.size();
        int ans = n+1;
        int idx = 0;
        unordered_set<char> st,tt;
        
        for(int i=0; i<t.size(); i++){
            tf[t[i]]++;
            tt.insert(t[i]);
        }
        
        for(int r=0,l=0; r<n; r++){
            sf[s[r]]++;
            while(l<r and sf[s[l]] > tf[s[l]]){
                sf[s[l]]--;
                l++;
            }
            if(sf[s[r]] == tf[s[r]]) st.insert(s[r]);
            
            // cout<<l<<","<<r<<","<<st.size()<<", "<<s.substr(l,r-l+1)<<endl;
            // cout<<"sf {";
            // for(int i=0; i<500; i++) if(sf[i]) cout<<(char)i<<":"<<sf[i]<<", ";
            // cout<<"}\n";
            // cout<<"tf {";
            // for(int i=0; i<500; i++) if(tf[i]) cout<<(char)i<<":"<<tf[i]<<", ";
            // cout<<"}\n";
            if(st.size() == tt.size() and ans > r-l+1){
                ans = r-l+1;
                idx = l;
            }
        }
        if(ans > n) return "";
        return s.substr(idx,ans);
    }
};