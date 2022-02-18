class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(auto c: num){
            while(ans.length() and ans.back() > c and k) ans.pop_back(), k--;
            if(ans.length() || c!='0') ans.push_back(c);
        }
        while(!ans.empty() and k--) ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};