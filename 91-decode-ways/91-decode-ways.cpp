class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            dp[i] = (s[i] == '0') ? 0 : dp[i+1];
            if(i+1 < n and (s[i] == '1' or (s[i]=='2' and s[i+1] >= '0' and s[i+1] <= '6'))){
                dp[i] = dp[i]+dp[i+2];
            }
        }
        return dp[0];
    }
};