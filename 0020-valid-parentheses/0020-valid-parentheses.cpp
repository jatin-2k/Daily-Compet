class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            switch(s[i]){
                case(')'): if(!st.empty() && st.top() == '(' ) {st.pop(); break;} else return false;
                case('}'): if(!st.empty() && st.top() == '{' ) {st.pop(); break;} else return false;
                case(']'): if(!st.empty() && st.top() == '[' ) {st.pop(); break;} else return false;
            }
        }
        return st.empty();
    }
};