class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        map<char,int> map;
            map['+']=1;
            map['-']=1;
            map['*']=2;
            map['/']=2;
            map['^']=3;
        stack<char> temp;
        string ans;
        for(int i=0; i<s.size(); i++){
            if('a'<= s[i] && s[i] <= 'z'){
                ans+=s[i];
            }
            else{
                if(temp.empty() || s[i]=='('){
                    temp.push(s[i]);
                }
                else if(s[i] == ')'){
                    while(temp.top()!='('){
                        ans+=temp.top();
                        temp.pop();
                    }
                    if(temp.top()=='(') temp.pop();
                }
                else if(map[s[i]]<=map[temp.top()]){
                    while( !temp.empty() &&
                            temp.top()!='(' && 
                            map[s[i]]<=map[temp.top()]){
                        ans+=temp.top();
                        temp.pop();
                    }
                    temp.push(s[i]);
                }
                else{
                    temp.push(s[i]);
                }
            }
        }
        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }
        return ans;
    }
};