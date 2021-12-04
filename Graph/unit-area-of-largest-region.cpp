class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &res,int &ma)
   {
       if(i < 0 || j < 0 || i>=n || j>= m || grid[i][j] == 0)
           return;
       grid[i][j] = 0;
       res++;
       dfs(grid,i+1,j,n,m,res,ma);
       dfs(grid,i,j+1,n,m,res,ma);
       dfs(grid,i+1,j+1,n,m,res,ma);
       dfs(grid,i-1,j-1,n,m,res,ma);
       dfs(grid,i+1,j-1,n,m,res,ma);
       dfs(grid,i-1,j+1,n,m,res,ma);
       dfs(grid,i,j-1,n,m,res,ma);
       dfs(grid,i-1,j,n,m,res,ma);
       ma = max(ma,res);
   }
   
   int findMaxArea(vector<vector<int>>& grid) {
       // Code here
       int n = grid.size();
       int m = grid[0].size();
       int res = 0;
       int ma = 0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               res = 0;
               dfs(grid,i,j,n,m,res,ma);
           }
       }
       return ma;
   }
};