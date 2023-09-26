class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp = vector<int>(26,0);
        int n = s.size();
        int ans = 1;
        int maxChar = 1;
        char c = s[0];
        for(int r=0, l=0; r<n; r++){
            mp[s[r]-'A']++;
            if(mp[s[r]-'A'] > maxChar){
                maxChar = mp[s[r]-'A'];
                c = s[r];
            }
            while(l<r and r-l+1-maxChar > k){
                mp[s[l]-'A']--;
                maxChar--;
                l++;
                for(int i=0; i<26; i++){
                    if(mp[i] > maxChar){
                        maxChar = mp[i];
                        c = i+'A';
                    }
                }
            }
            //if(ans < r-l+1) cout<<l<<","<<r<<","<<maxChar<<","<<c<<": "<<s.substr(l,r-l+1)<<"\n";
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};