class Solution {
public:
    int numIslands(vector<vector<char>> grid) {
        int n = grid.size(); int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    calc(i,j,grid,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
    void calc(int i, int j, vector<vector<char>> &grid, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            calc(i-1,j,grid,n,m);
            calc(i,j-1,grid,n,m);
            calc(i+1,j,grid,n,m);
            calc(i,j+1,grid,n,m);
        }
    }
};