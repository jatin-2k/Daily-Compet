class Solution {
public:
    string multiply(string num1, string num2) {
         vector<int>mul(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--)
        {
            for(int j=num2.size()-1;j>=0;j--)
            {
                mul[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                mul[i+j]+=mul[i+j+1]/10;
                mul[i+j+1]=mul[i+j+1]%10;
            }
        }
        int p=0;
        for(int i=0;i<mul.size();i++)
        {
            if(mul[i]==0)
            {
                p++;
            }
            else
            {
                break;
            }
        }
        string ans;
        while(p<mul.size())
        {
            ans+=(mul[p]+'0');
            p++;
        }
        if(num1=="0" or num2=="0")
            return "0";
        return ans;
    }
};