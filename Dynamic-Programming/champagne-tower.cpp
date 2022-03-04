
class Solution {
public:
    double champagneTower(int poured, int x, int y) {
        vector<vector<double>> dp(100,vector<double>(100));
        dp[0][0] = poured;
        for(int i=0; i<99; i++){
            for(int j=0; j<=i; j++){
                if(dp[i][j] > 1){
                    dp[i+1][j+0] += (dp[i][j]-1.0)/2.0;
                    dp[i+1][j+1] += (dp[i][j]-1.0)/2.0;
                }
            }
        }
        return min(1.0,dp[x][y]);
    }
};