class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        long long dp[s.size()+1];
        long long ans=s[0]-'0';
        int m = 1000000007;
        dp[0] = s[0]-'0';
        for(int i=1; i<s.size(); i++){
            dp[i] = (((s[i]-'0')*(i+1)) + 10*dp[i-1])%m;
            ans = (ans + dp[i])%m;
        }
        return ans;
    }
};