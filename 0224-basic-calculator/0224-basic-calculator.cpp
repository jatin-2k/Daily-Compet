class Solution {
public:
    int calculate(string s,int start = 0) {
       function<int(int&)> helper = [&](int& i)-> int{
           long res = 0,num = 0,sign = 1;
           while(i<s.size() and s[i] != ')'){
               if(isdigit(s[i]))num  = num*10 + s[i] - '0';
                else{
                     res+= num*sign, num = 0;
                     if(s[i] == '(')res = res + sign*helper(++i);
                     else if(!isspace(s[i])) sign = s[i] == '+'?1:-1;
                   }
                  ++i;
                }
            return res + sign*num;
        };
        return helper(start);
    }
};