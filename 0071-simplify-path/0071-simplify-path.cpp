class Solution {
public:
    string simplifyPath(string s) {
        for(auto &c: s) c = c=='/' ? ' ' : c;
        istringstream iss(s);
        stack<string> st;
        while(iss>>s){
            if(s=="."){}
            else if(s==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(s);
        }
        s = "";
        while(!st.empty()){
            s = "/" + st.top() + s;
            st.pop();
        }
        return s.empty() ? "/" : s;
    }
};