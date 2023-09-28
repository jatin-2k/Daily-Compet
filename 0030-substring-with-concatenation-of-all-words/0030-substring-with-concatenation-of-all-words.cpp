class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        vector<int> ans = vector<int>();
        int n = s.size();
        int m = w[0].size();
        unordered_map<string, int> wf;
        
        for(auto x: w) wf[x]++;
        
        for(int i=0; i<m; i++){
            unordered_map<string, int> sf;
            
            for(int r=i,l=i; r+m<=n; r+=m){
                string rword = s.substr(r,m);
                bool inList = wf.find(rword)!=wf.end();
                if(inList){
                    sf[rword]++;
                }
                else{
                    l = r+m;
                    sf.clear();
                    continue;
                }
                while(l<r and (!inList || sf[rword] > wf[rword])){
                    string lword = s.substr(l,m);
                    if(sf.find(lword)!=sf.end()){
                        sf[lword]--;
                    }
                    l+=m;
                }
                //cout<<l<<","<<r<<endl;
                if(sf == wf and r-l+m == m*w.size()) ans.push_back(l);
            }
        }
        return ans;
    }
};