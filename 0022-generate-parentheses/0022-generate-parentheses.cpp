class Solution {
public:
    vector<string> ans;
    string cur;
    vector<string> generateParenthesis(int n) {
        gen(n, 0);
        return ans;
    }
    
    void gen(int o, int c){
        if(o==0 && c ==0){
            ans.push_back(cur);
            return;
        }
        if(o){
            cur += '(';
            gen(o-1, c+1);
            cur.pop_back();
        }
        if(c){
            cur += ')';
            gen(o, c-1);
            cur.pop_back();
        }
    }
};