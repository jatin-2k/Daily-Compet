class Solution {
public:
    int concatenatedBinary(int n) {
        string s = "";
        long long ans = 0, m = 1000000007;
        for(int i=1; i<=n; i++){
            string a = "";
            for(int j=i; j; j /= 2){
                a += (j & 1 == 1) ? '1' : '0';
            }
            reverse(a.begin(), a.end());
            s += a;
        }
        //cout<<s;
        for(int i=0; i<s.size(); i++){
            ans = (ans * 2 + (s[i] == '1'))%m;
        }
        return ans;
    }
};