class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[x+1][y+1];
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                dp[i][j]=0;
            }
        }
        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j]=dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
};

//   - A B C D G H
// - 0 0 0 0 0 0 0
// A 0 1 1 1 1 1 1 
// E 0 1 1 1 1 1 1
// D 0 1 1 1 2 2 2
// F 0 1 1 1 2 2 2
// H 0 1 1 1 2 2 3
// R 0 1 1 1 2 2 3