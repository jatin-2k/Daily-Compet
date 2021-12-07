class Solution 
{
    public:
    int ans = 0;
    vector<vector<int>> t;
    int row;
    int col;
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid)
   {
       row = grid.size();
       col = grid[0].size();
       queue<pair<int,int>> q;
       t = vector<vector<int>>(row, vector<int>(col,0));
       for(int i=0; i<row; i++){
           for(int j=0; j<col; j++){
               if(grid[i][j]==2){
                   q.push({i,j});
                   t[i][j] = 0;
               }
           }
       }
       while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            //cout<<i<<" "<<j<<endl;
            if(check(i-1,j  ,grid,t[i][j])) q.push({i-1,j  });
            if(check(i  ,j-1,grid,t[i][j])) q.push({i  ,j-1});
            if(check(i+1,j  ,grid,t[i][j])) q.push({i+1,j  });
            if(check(i  ,j+1,grid,t[i][j])) q.push({i  ,j+1});
            q.pop();
       }
       for(int i=0; i<row; i++){
           for(int j=0; j<col; j++){
               if(grid[i][j]==1){
                   return -1;
               }
           }
       }
       return ans;
   }
   
   bool check(int i, int j, vector<vector<int>>& grid, int par){
       if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!=1) return false;
       else{
           grid[i][j] = 2;
           t[i][j] = par+1;
           ans = max(ans, par+1);
           return true;
       }
   }
   
};