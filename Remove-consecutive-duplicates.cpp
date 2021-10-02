class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        // Your code here
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
            }
        }
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};