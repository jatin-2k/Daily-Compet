class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int i = 0;
        vector<string> ans;
        while(i+k < s.size()){
            ans.push_back(s.substr(i,k));
            i = i+k;
        }
        if(i >= s.size()) return ans;
        string ss = "";
        while(i<s.size()){
            ss = ss + s[i];
            i++;
        }
        while(ss.size() < k){
            ss = ss + fill;
        }
        ans.push_back(ss);
        return ans;
    }
};