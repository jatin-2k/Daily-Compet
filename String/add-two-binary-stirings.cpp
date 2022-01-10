class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int diga,digb;
        string ans="";
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            diga = 0; digb = 0;
            if( i>=0 )  diga = a[i--]=='1';
            if( j>=0 )  digb = b[j--]=='1';
            ans = static_cast<char>((diga ^ digb ^ carry) + '0') + ans;
            carry = (diga + digb + carry) > 1;
        }
        return ans;
    }
};