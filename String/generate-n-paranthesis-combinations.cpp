class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        vector<string> ans = generateParenthesis(n-1);
        set<string> gens;
        for(auto s: ans){
            for(int i=0; i<s.size(); i++){
                if(s[i]==')'){
                    string newString;
                    newString = s.substr(0,i) + "()" + s.substr(i,s.size()-i);
                    gens.insert(newString);
                    newString = s.substr(0,i+1) + "()" + s.substr(i+1, s.size()-i-1);
                    gens.insert(newString);
                }
            }
        }
        return vector<string>(gens.begin(), gens.end());
    }
};