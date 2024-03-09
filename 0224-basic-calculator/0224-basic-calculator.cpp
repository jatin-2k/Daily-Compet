class Solution {
public:
    int calculate(string s) {
        long long int ans = 0, num=0, sign=1;
        int i = 0;
        stack<int> st;

        for(i = 0 ; i < s.size() ;i++){
            if(isdigit(s[i])){
                num = num*10 + s[i]-'0';
            }else if(s[i] == '+' || s[i] == '-'){
                ans = ans + sign*num;
                num = 0;
                sign = s[i] == '+' ? 1: -1;
            }else if(s[i] == '('){
                st.push(ans);
                st.push(sign);
                sign = 1;
                ans = 0;
            }else if(s[i] == ')'){
                
                int tmp_sign = st.top();
                st.pop();
                int tmp_ans =st.top();
                st.pop();
                ans = ans + sign*num;
                ans = tmp_ans + tmp_sign * ans;

                sign = 1;
                num=0;

            }
        }
        ans = ans + sign*num;
        
        return ans;
    }
};