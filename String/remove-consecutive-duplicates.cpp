string clean(string s){
    stack<pair<char,int>> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty() || st.top().first!= s[i]){
            if(!st.empty() && st.top().second > 1){
                st.pop();
                i--;
                continue;
            }
            st.push({s[i],1});
        }
        else if(st.top().first==s[i]){
            st.top().second++;
        }
    }
    string ans = "";
    while(!st.empty()){
         if(st.top().second == 1){
             ans = st.top().first + ans;
         }
         st.pop();
    }
    return ans;
}