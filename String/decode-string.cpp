class Solution {
public:
    string solve(int n, string s){
        string ans;
        while(n--){
            ans = ans + s;
        }
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        int n=s.size();
        while(1){
            //end of string
            while(i<s.size() and s[i]!=']') i++;
            if(i>=s.size()) return s;
            int j=i;
            //start of string
            while(s[j]!='[') j--;
            int k=j;
            k--;
            while(k>=0 and isdigit(s[k])){
                k--;
            }
            if(k!=0) k++;
            int RepeatTimes= stoi(s.substr(k, j-k));
            string RepeatString = s.substr(j+1, i-j-1);
            s.replace(k,i-k+1, solve(RepeatTimes, RepeatString));
            i=0;
        }
        return s;
    }
};