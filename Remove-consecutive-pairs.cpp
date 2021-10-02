class Solution
{
    public:
    //Function to remove pair of duplicates from given string using Stack.
    string removePair(string str)
    {
        // Your code here
        stack<char> st;
        for(int i=0; i<str.size(); i++){
            if(!st.empty() && st.top()==str[i]){
                st.pop();
            }
            else{
                st.push(str[i]);
            }
        }
        string ans;
       while(!st.empty()){
           ans += st.top();
           st.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};