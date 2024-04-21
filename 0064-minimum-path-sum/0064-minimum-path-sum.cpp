class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {-1,0,0,1};
        vector<int> dy = {0,-1,1,0};
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = grid[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<4; k++){
                    int x = dx[k]+i;
                    int y = dy[k]+j;
                    if(x>=0 && x<n && y>=0 && y<m){
                        dp[x][y] = min(dp[x][y], dp[i][j]+grid[x][y]);
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};
